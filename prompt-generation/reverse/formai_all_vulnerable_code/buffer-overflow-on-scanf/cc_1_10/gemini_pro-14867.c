//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string.
#define MAX_INPUT_LENGTH 100

// Define the conversion table for hexadecimal digits.
const char *hex_digits = "0123456789ABCDEF";

// Convert a hexadecimal digit to its decimal equivalent.
int hex_digit_to_decimal(char digit) {
  // Check if the digit is valid.
  if (digit < '0' || digit > 'F') {
    return -1;
  }

  // Convert the digit to its decimal equivalent.
  if (digit <= '9') {
    return digit - '0';
  } else {
    return digit - 'A' + 10;
  }
}

// Convert a hexadecimal string to its decimal equivalent.
int hex_string_to_decimal(const char *hex_string) {
  // Check if the string is empty.
  if (strlen(hex_string) == 0) {
    return 0;
  }

  // Convert the first digit of the string to its decimal equivalent.
  int decimal_value = hex_digit_to_decimal(hex_string[0]);

  // Check if the digit is valid.
  if (decimal_value == -1) {
    return -1;
  }

  // Convert the remaining digits of the string to their decimal equivalents and add them to the total.
  for (int i = 1; i < strlen(hex_string); i++) {
    decimal_value = decimal_value * 16 + hex_digit_to_decimal(hex_string[i]);
  }

  // Return the total decimal value.
  return decimal_value;
}

// Convert a decimal number to its hexadecimal equivalent.
char *decimal_to_hex_string(int decimal_number) {
  // Check if the number is negative.
  if (decimal_number < 0) {
    return NULL;
  }

  // Allocate memory for the hexadecimal string.
  char *hex_string = malloc(sizeof(char) * 100);

  // Convert the number to its hexadecimal equivalent.
  int quotient = decimal_number;
  int remainder;
  int i = 0;
  while (quotient != 0) {
    remainder = quotient % 16;
    hex_string[i++] = hex_digits[remainder];
    quotient /= 16;
  }

  // Reverse the hexadecimal string.
  for (int j = 0; j < i / 2; j++) {
    char temp = hex_string[j];
    hex_string[j] = hex_string[i - j - 1];
    hex_string[i - j - 1] = temp;
  }

  // Terminate the hexadecimal string with a null character.
  hex_string[i] = '\0';

  // Return the hexadecimal string.
  return hex_string;
}

// Get the hexadecimal representation of a number from the user.
char *get_hex_string_from_user() {
  // Allocate memory for the hexadecimal string.
  char *hex_string = malloc(sizeof(char) * MAX_INPUT_LENGTH);

  // Get the hexadecimal string from the user.
  printf("Enter a hexadecimal number: ");
  scanf("%s", hex_string);

  // Return the hexadecimal string.
  return hex_string;
}

// Get the decimal representation of a number from the user.
int get_decimal_number_from_user() {
  // Get the decimal number from the user.
  int decimal_number;
  printf("Enter a decimal number: ");
  scanf("%d", &decimal_number);

  // Return the decimal number.
  return decimal_number;
}

// Print the hexadecimal representation of a number.
void print_hex_string(const char *hex_string) {
  // Print the hexadecimal string.
  printf("Hexadecimal representation: %s\n", hex_string);
}

// Print the decimal representation of a number.
void print_decimal_number(int decimal_number) {
  // Print the decimal number.
  printf("Decimal representation: %d\n", decimal_number);
}

// Main function.
int main() {
  // Get the hexadecimal string from the user.
  char *hex_string = get_hex_string_from_user();

  // Convert the hexadecimal string to its decimal equivalent.
  int decimal_number = hex_string_to_decimal(hex_string);

  // Print the hexadecimal and decimal representations of the number.
  print_hex_string(hex_string);
  print_decimal_number(decimal_number);

  // Get the decimal number from the user.
  decimal_number = get_decimal_number_from_user();

  // Convert the decimal number to its hexadecimal equivalent.
  hex_string = decimal_to_hex_string(decimal_number);

  // Print the hexadecimal and decimal representations of the number.
  print_hex_string(hex_string);
  print_decimal_number(decimal_number);

  // Free the allocated memory.
  free(hex_string);

  return 0;
}