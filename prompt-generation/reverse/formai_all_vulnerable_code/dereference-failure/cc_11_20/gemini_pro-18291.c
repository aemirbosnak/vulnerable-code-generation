//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <hexadecimal number>\n", argv[0]);
    return 1;
  }

  char *hex = argv[1];
  int len = strlen(hex);

  if (len % 2 != 0) {
    printf("Error: Hexadecimal number must have an even number of digits.\n");
    return 1;
  }

  int i;
  int decimal = 0;
  for (i = 0; i < len; i += 2) {
    char c1 = hex[i];
    char c2 = hex[i + 1];

    int digit1, digit2;

    if (c1 >= '0' && c1 <= '9') {
      digit1 = c1 - '0';
    } else if (c1 >= 'A' && c1 <= 'F') {
      digit1 = c1 - 'A' + 10;
    } else if (c1 >= 'a' && c1 <= 'f') {
      digit1 = c1 - 'a' + 10;
    } else {
      printf("Error: Invalid hexadecimal digit: %c\n", c1);
      return 1;
    }

    if (c2 >= '0' && c2 <= '9') {
      digit2 = c2 - '0';
    } else if (c2 >= 'A' && c2 <= 'F') {
      digit2 = c2 - 'A' + 10;
    } else if (c2 >= 'a' && c2 <= 'f') {
      digit2 = c2 - 'a' + 10;
    } else {
      printf("Error: Invalid hexadecimal digit: %c\n", c2);
      return 1;
    }

    decimal = decimal * 16 + digit1 * 16 + digit2;
  }

  printf("Decimal: %d\n", decimal);
  return 0;
}