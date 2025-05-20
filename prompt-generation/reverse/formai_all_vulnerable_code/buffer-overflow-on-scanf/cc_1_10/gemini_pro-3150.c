//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input hexadecimal string
#define MAX_HEX_LENGTH 100

// Define the conversion table for hexadecimal digits
char hex_digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// Function to convert a hexadecimal digit to its corresponding decimal value
int hex_to_dec(char hex_digit) {
  int dec_value = -1;

  // Check if the hexadecimal digit is valid
  for (int i = 0; i < 16; i++) {
    if (hex_digit == hex_digits[i]) {
      dec_value = i;
      break;
    }
  }

  return dec_value;
}

// Function to convert a hexadecimal string to its corresponding decimal value
int hex_to_dec_string(char *hex_string) {
  int dec_value = 0;
  int hex_length = strlen(hex_string);

  // Iterate over the hexadecimal string from right to left
  for (int i = 0; i < hex_length; i++) {
    // Convert the current hexadecimal digit to its corresponding decimal value
    int dec_digit = hex_to_dec(hex_string[i]);

    // Multiply the decimal value by the appropriate power of 16
    dec_digit *= (1 << (4 * (hex_length - i - 1)));

    // Add the decimal value to the total decimal value
    dec_value += dec_digit;
  }

  return dec_value;
}

int main() {
  // Get the hexadecimal string from the user
  char hex_string[MAX_HEX_LENGTH + 1];
  printf("Enter a hexadecimal string: ");
  scanf("%s", hex_string);

  // Convert the hexadecimal string to its corresponding decimal value
  int dec_value = hex_to_dec_string(hex_string);

  // Print the decimal value
  printf("The decimal value of the hexadecimal string %s is %d\n", hex_string, dec_value);

  return 0;
}