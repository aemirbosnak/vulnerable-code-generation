//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <hexadecimal number>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *hex_str = argv[1];
  int hex_len = strlen(hex_str);

  if (hex_len == 0) {
    printf("Error: Invalid hexadecimal number\n");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < hex_len; i++) {
    char hex_char = hex_str[i];
    if ((hex_char >= '0' && hex_char <= '9') ||
        (hex_char >= 'A' && hex_char <= 'F') ||
        (hex_char >= 'a' && hex_char <= 'f')) {
      continue;
    } else {
      printf("Error: Invalid hexadecimal number\n");
      return EXIT_FAILURE;
    }
  }

  int decimal_num = 0;
  int base = 1;

  for (int i = hex_len - 1; i >= 0; i--) {
    char hex_char = hex_str[i];
    int digit_value;

    if (hex_char >= '0' && hex_char <= '9') {
      digit_value = hex_char - '0';
    } else if (hex_char >= 'A' && hex_char <= 'F') {
      digit_value = hex_char - 'A' + 10;
    } else if (hex_char >= 'a' && hex_char <= 'f') {
      digit_value = hex_char - 'a' + 10;
    }

    decimal_num += digit_value * base;
    base *= 16;
  }

  printf("Decimal number: %d\n", decimal_num);

  return EXIT_SUCCESS;
}