//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int is_valid_hex(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else if (c >= 'A' && c <= 'F') {
    return 1;
  } else if (c >= 'a' && c <= 'f') {
    return 1;
  } else {
    return 0;
  }
}

int hex_to_decimal(char* hex) {
  int dec = 0;
  int power = 0;

  for (int i = strlen(hex) - 1; i >= 0; i--) {
    if (is_valid_hex(hex[i])) {
      if (hex[i] >= '0' && hex[i] <= '9') {
        dec += hex[i] - '0';
      } else if (hex[i] >= 'A' && hex[i] <= 'F') {
        dec += hex[i] - 'A' + 10;
      } else if (hex[i] >= 'a' && hex[i] <= 'f') {
        dec += hex[i] - 'a' + 10;
      }
    } else {
      return -1;
    }

    power *= 16;
  }

  return dec;
}

int decimal_to_hex(int dec) {
  char hex[MAX_LENGTH];
  int power = 1;

  sprintf(hex, "%X", dec);

  return strlen(hex);
}

int main() {
  char hex[MAX_LENGTH];
  int dec;

  printf("Enter a hexadecimal number: ");
  scanf("%s", hex);

  dec = hex_to_decimal(hex);

  if (dec == -1) {
    printf("Invalid hexadecimal number!\n");
  } else {
    printf("Decimal equivalent: %d\n", dec);
    printf("Hexadecimal equivalent: ");
    for (int i = strlen(hex) - 1; i >= 0; i--) {
      printf("%c", hex[i]);
    }
    printf("\n");
  }

  return 0;
}