//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BINARY_CONVERTER_MAX_INPUT_SIZE 1024
#define BINARY_CONVERTER_MAX_OUTPUT_SIZE 1024

// Global variables
char binary_converter_input[BINARY_CONVERTER_MAX_INPUT_SIZE];
char binary_converter_output[BINARY_CONVERTER_MAX_OUTPUT_SIZE];
int binary_converter_input_length = 0;
int binary_converter_output_length = 0;

// Function to convert binary to decimal
int binary_to_decimal(char binary_number[]) {
  int decimal_number = 0;
  for (int i = 0; i < strlen(binary_number); i++) {
    decimal_number *= 2;
    if (binary_number[i] == '1') {
      decimal_number += 1;
    }
  }
  return decimal_number;
}

// Function to convert decimal to binary
int decimal_to_binary(int decimal_number) {
  char binary_number[BINARY_CONVERTER_MAX_OUTPUT_SIZE];
  int i = 0;
  while (decimal_number != 0) {
    binary_number[i] = decimal_number % 2 == 0 ? '0' : '1';
    decimal_number /= 2;
    i++;
  }
  return binary_number;
}

int main() {
  // Prompt user for input
  printf("Enter a binary number (max %d characters): ", BINARY_CONVERTER_MAX_INPUT_SIZE);
  fgets(binary_converter_input, BINARY_CONVERTER_MAX_INPUT_SIZE, stdin);

  // Convert binary to decimal
  int decimal_number = binary_to_decimal(binary_converter_input);

  // Prompt user for output format (decimal or binary)
  printf("Enter the output format (d for decimal or b for binary): ");
  char output_format;
  scanf("%c", &output_format);

  // Convert decimal to binary (if necessary)
  if (output_format == 'd') {
    decimal_to_binary(decimal_number);
  }

  // Print output
  printf("%s\n", binary_converter_output);

  return 0;
}