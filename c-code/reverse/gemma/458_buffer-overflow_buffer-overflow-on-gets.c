#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char input[1024], output[1024];
  int i, j, k, r;

  gets(input);

  for (i = 0; input[i] != '\0'; i++) {
    switch (input[i]) {
      case 'a':
      case 'A':
        r = rand() % 10;
        output[i] = 'a' + r;
        break;
      case 'e':
      case 'E':
        r = rand() % 10;
        output[i] = 'e' + r;
        break;
      default:
        output[i] = input[i] + rand() % 2;
    }

    if (input[i] == ' ') {
      output[i] = 'SPACE';
    }
  }

  output[i] = '\0';

  printf("%s", output);

  return 0;
}
