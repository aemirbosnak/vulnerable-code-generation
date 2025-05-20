//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUMBER_OF_BITS 32
#define MAX_NUMBER_OF_BYTES 4

// Function to convert a binary number to its decimal equivalent
int binaryToDecimal(char binary[MAX_NUMBER_OF_BYTES], int numberOfBytes) {
  int decimal = 0;
  for (int i = 0; i < numberOfBytes; i++) {
    decimal += (binary[i] - '0') * pow(2, i);
  }
  return decimal;
}

// Function to convert a decimal number to its binary equivalent
char decimalToBinary(int decimal) {
  char binary[MAX_NUMBER_OF_BYTES];
  int numberOfBytes = 0;
  while (decimal != 0) {
    binary[numberOfBytes] = decimal % 2 == 0 ? '0' : '1';
    decimal /= 2;
    numberOfBytes++;
  }
  return binary[0];
}

int main() {
  char binary[MAX_NUMBER_OF_BYTES];
  int numberOfBytes;
  int decimal;

  // Get the binary number from the user
  printf("Enter a binary number (max %d bytes): ", MAX_NUMBER_OF_BYTES);
  scanf("%s", binary);

  // Convert the binary number to its decimal equivalent
  decimal = binaryToDecimal(binary, strlen(binary));

  // Print the decimal number
  printf("Decimal equivalent of %s: %d\n", binary, decimal);

  // Get the decimal number from the user
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  // Convert the decimal number to its binary equivalent
  binary[0] = decimalToBinary(decimal);

  // Print the binary number
  printf("Binary equivalent of %d: %s\n", decimal, binary);

  return 0;
}