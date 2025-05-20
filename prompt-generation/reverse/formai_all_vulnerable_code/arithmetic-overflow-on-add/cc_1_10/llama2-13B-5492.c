//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the number of bits in each binary digit
#define BITS_PER_DIGIT 4

// Define the maximum number of digits in a binary number
#define MAX_DIGITS 16

// Define a function to convert a binary number to decimal
int binary_to_decimal(int binary[MAX_DIGITS]) {
  int result = 0;
  for (int i = 0; i < MAX_DIGITS; i++) {
    result *= 2;
    result += binary[i];
  }
  return result;
}

// Define a function to convert a decimal number to binary
int decimal_to_binary(int decimal) {
  int binary[MAX_DIGITS];
  int i = 0;
  while (decimal != 0) {
    binary[i] = decimal % 2;
    decimal /= 2;
    i++;
  }
  return binary[i-1];
}

int main() {
  // Test cases
  int test_cases[] = {
    10, // Decimal
    10101, // Binary
    36, // Decimal
    110010, // Binary
    13, // Decimal
    1001101, // Binary
  };

  int i;
  for (i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
    int decimal = test_cases[i];
    int binary = decimal_to_binary(decimal);
    printf("%d (%d binary digits): %d\n", decimal, i, binary);

    // Convert binary to decimal
    int decimal_result = binary_to_decimal(binary);
    printf("%d (%d binary digits): %d\n", decimal_result, i, decimal);

    // Check for errors
    if (decimal_result != decimal) {
      printf("Error: %d does not equal %d\n", decimal_result, decimal);
    }
  }

  return 0;
}