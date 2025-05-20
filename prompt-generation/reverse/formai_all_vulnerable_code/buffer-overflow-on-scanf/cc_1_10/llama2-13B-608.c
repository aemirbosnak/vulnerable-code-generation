//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DIGITS 100
#define BINARY_PREFIX "0b"

// Function to convert a decimal number to binary
void decimalToBinary(int decimal) {
  int i, binary[MAX_DIGITS];
  char buffer[MAX_DIGITS];

  // Initialize binary array with 0s
  for (i = 0; i < MAX_DIGITS; i++) {
    binary[i] = 0;
  }

  // Loop until the decimal number is 0
  while (decimal > 0) {
    // Divide the decimal number by 2
    int quotient = decimal / 2;

    // Store the remainder in the binary array
    binary[i] = (decimal - quotient * 2) % 2;

    // Shift the binary array left
    for (i = 0; i < MAX_DIGITS - 1; i++) {
      binary[i + 1] = binary[i];
    }

    // Update the decimal number
    decimal = quotient;

    // Check if the decimal number is 0
    if (decimal == 0) {
      break;
    }
  }

  // Reverse the binary array
  for (i = 0; i < MAX_DIGITS / 2; i++) {
    int temp = binary[i];
    binary[i] = binary[MAX_DIGITS - i - 1];
    binary[MAX_DIGITS - i - 1] = temp;
  }

  // Print the binary representation
  for (i = 0; i < MAX_DIGITS; i++) {
    printf("%c", BINARY_PREFIX[binary[i]]);
  }
}

int main() {
  int decimal;

  // Get the decimal number from the user
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  // Convert the decimal number to binary
  decimalToBinary(decimal);

  return 0;
}