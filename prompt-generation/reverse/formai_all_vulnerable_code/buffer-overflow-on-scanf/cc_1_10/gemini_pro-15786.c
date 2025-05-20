//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Global constants
const char *HEX_DIGITS = "0123456789ABCDEF";
const int HEX_BASE = 16;

// Function to convert a decimal number to hexadecimal
char *dec_to_hex(int dec) {
  // Allocate memory for the hexadecimal string
  char *hex = malloc(11);

  // Initialize the hexadecimal string
  hex[0] = '\0';

  // Convert the decimal number to hexadecimal
  while (dec > 0) {
    int digit = dec % HEX_BASE;
    hex = realloc(hex, strlen(hex) + 2);
    hex[strlen(hex)] = HEX_DIGITS[digit];
    hex[strlen(hex) + 1] = '\0';
    dec /= HEX_BASE;
  }

  // Reverse the hexadecimal string
  int len = strlen(hex);
  for (int i = 0; i < len / 2; i++) {
    char temp = hex[i];
    hex[i] = hex[len - i - 1];
    hex[len - i - 1] = temp;
  }

  return hex;
}

// Function to convert a hexadecimal number to decimal
int hex_to_dec(char *hex) {
  // Initialize the decimal number
  int dec = 0;

  // Convert the hexadecimal number to decimal
  for (int i = 0; hex[i] != '\0'; i++) {
    int digit = 0;
    if (hex[i] >= '0' && hex[i] <= '9') {
      digit = hex[i] - '0';
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      digit = hex[i] - 'A' + 10;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      digit = hex[i] - 'a' + 10;
    }
    dec = dec * HEX_BASE + digit;
  }

  return dec;
}

// Main function
int main() {
  // Get the decimal number from the user
  int dec;
  printf("Enter a decimal number: ");
  scanf("%d", &dec);

  // Convert the decimal number to hexadecimal
  char *hex = dec_to_hex(dec);

  // Print the hexadecimal number
  printf("Hexadecimal: %s\n", hex);

  // Convert the hexadecimal number to decimal
  int dec2 = hex_to_dec(hex);

  // Print the decimal number
  printf("Decimal: %d\n", dec2);

  // Free the allocated memory
  free(hex);

  return 0;
}