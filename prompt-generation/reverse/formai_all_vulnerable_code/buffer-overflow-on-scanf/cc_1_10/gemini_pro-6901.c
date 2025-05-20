//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char *decimalToBinary(int n) {
  // Allocate memory for the binary string
  char *binaryString = malloc(33);

  // Initialize the binary string to all 0s
  for (int i = 0; i < 32; i++) {
    binaryString[i] = '0';
  }

  // Convert the decimal number to binary by repeatedly dividing by 2 and appending the remainder to the binary string
  int i = 31;
  while (n > 0) {
    binaryString[i--] = (n % 2) + '0';
    n /= 2;
  }

  // Return the binary string
  return binaryString;
}

// Function to convert a binary string to a decimal number
int binaryToDecimal(char *binaryString) {
  // Initialize the decimal number to 0
  int decimalNumber = 0;

  // Convert the binary string to a decimal number by multiplying each digit by the appropriate power of 2 and adding the results
  for (int i = 0; i < 32; i++) {
    if (binaryString[i] == '1') {
      decimalNumber += (1 << (31 - i));
    }
  }

  // Return the decimal number
  return decimalNumber;
}

int main() {
  // Get the decimal number from the user
  int decimalNumber;
  printf("Enter a decimal number: ");
  scanf("%d", &decimalNumber);

  // Convert the decimal number to binary
  char *binaryString = decimalToBinary(decimalNumber);

  // Print the binary string
  printf("Binary string: %s\n", binaryString);

  // Convert the binary string to a decimal number
  int decimalNumber2 = binaryToDecimal(binaryString);

  // Print the decimal number
  printf("Decimal number: %d\n", decimalNumber2);

  // Free the memory allocated for the binary string
  free(binaryString);

  return 0;
}