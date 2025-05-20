//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hex_to_dec(char hex[]) {
  int len = strlen(hex);
  int base = 1;
  int dec = 0;

  // Iterate over the digits of the hexadecimal number from right to left
  for (int i = len - 1; i >= 0; i--) {
    // Convert the current digit to its decimal equivalent
    int digit;
    if (hex[i] >= '0' && hex[i] <= '9') {
      digit = hex[i] - '0';
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      digit = hex[i] - 'A' + 10;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      digit = hex[i] - 'a' + 10;
    } else {
      return -1; // Invalid hexadecimal digit
    }

    // Multiply the digit by the appropriate power of 16 and add it to the decimal result
    dec += digit * base;
    base *= 16;
  }

  return dec;
}

// Function to convert decimal to hexadecimal
char *dec_to_hex(int dec) {
  char *hex = malloc(sizeof(char) * 100);
  int i = 0;

  // Iterate until the decimal number is 0
  while (dec > 0) {
    // Get the remainder of the division by 16
    int remainder = dec % 16;

    // Convert the remainder to a hexadecimal digit
    char digit;
    if (remainder < 10) {
      digit = remainder + '0';
    } else {
      digit = remainder - 10 + 'A';
    }

    // Append the digit to the hexadecimal string
    hex[i++] = digit;

    // Divide the decimal number by 16
    dec /= 16;
  }

  // Reverse the hexadecimal string
  char *reversed_hex = malloc(sizeof(char) * 100);
  int j = 0;
  for (i = strlen(hex) - 1; i >= 0; i--) {
    reversed_hex[j++] = hex[i];
  }

  free(hex);
  return reversed_hex;
}

int main() {
  // Get the hexadecimal number from the user
  char hex[100];
  printf("Enter a hexadecimal number: ");
  scanf("%s", hex);

  // Convert the hexadecimal number to decimal
  int dec = hex_to_dec(hex);
  if (dec == -1) {
    printf("Invalid hexadecimal number\n");
    return 1;
  }

  // Print the decimal number
  printf("Decimal equivalent: %d\n", dec);

  // Convert the decimal number back to hexadecimal
  char *hex_result = dec_to_hex(dec);

  // Print the hexadecimal result
  printf("Hexadecimal equivalent: %s\n", hex_result);

  free(hex_result);
  return 0;
}