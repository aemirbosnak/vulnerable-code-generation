//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters in a hexadecimal string.
#define MAX_HEX_STRING_LENGTH 100

// Define the hexadecimal digits.
char hex_digits[] = "0123456789ABCDEF";

// Function to convert a hexadecimal string to an integer.
int hex_to_int(char *hex_string) {
  // Check if the hexadecimal string is valid.
  if (strlen(hex_string) > MAX_HEX_STRING_LENGTH) {
    printf("Error: The hexadecimal string is too long.\n");
    return -1;
  }

  // Initialize the integer value.
  int int_value = 0;

  // Convert each character in the hexadecimal string to an integer.
  for (int i = 0; i < strlen(hex_string); i++) {
    // Get the character at the current index.
    char character = hex_string[i];

    // Find the index of the character in the hexadecimal digits array.
    int index = 0;
    while (index < 16 && character != hex_digits[index]) {
      index++;
    }

    // If the character is not found in the hexadecimal digits array, then it is
    // not a valid hexadecimal character.
    if (index == 16) {
      printf("Error: The hexadecimal string contains an invalid character.\n");
      return -1;
    }

    // Add the value of the character to the integer value.
    int_value += index * pow(16, strlen(hex_string) - i - 1);
  }

  // Return the integer value.
  return int_value;
}

// Function to convert an integer to a hexadecimal string.
char *int_to_hex(int int_value) {
  // Initialize the hexadecimal string.
  char *hex_string = malloc(MAX_HEX_STRING_LENGTH + 1);

  // Convert the integer value to a hexadecimal string.
  int i = 0;
  while (int_value > 0) {
    // Get the remainder of the integer value when divided by 16.
    int remainder = int_value % 16;

    // Add the hexadecimal digit corresponding to the remainder to the
    // hexadecimal string.
    hex_string[i++] = hex_digits[remainder];

    // Divide the integer value by 16.
    int_value /= 16;
  }

  // Reverse the hexadecimal string.
  for (int j = 0; j < i / 2; j++) {
    char temp = hex_string[j];
    hex_string[j] = hex_string[i - j - 1];
    hex_string[i - j - 1] = temp;
  }

  // Add the null terminator to the hexadecimal string.
  hex_string[i] = '\0';

  // Return the hexadecimal string.
  return hex_string;
}

// Main function.
int main() {
  // Get the hexadecimal string from the user.
  char hex_string[MAX_HEX_STRING_LENGTH + 1];
  printf("Enter a hexadecimal string: ");
  scanf("%s", hex_string);

  // Convert the hexadecimal string to an integer.
  int int_value = hex_to_int(hex_string);

  // Print the integer value.
  printf("The integer value of the hexadecimal string is: %d\n", int_value);

  // Convert the integer value to a hexadecimal string.
  char *new_hex_string = int_to_hex(int_value);

  // Print the hexadecimal string.
  printf("The hexadecimal string of the integer value is: %s\n", new_hex_string);

  // Free the memory allocated for the hexadecimal string.
  free(new_hex_string);

  return 0;
}