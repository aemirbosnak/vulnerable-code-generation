//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 100
#define MAX_NUMBER_OF_CONVERTIONS 10

int main() {
  int i, j, num_conversions = 0;
  char input_string[MAX_INPUT_SIZE];
  char output_string[MAX_INPUT_SIZE];
  long long int input_number = 0;
  double output_number = 0.0;

  // Initialize input and output strings
  printf("Welcome to the Happy Binary Converter! Please enter a number or a string to convert:\n");
  fgets(input_string, MAX_INPUT_SIZE, stdin);

  // Convert string to integer
  if (sscanf(input_string, "%lld", &input_number) == 1) {
    // Convert integer to binary
    char binary[MAX_INPUT_SIZE];
    sprintf(binary, "%lld", input_number);
    printf("Here's the binary representation of %lld: %s\n", input_number, binary);

    // Convert integer to hexadecimal
    char hex[MAX_INPUT_SIZE];
    sprintf(hex, "%016llx", input_number);
    printf("Here's the hexadecimal representation of %lld: %s\n", input_number, hex);

    // Convert integer to octal
    char octal[MAX_INPUT_SIZE];
    sprintf(octal, "%016llu", input_number);
    printf("Here's the octal representation of %lld: %s\n", input_number, octal);

    // Increment number of conversions
    num_conversions++;
  }

  // Convert string to floating-point number
  else if (sscanf(input_string, "%f", &output_number) == 1) {
    // Convert floating-point number to binary
    char binary_string[MAX_INPUT_SIZE];
    sprintf(binary_string, "%.16g", output_number);
    printf("Here's the binary representation of %f: %s\n", output_number, binary_string);

    // Convert floating-point number to hexadecimal
    char hex_string[MAX_INPUT_SIZE];
    sprintf(hex_string, "%.16g", output_number);
    printf("Here's the hexadecimal representation of %f: %s\n", output_number, hex_string);

    // Convert floating-point number to octal
    char octal_string[MAX_INPUT_SIZE];
    sprintf(octal_string, "%.16g", output_number);
    printf("Here's the octal representation of %f: %s\n", output_number, octal_string);

    // Increment number of conversions
    num_conversions++;
  }

  // Display number of conversions
  printf("Total number of conversions: %d\n", num_conversions);

  return 0;
}