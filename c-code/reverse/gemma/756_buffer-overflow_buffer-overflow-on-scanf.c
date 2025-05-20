#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char input[10];
  int i, decimal, hex;

  printf("Enter a hexadecimal number: ");
  scanf("%s", input);

  switch (strlen(input)) {
    case 1:
      hex = input[0] - 'a' + 10;
      break;
    case 2:
      hex = (input[0] - 'a' + 10) * 16 + input[1] - 'a' + 10;
      break;
    default:
      printf("Invalid input.\n");
      return 1;
  }

  decimal = hex * 16 + 10;
  printf("Decimal equivalent: %d\n", decimal);

  return 0;
}
