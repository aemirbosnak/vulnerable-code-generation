#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char hex_input[1024];
  int i, j, k, num_cases = 0;

  scanf("Enter the number of test cases: ", &num_cases);

  for (i = 0; i < num_cases; i++) {
    printf("Enter hexadecimal number: ");
    scanf("%s", hex_input);

    for (j = 0; hex_input[j] != '\0'; j++) {
      if (hex_input[j] >= 'a' && hex_input[j] <= 'f') {
        hex_input[j] -= 32;
      }
    }

    for (k = 0; k < 10; k++) {
      if (hex_input[k] >= 'a' && hex_input[k] <= 'f') {
        hex_input[k] -= 32;
      }
    }

    switch (hex_input[0]) {
      case 'a':
        printf("Converted number: %x\n", hex_input[1] << 16 | hex_input[2] << 8 | hex_input[3] << 0);
        break;
      case 'b':
        printf("Converted number: %x\n", hex_input[1] << 16 | hex_input[2] << 8 | hex_input[3] << 0);
        break;
      default:
        printf("Invalid input.\n");
    }
  }

  return 0;
}
