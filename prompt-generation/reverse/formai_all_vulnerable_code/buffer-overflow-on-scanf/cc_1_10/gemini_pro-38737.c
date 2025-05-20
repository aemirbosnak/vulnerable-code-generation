//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to its decimal equivalent
int hexToDecimal(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int dec = 0;

  // Iterate through the hexadecimal string from right to left
  for (int i = len - 1; i >= 0; i--) {
    // Get the digit value of the current character
    int digit;
    if (hex[i] >= '0' && hex[i] <= '9') {
      digit = hex[i] - '0';
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      digit = hex[i] - 'A' + 10;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      digit = hex[i] - 'a' + 10;
    } else {
      return -1;  // Invalid hexadecimal character
    }

    // Multiply the digit value by the appropriate base and add it to the decimal result
    dec += digit * base;

    // Update the base for the next digit
    base *= 16;
  }

  return dec;
}

int main() {
  // Get the hexadecimal string from the user
  char hex[100];
  printf("Enter a hexadecimal string: ");
  scanf("%s", hex);

  // Convert the hexadecimal string to its decimal equivalent
  int dec = hexToDecimal(hex);

  // Print the result
  if (dec != -1) {
    printf("The decimal equivalent of %s is %d\n", hex, dec);
  } else {
    printf("Invalid hexadecimal string\n");
  }

  return 0;
}