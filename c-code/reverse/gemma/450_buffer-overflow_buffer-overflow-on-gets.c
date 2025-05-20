#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char text[1024];
  gets(text);

  char *word = strtok(text, " ");
  while (word) {
    switch (rand() % 3) {
      case 0:
        word = strcat(word, "tron");
        break;
      case 1:
        word = strcat(word, "flux");
        break;
      case 2:
        word = strcat(word, "quantum");
        break;
    }
    printf("%s SPACE", word);
    word = strtok(NULL, " ");
  }
  printf("\n");
  return 0;
}
