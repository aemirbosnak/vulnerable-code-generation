//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>

// Define the base-10 and base-2 conversions
void convert_to_binary(int num) {
  // The accumulator for the binary representation
  int bin = 0;

  // Iterate over the digits of the base-10 number
  for (int i = 0; i < 10; i++) {
    // Get the digit of the base-10 number
    int digit = num / (int)pow(10, i);

    // Add the digit to the binary representation
    bin = (bin * 2) + digit;
  }

  // Print the binary representation
  printf("%s\n", bin);
}

void convert_from_binary(int num) {
  // The accumulator for the base-10 representation
  int dec = 0;

  // Iterate over the digits of the base-2 number
  for (int i = 0; i < 2; i++) {
    // Get the digit of the base-2 number
    int digit = num % 2;

    // Add the digit to the base-10 representation
    dec = (dec * 10) + digit;
    num /= 2;
  }

  // Print the base-10 representation
  printf("%d\n", dec);
}

int main() {
  // Convert 123 to binary
  convert_to_binary(123);

  // Convert 111010 to binary
  convert_to_binary(111010);

  // Convert 23 to decimal
  convert_from_binary(10101);

  // Convert 101010 to decimal
  convert_from_binary(101010);

  return 0;
}