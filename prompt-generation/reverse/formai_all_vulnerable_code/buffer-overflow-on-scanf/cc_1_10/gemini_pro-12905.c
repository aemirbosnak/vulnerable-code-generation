//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declare variables
  char hexString[100];
  int decimalValue;
  int i, j, k;
  int len;

  // Get the hexadecimal string from the user
  printf("Enter the hexadecimal string: ");
  scanf("%s", hexString);

  // Calculate the length of the hexadecimal string
  len = strlen(hexString);

  // Convert the hexadecimal string to decimal value
  decimalValue = 0;
  for (i = 0; i < len; i++) {
    // Get the current character from the hexadecimal string
    char c = hexString[i];

    // Check if the current character is a digit
    if (c >= '0' && c <= '9') {
      // Convert the current character to a decimal value
      j = c - '0';
    } else if (c >= 'a' && c <= 'f') {
      // Convert the current character to a decimal value
      j = c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
      // Convert the current character to a decimal value
      j = c - 'A' + 10;
    } else {
      // The current character is not a valid hexadecimal digit
      printf("Invalid hexadecimal string\n");
      return 1;
    }

    // Multiply the decimal value by the appropriate power of 16
    k = len - i - 1;
    decimalValue += j * (1 << (k * 4));
  }

  // Print the decimal value
  printf("The decimal value of the hexadecimal string is: %d\n", decimalValue);

  return 0;
}