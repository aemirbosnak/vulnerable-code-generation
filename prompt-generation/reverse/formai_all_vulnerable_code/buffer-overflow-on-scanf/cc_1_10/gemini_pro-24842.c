//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal number to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int dec = 0;

  // Iterate through the hexadecimal number from right to left
  for (int i = len - 1; i >= 0; i--) {
    // Get the digit value of the current character
    int digit;
    if (hex[i] >= '0' && hex[i] <= '9') {
      digit = hex[i] - '0';
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      digit = hex[i] - 'a' + 10;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      digit = hex[i] - 'A' + 10;
    } else {
      // Invalid character, return -1
      return -1;
    }

    // Multiply the digit by the appropriate base and add it to the decimal value
    dec += digit * base;

    // Multiply the base by 16 to move to the next digit
    base *= 16;
  }

  // Return the decimal value
  return dec;
}

// Function to convert an integer to a hexadecimal number
char *int_to_hex(int dec) {
  // Allocate memory for the hexadecimal number
  char *hex = (char *)malloc(sizeof(char) * 10);

  // Initialize the hexadecimal number to the empty string
  strcpy(hex, "");

  // Iterate through the digits of the decimal number from right to left
  while (dec > 0) {
    // Get the remainder of the division by 16
    int remainder = dec % 16;

    // Convert the remainder to a hexadecimal digit
    char digit;
    if (remainder < 10) {
      digit = remainder + '0';
    } else {
      digit = remainder - 10 + 'a';
    }

    // Append the hexadecimal digit to the hexadecimal number
    strcat(hex, &digit);

    // Divide the decimal number by 16 to move to the next digit
    dec /= 16;
  }

  // Reverse the hexadecimal number to get the correct order of the digits
  int len = strlen(hex);
  for (int i = 0; i < len / 2; i++) {
    char temp = hex[i];
    hex[i] = hex[len - i - 1];
    hex[len - i - 1] = temp;
  }

  // Return the hexadecimal number
  return hex;
}

int main() {
  // Get the hexadecimal number from the user
  char hex[100];
  printf("Enter a hexadecimal number: ");
  scanf("%s", hex);

  // Convert the hexadecimal number to an integer
  int dec = hex_to_int(hex);

  // Check if the conversion was successful
  if (dec == -1) {
    printf("Invalid hexadecimal number.\n");
    return 1;
  }

  // Print the decimal number
  printf("The decimal equivalent of %s is %d.\n", hex, dec);

  // Convert the integer back to a hexadecimal number
  char *new_hex = int_to_hex(dec);

  // Print the hexadecimal number
  printf("The hexadecimal equivalent of %d is %s.\n", dec, new_hex);

  // Free the allocated memory
  free(new_hex);

  return 0;
}