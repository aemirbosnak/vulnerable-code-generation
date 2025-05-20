#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char hex_input[100];
  int decimal_output;
  int i = 0;

  printf("Enter a hexadecimal number: ");
  scanf("%s", hex_input);

  if (strlen(hex_input) > 20) {
    printf("Error: Input too long.\n");
    return 1;
  }

  for (i = 0; hex_input[i] != '\0'; i++) {
    if ((hex_input[i] >= 'a' && hex_input[i] <= 'f') || (hex_input[i] >= 'A' && hex_input[i] <= 'F')) {
      decimal_output = decimal_output * 16 + (hex_input[i] - 'a' + 10) * 16;
    } else if (hex_input[i] >= '0' && hex_input[i] <= '9') {
      decimal_output = decimal_output * 16 + (hex_input[i] - '0') * 16;
    } else {
      printf("Error: Invalid input.\n");
      return 1;
    }
  }

  printf("Decimal equivalent: %d\n", decimal_output);

  return 0;
}
