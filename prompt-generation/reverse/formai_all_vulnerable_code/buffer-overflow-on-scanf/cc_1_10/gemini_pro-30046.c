//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of digits in a binary number
#define MAX_DIGITS 32

// Function to convert a decimal number to binary
void decimalToBinary(int decimalNumber) {
  // Create an array to store the binary digits
  int binaryDigits[MAX_DIGITS];

  // Initialize the index of the binary digits array
  int index = 0;

  // While the decimal number is greater than 0
  while (decimalNumber > 0) {
    // Get the remainder of the decimal number when divided by 2
    binaryDigits[index] = decimalNumber % 2;

    // Divide the decimal number by 2
    decimalNumber /= 2;

    // Increment the index of the binary digits array
    index++;
  }

  // Print the binary digits in reverse order
  for (int i = index - 1; i >= 0; i--) {
    printf("%d", binaryDigits[i]);
  }

  // Print a newline character
  printf("\n");
}

// Function to convert a binary number to decimal
int binaryToDecimal(int binaryNumber) {
  // Initialize the decimal number to 0
  int decimalNumber = 0;

  // Get the length of the binary number
  int length = snprintf(NULL, 0, "%d", binaryNumber);

  // Iterate over the digits of the binary number
  for (int i = 0; i < length; i++) {
    // Get the digit at the current index
    int digit = binaryNumber % 10;

    // Multiply the decimal number by 2
    decimalNumber *= 2;

    // Add the digit to the decimal number
    decimalNumber += digit;

    // Divide the binary number by 10
    binaryNumber /= 10;
  }

  // Return the decimal number
  return decimalNumber;
}

// Main function
int main() {
  // Get the input from the user
  int input;
  printf("Enter a decimal or binary number: ");
  scanf("%d", &input);

  // Check if the input is a decimal number
  if (input >= 0) {
    // Convert the decimal number to binary
    printf("Binary representation: ");
    decimalToBinary(input);
  } else {
    // Convert the binary number to decimal
    printf("Decimal representation: %d\n", binaryToDecimal(input));
  }

  return 0;
}