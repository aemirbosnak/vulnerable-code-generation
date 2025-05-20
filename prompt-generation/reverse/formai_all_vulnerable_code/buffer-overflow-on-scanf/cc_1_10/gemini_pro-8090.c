//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
char *decimalToBinary(int n) {
  // Check for negative numbers
  if (n < 0) {
    printf("Error: Negative numbers not supported!\n");
    return NULL;
  }

  // Allocate memory for the binary representation
  int binaryLength = 32; // Assuming 32-bit integers
  char *binary = malloc(binaryLength + 1);
  if (binary == NULL) {
    printf("Error: Memory allocation failed!\n");
    return NULL;
  }

  // Initialize the binary representation to all zeros
  memset(binary, '0', binaryLength);
  binary[binaryLength] = '\0'; // Null-terminate the string

  // Convert the decimal number to binary, one bit at a time
  int i = binaryLength - 1;
  while (n > 0) {
    if (n % 2 == 1) {
      binary[i] = '1';
    }
    n /= 2;
    i--;
  }

  // Return the binary representation
  return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(char *binary) {
  // Check for invalid binary representations
  if (strlen(binary) > 32) {
    printf("Error: Binary representation too long!\n");
    return -1;
  }

  for (int i = 0; i < strlen(binary); i++) {
    if (binary[i] != '0' && binary[i] != '1') {
      printf("Error: Invalid binary representation!\n");
      return -1;
    }
  }

  // Convert the binary representation to decimal
  int decimal = 0;
  for (int i = strlen(binary) - 1, j = 0; i >= 0; i--, j++) {
    if (binary[i] == '1') {
      decimal += (1 << j);
    }
  }

  // Return the decimal representation
  return decimal;
}

// Main function
int main() {
  // Get the input number from the user
  printf("Enter a decimal number: ");
  int number;
  if (scanf("%d", &number) != 1) {
    printf("Error: Invalid input!\n");
    return 1;
  }

  // Convert the decimal number to binary
  char *binary = decimalToBinary(number);
  if (binary == NULL) {
    return 1;
  }

  // Print the binary representation
  printf("Binary representation: %s\n", binary);

  // Convert the binary representation to decimal
  int decimal = binaryToDecimal(binary);
  if (decimal == -1) {
    return 1;
  }

  // Print the decimal representation
  printf("Decimal representation: %d\n", decimal);

  // Free the allocated memory
  free(binary);

  return 0;
}