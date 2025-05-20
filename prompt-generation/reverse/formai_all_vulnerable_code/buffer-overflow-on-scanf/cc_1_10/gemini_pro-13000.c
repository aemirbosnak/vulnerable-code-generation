//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char *decimalToBinary(int n) {
  // Allocate memory for the binary string
  char *binaryString = malloc(sizeof(char) * 33);

  // Initialize the binary string to empty
  binaryString[0] = '\0';

  // Iterate through the bits of the decimal number
  int i = 0;
  while (n > 0) {
    // Append the least significant bit of the decimal number to the binary string
    binaryString[i++] = (n % 2) + '0';

    // Shift the decimal number to the right by 1 bit
    n >>= 1;
  }

  // Reverse the binary string
  for (int j = 0; j < i / 2; j++) {
    char temp = binaryString[j];
    binaryString[j] = binaryString[i - j - 1];
    binaryString[i - j - 1] = temp;
  }

  // Return the binary string
  return binaryString;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char *binaryString) {
  // Initialize the decimal number to 0
  int decimalNumber = 0;

  // Iterate through the bits of the binary string
  int i = 0;
  while (binaryString[i] != '\0') {
    // Multiply the decimal number by 2
    decimalNumber *= 2;

    // Add the value of the current bit to the decimal number
    decimalNumber += binaryString[i] - '0';

    // Increment the index of the binary string
    i++;
  }

  // Return the decimal number
  return decimalNumber;
}

// Main function
int main() {
  // Get the decimal number from the user
  int decimalNumber;
  printf("Enter a decimal number: ");
  scanf("%d", &decimalNumber);

  // Convert the decimal number to binary
  char *binaryString = decimalToBinary(decimalNumber);

  // Print the binary number
  printf("The binary representation of %d is %s\n", decimalNumber, binaryString);

  // Convert the binary number to decimal
  int convertedDecimalNumber = binaryToDecimal(binaryString);

  // Print the converted decimal number
  printf("The decimal representation of %s is %d\n", binaryString, convertedDecimalNumber);

  // Free the memory allocated for the binary string
  free(binaryString);

  return 0;
}