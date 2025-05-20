//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 1024
#define MAX_BINARY_SIZE 1024

// Function to convert decimal to binary
void decimalToBinary(int decimal, char *binary) {
  int remainder = decimal;
  int quotient = 1;
  char temp = '0';

  // Loop until the remainder is 0
  while (remainder > 0) {
    // Calculate the quotient and remainder for the next digit
    quotient *= 2;
    remainder -= (remainder / quotient) * quotient;

    // Store the digit in the binary string
    binary[((int)temp - '0')] = remainder % 2 == 0 ? '0' : '1';

    // Increment the index of the binary string
    temp++;
  }
}

// Function to convert binary to decimal
void binaryToDecimal(char *binary, int *decimal) {
  int index = 0;
  int value = 0;

  // Loop until the end of the binary string
  while (binary[index] != '\0') {
    // Convert the current digit to its decimal value
    value *= 2;
    value += (binary[index] - '0') << (index * 2);

    // Increment the index of the binary string
    index++;
  }

  // Store the result in the decimal variable
  *decimal = value;
}

int main() {
  int decimal;
  char binary[MAX_INPUT_SIZE];

  // Get the decimal number from the user
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  // Convert the decimal number to binary
  decimalToBinary(decimal, binary);

  // Print the binary representation of the number
  printf("The binary representation of %d is: %s\n", decimal, binary);

  // Get the binary number from the user
  printf("Enter a binary number: ");
  fgets(binary, MAX_INPUT_SIZE, stdin);

  // Convert the binary number to decimal
  binaryToDecimal(binary, &decimal);

  // Print the decimal representation of the number
  printf("The decimal representation of %s is: %d\n", binary, decimal);

  return 0;
}