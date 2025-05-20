#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  gets(input);

  for (int i = 0; input[i] != '\0'; i++) {
    char output[2];
    switch (input[i]) {
      case 'a':
        output[0] = 'A';
        output[1] = 'A';
        break;
      case 'b':
        output[0] = 'B';
        output[1] = 'B';
        break;
      case 'c':
        output[0] = 'C';
        output[1] = 'C';
        break;
      default:
        printf("Error: Unknown character.\n");
        return 1;
    }
    printf("%c%c ", output[0], output[1]);
  }

  printf("\n");

  return 0;
}
