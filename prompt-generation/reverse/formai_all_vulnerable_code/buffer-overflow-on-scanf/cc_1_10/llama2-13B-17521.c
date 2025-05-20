//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: surprised
#include <stdio.h>

int main() {
  // Declare variables
  int binary, decimal;

  // Ask the user for a binary number
  printf("Enter a binary number: ");
  scanf("%d", &binary);

  // Convert binary to decimal
  decimal = binaryToDecimal(binary);
  printf("Binary: %d, Decimal: %d\n", binary, decimal);

  // Ask the user for a decimal number
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  // Convert decimal to binary
  binary = decimalToBinary(decimal);
  printf("Decimal: %d, Binary: %d\n", decimal, binary);

  return 0;
}

// Function to convert binary to decimal
int binaryToDecimal(int binary) {
  int sum = 0;

  while (binary > 0) {
    sum += (binary % 2) * (pow(2, (binary > 0)) - 1);
    binary /= 2;
  }

  return sum;
}

// Function to convert decimal to binary
int decimalToBinary(int decimal) {
  int binary = 0;
  int exponent = 1;

  while (decimal > 0) {
    binary = (decimal % 2) + (binary * (pow(2, exponent - 1) - 1));
    decimal /= 2;
    exponent++;
  }

  return binary;
}