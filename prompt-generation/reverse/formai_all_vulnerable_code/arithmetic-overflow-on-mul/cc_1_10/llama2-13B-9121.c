//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_PER_BYTE 8
#define BYTES_PER_INT 4

// Function to convert a binary number to decimal
int binary_to_decimal(int num) {
  int result = 0;
  while (num != 0) {
    result = (result * 2) + (num % 2);
    num /= 2;
  }
  return result;
}

// Function to convert a decimal number to binary
int decimal_to_binary(int num) {
  int result = 0;
  while (num != 0) {
    result = (result * 2) + (num % 2);
    num /= 2;
  }
  return result;
}

// Function to convert a binary number to hexadecimal
int binary_to_hex(int num) {
  int result = 0;
  while (num != 0) {
    result = (result * 16) + (num % 2);
    num /= 2;
  }
  return result;
}

// Function to convert a hexadecimal number to binary
int hex_to_binary(int num) {
  int result = 0;
  while (num != 0) {
    result = (result * 2) + (num % 16);
    num /= 16;
  }
  return result;
}

int main() {
  int num1, num2, result;

  // Example 1: Convert 123 to decimal
  num1 = 1111011; // 123 in binary
  result = binary_to_decimal(num1);
  printf("123 in decimal is %d\n", result);

  // Example 2: Convert 456 to hexadecimal
  num2 = 110010010; // 456 in binary
  result = binary_to_hex(num2);
  printf("456 in hexadecimal is %x\n", result);

  // Example 3: Convert 255 to binary
  num1 = 255;
  result = decimal_to_binary(num1);
  printf("255 in binary is %d\n", result);

  // Example 4: Convert 0xFF to binary
  num2 = 0xFF;
  result = hex_to_binary(num2);
  printf("0xFF in binary is %d\n", result);

  return 0;
}