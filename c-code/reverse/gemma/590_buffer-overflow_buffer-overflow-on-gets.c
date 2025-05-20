#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char input;

  while ((input = getchar()) != '\0') {
    switch (input) {
      case 'a':
        printf("b");
        break;
      case 'b':
        printf("c");
        break;
      case 'c':
        printf("d");
        break;
      // Add remaining cases...
      default:
        printf("Invalid input");
    }
  }

  return 0;
}
