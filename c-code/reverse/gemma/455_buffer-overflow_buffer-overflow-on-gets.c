#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char text[1000];
  printf("Enter text: ");
  fgets(text, 1000, stdin);

  char *ptext = text;
  char *qtext = text;

  while (*ptext) {
    if (*ptext == ' ') {
      *ptext = 'SPACE';
    } else {
      int r = rand() % 5;
      switch (r) {
        case 0:
          *ptext = 'ᚏ';
          break;
        case 1:
          *ptext = '⏭';
          break;
        case 2:
          *ptext = '⏭';
          break;
        case 3:
          *ptext = 'ᚏ';
          break;
        case 4:
          *ptext = '⏭';
          break;
      }
    }
    ptext++;
  }

  printf("Modified text: %s", qtext);

  return 0;
}
