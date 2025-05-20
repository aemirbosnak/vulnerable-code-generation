#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice, num, hex_num;
  char hex_str[20];

  printf("Select an option:\n");
  printf("1. Hex to Decimal\n");
  printf("2. Decimal to Hex\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter a hexadecimal number: ");
      scanf("%s", hex_str);
      hex_num = strtol(hex_str, NULL, 16);
      printf("Decimal equivalent: %d\n", hex_num);
      break;
    case 2:
      printf("Enter a decimal number: ");
      scanf("%d", &num);
      sprintf(hex_str, "%x", num);
      printf("Hex equivalent: %s\n", hex_str);
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}
