//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BIT_STRING_SIZE 64

// Convert a decimal number to its binary representation.
void decimal_to_binary(int decimal, char *binary) {
  int quotient = decimal;
  int remainder;
  int i = 0;

  while (quotient != 0) {
    remainder = quotient % 2;
    binary[i++] = remainder + '0';
    quotient /= 2;
  }

  // Pad the binary string with leading zeros.
  while (i < BIT_STRING_SIZE) {
    binary[i++] = '0';
  }

  // Reverse the binary string.
  for (int j = 0; j < BIT_STRING_SIZE / 2; j++) {
    char temp = binary[j];
    binary[j] = binary[BIT_STRING_SIZE - j - 1];
    binary[BIT_STRING_SIZE - j - 1] = temp;
  }
}

// Convert a binary number to its decimal representation.
int binary_to_decimal(char *binary) {
  int decimal = 0;
  int i;

  for (i = 0; i < BIT_STRING_SIZE; i++) {
    decimal += (binary[i] - '0') * pow(2, BIT_STRING_SIZE - i - 1);
  }

  return decimal;
}

int main() {
  // Declare the input and output strings.
  char decimal_string[128];
  char binary_string[BIT_STRING_SIZE + 1];

  // Get the decimal number from the user.
  printf("Enter a decimal number: ");
  scanf("%s", decimal_string);

  // Convert the decimal number to binary.
  decimal_to_binary(atoi(decimal_string), binary_string);

  // Print the binary representation.
  printf("Binary representation: %s\n", binary_string);

  // Convert the binary number to decimal.
  int decimal_number = binary_to_decimal(binary_string);

  // Print the decimal representation.
  printf("Decimal representation: %d\n", decimal_number);

  return 0;
}