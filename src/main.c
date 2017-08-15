/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>
#include <string.h>

int main() {

  char c, ant = '/0';
  int contador = 0;

  c = 1;

  scanf("%c", &c);
  if (c != ' ' && c != '.' && c != ',' && c != '!'){ //Verifica se o primeiro termo não é um separador, e, caso não seja, já incrementamos a existência de uma palavra
    contador++;
  }
  while (c != '\n') {
    scanf("%c", &c);
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){ //Verifica se se trata de um número
      scanf("%c", &c);
      while (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
        scanf("%c", &c);
      }
      if (c == ' '){ //Conta o início de outra palavra caso haja uma separação por espaço
        contador++;
      }
      if (c == '.' || c == ','){ //Garante que não se inicie a contagem de outra palavra nas casas decimais de um número
        scanf("%c", &c);
        while (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
          scanf("%c", &c);
          if (c == ' ' || c == ','){
            contador--;
          }
        }
      }
    }else{
      if (c == ' ' || c == '.' || c == ',' || c == '!' || c == '-'){ //Verifica se há separadores de letras
        contador++;
        while (c == ' ' || c == '.' || c == ',' || c == '!' || c == '-'){ //Enquanto não aparecer uma letra ou número, segue escaneando
          scanf("%c", &c);
          if (c == '\n'){ //Caso o separador seja o último caractere da frase, decrementamos o contador, pois não virá uma palavra após ele, como antes previsto
            contador--;
          }
        }
      }
    }
  }

  printf("%d\n", contador);
  return 0;

}
