//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INPUT_LEN 1024
#define MAX_OUTPUT_LEN 2048

// Function to convert binary to decimal
int binaryToDecimal(char binary[], int len) {
  int i, sum = 0;
  for (i = 0; i < len; i++) {
    sum += (binary[i] - '0') * pow(2, len - i - 1);
  }
  return sum;
}

// Function to convert decimal to binary
int decimalToBinary(int decimal) {
  int i, binary[MAX_INPUT_LEN];
  for (i = 0; decimal != 0; i++) {
    binary[i] = decimal % 2 + '0';
    decimal /= 2;
  }
  return binary[i];
}

int main() {
  char binaryInput[MAX_INPUT_LEN];
  int decimalInput, decimalOutput;
  int len = 0;

  // Get the input binary string from the user
  printf("Enter a binary string: ");
  fgets(binaryInput, MAX_INPUT_LEN, stdin);
  len = strlen(binaryInput);

  // Convert the binary string to decimal
  decimalInput = binaryToDecimal(binaryInput, len);

  // Print the decimal value
  printf("Decimal value: %d\n", decimalInput);

  // Get the output decimal value from the user
  printf("Enter a decimal value to convert back to binary: ");
  scanf("%d", &decimalOutput);

  // Convert the decimal value back to binary
  char binaryOutput[MAX_OUTPUT_LEN];
  binaryOutput[0] = decimalToBinary(decimalOutput);
  len = strlen(binaryOutput);
  printf("Binary value: %s\n", binaryOutput);

  // Get the input binary string again and convert it to decimal
  printf("Enter another binary string to convert: ");
  fgets(binaryInput, MAX_INPUT_LEN, stdin);
  len = strlen(binaryInput);
  decimalInput = binaryToDecimal(binaryInput, len);
  printf("Decimal value: %d\n", decimalInput);

  // Keep asking for input and converting until the user enters "quit"
  while (strcmp(binaryInput, "quit") != 0) {
    printf("Enter another binary string to convert: ");
    fgets(binaryInput, MAX_INPUT_LEN, stdin);
    len = strlen(binaryInput);
    decimalInput = binaryToDecimal(binaryInput, len);
    printf("Decimal value: %d\n", decimalInput);
  }

  return 0;
}