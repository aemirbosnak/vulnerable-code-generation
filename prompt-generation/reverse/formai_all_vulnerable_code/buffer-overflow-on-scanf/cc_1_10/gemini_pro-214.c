//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>
#include <string.h>

// Function to convert a hexadecimal number to its decimal equivalent
int hex_to_decimal(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int decimal = 0;

  // Iterate through the hexadecimal number from right to left
  for (int i = len - 1; i >= 0; i--) {
    // Get the digit value of the current character
    int digit;
    if (hex[i] >= '0' && hex[i] <= '9') {
      digit = hex[i] - '0';
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      digit = hex[i] - 'A' + 10;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      digit = hex[i] - 'a' + 10;
    } else {
      // Invalid character encountered
      return -1;
    }

    // Add the digit value to the decimal result, weighted by the appropriate power of 16
    decimal += digit * base;
    base *= 16;
  }

  return decimal;
}

// Function to convert a decimal number to its hexadecimal equivalent
char *decimal_to_hex(int decimal) {
  // Allocate a buffer to store the hexadecimal result
  char *hex = malloc(11);
  int i = 0;

  // Iterate through the decimal number, dividing by 16 until the quotient is 0
  while (decimal > 0) {
    // Get the remainder of the division by 16
    int remainder = decimal % 16;

    // Convert the remainder to a hexadecimal digit
    char digit;
    if (remainder >= 0 && remainder <= 9) {
      digit = '0' + remainder;
    } else {
      digit = 'A' + remainder - 10;
    }

    // Store the digit in the hexadecimal result
    hex[i++] = digit;

    // Divide the decimal number by 16
    decimal /= 16;
  }

  // Terminate the hexadecimal result with a null character
  hex[i] = '\0';

  // Reverse the hexadecimal result, since we stored the digits in reverse order
  char *reversed_hex = malloc(strlen(hex) + 1);
  for (int j = 0; j < strlen(hex); j++) {
    reversed_hex[j] = hex[strlen(hex) - j - 1];
  }
  reversed_hex[strlen(hex)] = '\0';

  // Free the original hexadecimal result
  free(hex);

  // Return the reversed hexadecimal result
  return reversed_hex;
}

int main() {
  // Declare variables
  char hex_input[100];
  int decimal_input;
  int choice;

  // Display menu options
  printf("\n1. Convert Hexadecimal to Decimal\n");
  printf("2. Convert Decimal to Hexadecimal\n");
  printf("3. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Loop until the user chooses to exit
  while (choice != 3) {
    switch (choice) {
      case 1:
        // Convert hexadecimal to decimal
        printf("Enter the hexadecimal number: ");
        scanf("%s", hex_input);
        int decimal_result = hex_to_decimal(hex_input);
        if (decimal_result == -1) {
          printf("Invalid hexadecimal number.\n");
        } else {
          printf("The decimal equivalent is: %d\n", decimal_result);
        }
        break;
      case 2:
        // Convert decimal to hexadecimal
        printf("Enter the decimal number: ");
        scanf("%d", &decimal_input);
        char *hex_result = decimal_to_hex(decimal_input);
        printf("The hexadecimal equivalent is: %s\n", hex_result);
        free(hex_result);
        break;
      case 3:
        // Exit the program
        printf("Thank you for using the hexadecimal converter. Goodbye!\n");
        break;
      default:
        // Handle invalid input
        printf("Invalid choice. Please enter a number between 1 and 3.\n");
        break;
    }

    // Display menu options again
    printf("\n1. Convert Hexadecimal to Decimal\n");
    printf("2. Convert Decimal to Hexadecimal\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
  }

  return 0;
}