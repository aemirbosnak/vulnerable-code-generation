#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[100];
  int choice, decimal, hex;
  char output[100];

  printf("Enter 1 for Hex to Decimal or 2 for Decimal to Hex: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter a hexadecimal number: ");
      scanf("%s", input);
      hex = strtol(input, NULL, 16);
      decimal = hex;
      sprintf(output, "Decimal equivalent: %d", decimal);
      printf("%s\n", output);
      break;
    case 2:
      printf("Enter a decimal number: ");
      scanf("%d", &decimal);
      hex = decimal;
      sprintf(output, "Hex equivalent: %x", hex);
      printf("%s\n", output);
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}
