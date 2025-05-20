//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hexadecimal digits
char hex_digits[] = "0123456789ABCDEF";

// Get the hexadecimal representation of a decimal number
char *decimal_to_hexadecimal(int decimal) {
  // Create a buffer to store the hexadecimal representation
  char *hexadecimal = malloc(sizeof(char) * 10);

  // Convert the decimal number to hexadecimal
  int i = 0;
  while (decimal > 0) {
    hexadecimal[i++] = hex_digits[decimal % 16];
    decimal /= 16;
  }

  // Reverse the hexadecimal representation
  for (int j = 0; j < i / 2; j++) {
    char temp = hexadecimal[j];
    hexadecimal[j] = hexadecimal[i - j - 1];
    hexadecimal[i - j - 1] = temp;
  }

  // Terminate the hexadecimal representation with a null character
  hexadecimal[i] = '\0';

  // Return the hexadecimal representation
  return hexadecimal;
}

// Main function
int main() {
  // Get the decimal number from the user
  int decimal;
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  // Convert the decimal number to hexadecimal
  char *hexadecimal = decimal_to_hexadecimal(decimal);

  // Print the hexadecimal representation
  printf("The hexadecimal representation of %d is %s\n", decimal, hexadecimal);

  // Free the memory allocated for the hexadecimal representation
  free(hexadecimal);

  return 0;
}