//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_STRING_LENGTH 100

// Define the base of the input string
#define INPUT_BASE 16

// Define the base of the output string
#define OUTPUT_BASE 10

// Define the maximum number of digits in the output string
#define MAX_DIGITS 100

// Declare the input string
char inputString[MAX_STRING_LENGTH];

// Declare the output string
char outputString[MAX_DIGITS];

// Declare the length of the input string
int inputStringLength;

// Declare the length of the output string
int outputStringLength;

// Declare the value of the input string
int inputValue;

// Declare the value of the output string
int outputValue;

// Declare the function to convert a hexadecimal string to an integer
int hexToInt(char *inputString, int inputStringLength) {
  int value = 0;

  for (int i = 0; i < inputStringLength; i++) {
    char c = inputString[i];

    if (c >= '0' && c <= '9') {
      value = value * INPUT_BASE + (c - '0');
    } else if (c >= 'A' && c <= 'F') {
      value = value * INPUT_BASE + (c - 'A' + 10);
    } else if (c >= 'a' && c <= 'f') {
      value = value * INPUT_BASE + (c - 'a' + 10);
    }
  }

  return value;
}

// Declare the function to convert an integer to a decimal string
char *intToDec(int inputValue, char *outputString, int outputStringLength) {
  int i = outputStringLength - 1;

  while (inputValue > 0) {
    int digit = inputValue % OUTPUT_BASE;

    if (digit >= 0 && digit <= 9) {
      outputString[i] = digit + '0';
    } else if (digit >= 10 && digit <= 15) {
      outputString[i] = digit + 'A' - 10;
    }

    inputValue /= OUTPUT_BASE;
    i--;
  }

  return outputString;
}

// Declare the main function
int main() {
  // Get the input string from the user
  printf("Enter a hexadecimal string: ");
  scanf("%s", inputString);

  // Get the length of the input string
  inputStringLength = strlen(inputString);

  // Convert the input string to an integer
  inputValue = hexToInt(inputString, inputStringLength);

  // Convert the integer to a decimal string
  outputValue = intToDec(inputValue, outputString, MAX_DIGITS);

  // Print the output string
  printf("The decimal value is: %s\n", outputString);

  return 0;
}