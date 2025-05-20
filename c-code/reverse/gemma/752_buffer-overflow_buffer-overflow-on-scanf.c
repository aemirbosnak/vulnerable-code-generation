#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char hex_input[100];
  int decimal_output;

  printf("Enter a hexadecimal number: ");
  scanf("%s", hex_input);

  decimal_output = strtol(hex_input, NULL, 16);

  printf("Decimal equivalent: %d\n", decimal_output);

  return 0;
}
