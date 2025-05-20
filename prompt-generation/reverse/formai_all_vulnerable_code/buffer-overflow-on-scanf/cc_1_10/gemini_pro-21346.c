//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a "look-up table" for the binary digits.
const char *binary_digits = "01";

// This function converts a decimal number to its binary representation.
char *decimal_to_binary(int decimal) {
  // Allocate memory for the binary representation.
  char *binary = malloc(33);
  if (binary == NULL) {
    return NULL;
  }

  // Initialize the binary representation to the empty string.
  binary[0] = '\0';

  // While the decimal number is greater than 0, repeatedly divide it by 2 and append the remainder to the binary representation.
  while (decimal > 0) {
    int remainder = decimal % 2;
    decimal /= 2;
    char digit = binary_digits[remainder];
    strcat(binary, &digit);
  }

  // Reverse the binary representation.
  int length = strlen(binary);
  for (int i = 0; i < length / 2; i++) {
    char temp = binary[i];
    binary[i] = binary[length - i - 1];
    binary[length - i - 1] = temp;
  }

  // Return the binary representation.
  return binary;
}

// This function converts a binary number to its decimal representation.
int binary_to_decimal(const char *binary) {
  // Initialize the decimal representation to 0.
  int decimal = 0;

  // Iterate over the binary digits from right to left.
  int length = strlen(binary);
  for (int i = 0; i < length; i++) {
    // Get the binary digit at the current position.
    char digit = binary[i];

    // Multiply the decimal representation by 2.
    decimal *= 2;

    // Add the binary digit to the decimal representation.
    if (digit == '1') {
      decimal++;
    }
  }

  // Return the decimal representation.
  return decimal;
}

int main() {
  // Get the decimal number from the user.
  int decimal;
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  // Convert the decimal number to its binary representation.
  char *binary = decimal_to_binary(decimal);
  if (binary == NULL) {
    printf("Error allocating memory for the binary representation.\n");
    return 1;
  }

  // Print the binary representation.
  printf("The binary representation of %d is %s.\n", decimal, binary);

  // Convert the binary representation back to its decimal representation.
  int decimal_from_binary = binary_to_decimal(binary);
  if (decimal_from_binary == -1) {
    printf("Error converting the binary representation back to its decimal representation.\n");
    return 1;
  }

  // Print the decimal representation.
  printf("The decimal representation of %s is %d.\n", binary, decimal_from_binary);

  // Free the memory allocated for the binary representation.
  free(binary);

  return 0;
}