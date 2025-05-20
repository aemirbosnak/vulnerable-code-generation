//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bits in a binary number
#define MAX_BITS 64

// Define the base of the binary number
#define BASE 2

// Define the maximum number of digits in a decimal number
#define MAX_DIGITS 10

// Define the maximum number of characters in a string
#define MAX_STRING 100

// Prototype the functions
void convertBinaryToDecimal(char *binary, uint64_t *decimal);
void convertDecimalToBinary(uint64_t decimal, char *binary);

// Main function
int main() {
  // Declare the variables
  char binary[MAX_STRING];
  uint64_t decimal;

  // Get the binary number from the user
  printf("Enter a binary number: ");
  scanf("%s", binary);

  // Convert the binary number to a decimal number
  convertBinaryToDecimal(binary, &decimal);

  // Print the decimal number
  printf("The decimal number is: %llu\n", decimal);

  // Get the decimal number from the user
  printf("Enter a decimal number: ");
  scanf("%llu", &decimal);

  // Convert the decimal number to a binary number
  convertDecimalToBinary(decimal, binary);

  // Print the binary number
  printf("The binary number is: %s\n", binary);

  return 0;
}

// Function to convert a binary number to a decimal number
void convertBinaryToDecimal(char *binary, uint64_t *decimal) {
  // Declare the variables
  int i;
  uint64_t temp = 0;

  // Loop through the binary number
  for (i = strlen(binary) - 1; i >= 0; i--) {
    // If the bit is a 1, add the corresponding power of 2 to the decimal number
    if (binary[i] == '1') {
      temp += (1 << (strlen(binary) - i - 1));
    }
  }

  // Store the decimal number in the pointer variable
  *decimal = temp;
}

// Function to convert a decimal number to a binary number
void convertDecimalToBinary(uint64_t decimal, char *binary) {
  // Declare the variables
  int i;
  uint64_t temp = decimal;

  // Loop through the decimal number
  for (i = 0; i < MAX_BITS; i++) {
    // If the bit is a 1, set the corresponding bit in the binary number to 1
    if (temp & 1) {
      binary[i] = '1';
    } else {
      binary[i] = '0';
    }

    // Shift the decimal number right by 1 bit
    temp >>= 1;
  }

  // Null-terminate the binary number
  binary[i] = '\0';
}