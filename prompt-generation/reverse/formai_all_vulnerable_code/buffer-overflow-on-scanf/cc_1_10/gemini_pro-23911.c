//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char *decimalToBinary(int n) {
  // Allocate memory for the binary string
  char *binaryString = (char *)malloc(33 * sizeof(char));

  // Initialize the binary string to all zeros
  for (int i = 0; i < 33; i++) {
    binaryString[i] = '0';
  }

  // Convert the decimal number to binary
  int i = 32;
  while (n > 0) {
    if (n % 2 == 1) {
      binaryString[i] = '1';
    }
    n = n / 2;
    i--;
  }

  // Return the binary string
  return binaryString;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char *binaryString) {
  // Initialize the decimal number to 0
  int decimalNumber = 0;

  // Convert the binary string to decimal
  int i = 0;
  while (binaryString[i] != '\0') {
    if (binaryString[i] == '1') {
      decimalNumber += 1 << (32 - i - 1);
    }
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

  // Print the binary string
  printf("Binary string: %s\n", binaryString);

  // Convert the binary string to decimal
  decimalNumber = binaryToDecimal(binaryString);

  // Print the decimal number
  printf("Decimal number: %d\n", decimalNumber);

  // Free the memory allocated for the binary string
  free(binaryString);

  return 0;
}