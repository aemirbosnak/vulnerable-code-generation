//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUMBER_OF_BITS 32

// Function to convert binary to decimal
int binaryToDecimal(char binary[MAX_INPUT_SIZE]) {
  int decimal = 0;
  for (int i = 0; i < MAX_INPUT_SIZE; i++) {
    decimal = (decimal * 2) + (binary[i] - '0');
  }
  return decimal;
}

// Function to convert decimal to binary
char decimalToBinary(int decimal) {
  char binary[MAX_INPUT_SIZE];
  int i = 0;
  while (decimal != 0) {
    binary[i] = decimal % 2 + '0';
    decimal /= 2;
    i++;
  }
  return binary[i - 1];
}

int main() {
  // Ask user for input
  printf("Enter a binary number (up to 32 bits): ");
  char binary[MAX_INPUT_SIZE];
  fgets(binary, MAX_INPUT_SIZE, stdin);

  // Convert binary to decimal
  int decimal = binaryToDecimal(binary);

  // Print result
  printf("Decimal: %d\n", decimal);

  // Ask user for another input
  printf("Enter another binary number (up to 32 bits): ");
  fgets(binary, MAX_INPUT_SIZE, stdin);

  // Convert decimal to binary
  char binaryOutput[MAX_INPUT_SIZE];
  int i = 0;
  while (decimal != 0) {
    binaryOutput[i] = decimal % 2 + '0';
    decimal /= 2;
    i++;
  }
  binaryOutput[i - 1] = '\0';
  printf("Binary: %s\n", binaryOutput);

  return 0;
}