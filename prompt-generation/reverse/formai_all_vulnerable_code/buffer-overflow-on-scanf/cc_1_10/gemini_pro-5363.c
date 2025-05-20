//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to a decimal integer
int hex_to_dec(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int dec = 0;

  for (int i = len - 1; i >= 0; i--) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      dec += (hex[i] - '0') * base;
      base *= 16;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      dec += (hex[i] - 'A' + 10) * base;
      base *= 16;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      dec += (hex[i] - 'a' + 10) * base;
      base *= 16;
    }
  }

  return dec;
}

// Function to convert a decimal integer to a hexadecimal string
char *dec_to_hex(int dec) {
  int len = 0;
  int temp = dec;

  // Count the number of digits in the hexadecimal representation
  while (temp > 0) {
    temp /= 16;
    len++;
  }

  // Allocate memory for the hexadecimal string
  char *hex = (char *)malloc(len + 1);

  // Convert the decimal integer to a hexadecimal string
  for (int i = len - 1; i >= 0; i--) {
    int digit = dec % 16;
    if (digit < 10) {
      hex[i] = digit + '0';
    } else {
      hex[i] = digit - 10 + 'A';
    }
    dec /= 16;
  }

  hex[len] = '\0';

  return hex;
}

// Main function
int main() {
  // Get the hexadecimal string from the user
  char hex[100];
  printf("Enter the hexadecimal string: ");
  scanf("%s", hex);

  // Convert the hexadecimal string to a decimal integer
  int dec = hex_to_dec(hex);

  // Print the decimal integer
  printf("The decimal equivalent of %s is %d\n", hex, dec);

  // Convert the decimal integer back to a hexadecimal string
  char *hex_back = dec_to_hex(dec);

  // Print the hexadecimal string
  printf("The hexadecimal equivalent of %d is %s\n", dec, hex_back);

  return 0;
}