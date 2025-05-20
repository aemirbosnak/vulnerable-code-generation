//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void convert_binary_to_decimal(char *binary_string, int *decimal_number) {
  int length = strlen(binary_string);
  *decimal_number = 0;
  for (int i = 0; i < length; i++) {
    if (binary_string[i] == '1') {
      *decimal_number += (1 << (length - i - 1));
    }
  }
}

void convert_decimal_to_binary(int decimal_number, char *binary_string, int length) {
  for (int i = length - 1; i >= 0; i--) {
    if (decimal_number & 1) {
      binary_string[i] = '1';
    } else {
      binary_string[i] = '0';
    }
    decimal_number >>= 1;
  }
}

int main() {
  printf("Welcome to the binary converter!\n");
  printf("Please enter a number in binary or decimal format: ");
  char input[MAX_INPUT_LENGTH];
  fgets(input, MAX_INPUT_LENGTH, stdin);

  int number;
  char binary_string[MAX_INPUT_LENGTH];

  if (input[strlen(input) - 1] == '\n') {
    input[strlen(input) - 1] = '\0';
  }

  if (strchr(input, '.') != NULL) {
    printf("Error: Invalid input. Please enter a whole number.\n");
    return 1;
  }

  if (input[0] == '0' && input[1] == 'b') {
    // Binary to decimal
    convert_binary_to_decimal(input + 2, &number);
  } else {
    // Decimal to binary
    number = atoi(input);
    int length = strlen(input) * 4;
    convert_decimal_to_binary(number, binary_string, length);
    printf("Binary: %s\n", binary_string);
  }

  printf("Decimal: %d\n", number);

  return 0;
}