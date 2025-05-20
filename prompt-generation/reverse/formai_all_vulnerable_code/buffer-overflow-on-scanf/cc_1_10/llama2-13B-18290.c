//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BINARY_DIGITS 8
#define BINARY_BASE 2

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
  int i = 0, j = 0;
  char binary[BINARY_DIGITS];

  // Initialize binary with 0s
  for (i = 0; i < BINARY_DIGITS; i++) {
    binary[i] = '0';
  }

  // Iterate through the decimal number
  while (decimal != 0) {
    // Get the remainder of the division
    int remainder = decimal % BINARY_BASE;

    // Add the remainder to the binary
    binary[j] = remainder + '0';

    // Increment the position of the remainder
    j++;

    // Update the decimal number
    decimal /= BINARY_BASE;
  }

  // Reverse the binary
  for (i = 0; i < j; i++) {
    char temp = binary[i];
    binary[i] = binary[j - 1];
    binary[j - 1] = temp;
  }

  // Print the binary
  for (i = 0; i < j; i++) {
    printf("%c", binary[i]);
  }
}

int main() {
  int decimal;

  // Get the decimal number from the user
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  // Convert the decimal to binary
  decimalToBinary(decimal);

  return 0;
}