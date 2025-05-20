//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a binary number to decimal
int binaryToDecimal(char *binary) {
  int decimal = 0;
  int length = strlen(binary);

  // Iterate through the binary string from right to left
  for (int i = 0; i < length; i++) {
    // Get the digit at the current position
    int digit = binary[i] - '0';

    // Multiply the digit by the appropriate power of 2
    int power = 1 << (length - i - 1);
    decimal += digit * power;
  }

  return decimal;
}

// Function to convert a decimal number to binary
char *decimalToBinary(int decimal) {
  // Create a buffer to store the binary string
  char *binary = malloc(33);
  memset(binary, 0, 33);

  // Iterate through the buffer from right to left
  int i = 32;
  while (decimal > 0) {
    // Get the remainder of the division by 2
    int remainder = decimal % 2;

    // Convert the remainder to a character
    char digit = remainder + '0';

    // Store the digit in the buffer
    binary[i] = digit;

    // Divide the decimal by 2
    decimal /= 2;

    i--;
  }

  return binary;
}

int main() {
  // Get the binary number from the user
  char binary[33];
  printf("Enter a binary number: ");
  scanf("%s", binary);

  // Convert the binary number to decimal
  int decimal = binaryToDecimal(binary);

  // Print the decimal number
  printf("The decimal equivalent of %s is %d\n", binary, decimal);

  // Convert the decimal number to binary
  char *binary2 = decimalToBinary(decimal);

  // Print the binary number
  printf("The binary equivalent of %d is %s\n", decimal, binary2);

  return 0;
}