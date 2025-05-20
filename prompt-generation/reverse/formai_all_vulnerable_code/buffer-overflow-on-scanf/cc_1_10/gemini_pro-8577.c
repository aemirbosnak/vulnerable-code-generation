//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: real-life
#include <stdio.h>

// Function to convert a binary number to its decimal equivalent
int binaryToDecimal(int binary) {
  int decimal = 0;
  int base = 1;

  while (binary > 0) {
    int lastBit = binary % 10;
    decimal += lastBit * base;
    base *= 2;
    binary /= 10;
  }

  return decimal;
}

// Function to convert a decimal number to its binary equivalent
int decimalToBinary(int decimal) {
  int binary = 0;
  int base = 1;

  while (decimal > 0) {
    int lastBit = decimal % 2;
    binary += lastBit * base;
    base *= 10;
    decimal /= 2;
  }

  return binary;
}

int main() {
  // Get the input number from the user
  int number;
  printf("Enter a number: ");
  scanf("%d", &number);

  // Check if the number is binary
  if (number >= 0) {
    // Convert the binary number to its decimal equivalent
    int decimal = binaryToDecimal(number);

    // Print the result
    printf("The decimal equivalent of %d is %d\n", number, decimal);
  } else {
    // Convert the decimal number to its binary equivalent
    int binary = decimalToBinary(number);

    // Print the result
    printf("The binary equivalent of %d is %d\n", number, binary);
  }

  return 0;
}