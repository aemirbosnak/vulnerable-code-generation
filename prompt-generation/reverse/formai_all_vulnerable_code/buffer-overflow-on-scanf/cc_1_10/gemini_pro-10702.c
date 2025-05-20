//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int dec = 0;

  for (int i = len - 1; i >= 0; i--) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      dec += (hex[i] - '0') * base;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      dec += (hex[i] - 'A' + 10) * base;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      dec += (hex[i] - 'a' + 10) * base;
    }
    base *= 16;
  }

  return dec;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int dec) {
  char *hex = (char *)malloc(100);
  int i = 0;

  while (dec != 0) {
    int temp = dec % 16;
    if (temp < 10) {
      hex[i++] = temp + '0';
    } else {
      hex[i++] = temp - 10 + 'A';
    }
    dec /= 16;
  }

  hex[i] = '\0';

  return hex;
}

int main() {
  // Get the hexadecimal string from the user
  char hex[100];
  printf("Enter a hexadecimal string: ");
  scanf("%s", hex);

  // Convert the hexadecimal string to an integer
  int dec = hex_to_int(hex);

  // Print the converted integer
  printf("The integer equivalent of %s is %d\n", hex, dec);

  // Convert the integer back to a hexadecimal string
  char *hex2 = int_to_hex(dec);

  // Print the converted hexadecimal string
  printf("The hexadecimal equivalent of %d is %s\n", dec, hex2);

  return 0;
}