//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
int *decimalToBinary(int n) {
  // Check if the number is negative
  if (n < 0) {
    printf("Please enter a non-negative integer.\n");
    return NULL;
  }

  // Initialize the binary array with the maximum possible size
  int *binary = malloc(32 * sizeof(int));

  // Initialize the index of the binary array
  int index = 0;

  // While the number is greater than 0
  while (n > 0) {
    // Get the remainder of the number when divided by 2
    binary[index] = n % 2;

    // Divide the number by 2
    n /= 2;

    // Increment the index of the binary array
    index++;
  }

  // Return the binary array
  return binary;
}

// Function to convert a binary number to decimal
int binaryToDecimal(int *binary) {
  // Initialize the decimal number to 0
  int decimal = 0;

  // Get the length of the binary array
  int length = sizeof(binary) / sizeof(binary[0]);

  // For each bit in the binary array
  for (int i = 0; i < length; i++) {
    // Get the value of the bit
    int bit = binary[i];

    // Shift the decimal number left by 1 bit
    decimal <<= 1;

    // Add the value of the bit to the decimal number
    decimal += bit;
  }

  // Return the decimal number
  return decimal;
}

// Function to print a binary number
void printBinary(int *binary) {
  // Get the length of the binary array
  int length = sizeof(binary) / sizeof(binary[0]);

  // For each bit in the binary array
  for (int i = length - 1; i >= 0; i--) {
    // Print the value of the bit
    printf("%d", binary[i]);
  }

  // Print a newline character
  printf("\n");
}

// Main function
int main() {
  // Get the decimal number from the user
  int decimal;
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  // Convert the decimal number to binary
  int *binary = decimalToBinary(decimal);

  // Print the binary number
  printf("The binary representation of %d is: ", decimal);
  printBinary(binary);

  // Convert the binary number to decimal
  int decimal2 = binaryToDecimal(binary);

  // Print the decimal number
  printf("The decimal representation of the binary number is: %d\n", decimal2);

  // Free the memory allocated for the binary array
  free(binary);

  return 0;
}