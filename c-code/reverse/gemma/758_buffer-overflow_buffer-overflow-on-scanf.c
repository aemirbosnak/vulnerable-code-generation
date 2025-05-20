#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice, num, hex_num;
  char hex_char;

  printf("Enter 1 for hexadecimal to decimal or 2 for decimal to hexadecimal: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter a hexadecimal number: ");
      scanf("%x", &hex_num);
      num = hex_num;
      printf("The decimal equivalent is: %d", num);
      break;
    case 2:
      printf("Enter a decimal number: ");
      scanf("%d", &num);
      hex_num = num;
      printf("The hexadecimal equivalent is: %x", hex_num);
      break;
    default:
      printf("Invalid input.");
  }

  return 0;
}
