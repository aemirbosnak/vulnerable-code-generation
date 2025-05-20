#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int number;
  char unit;

  scanf(" %d %c ", &number, &unit);

  switch (unit) {
    case 'm':
      switch (number) {
        case 1:
          printf("The conversion is: %d meters\n", number);
          break;
        case 2:
          printf("The conversion is: %d kilometers\n", number * 1000);
          break;
        default:
          printf("Invalid unit or number\n");
      }
      break;
    case 'kg':
      switch (number) {
        case 1:
          printf("The conversion is: %d grams\n", number * 1000);
          break;
        case 2:
          printf("The conversion is: %d tons\n", number * 1000000);
          break;
        default:
          printf("Invalid unit or number\n");
      }
      break;
    default:
      printf("Invalid unit or number\n");
  }

  return 0;
}
