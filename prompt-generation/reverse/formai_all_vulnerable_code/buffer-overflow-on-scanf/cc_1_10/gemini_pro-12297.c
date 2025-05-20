//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int val = 0;

  for (int i = len - 1; i >= 0; i--) {
    // Get the digit value
    int digit;
    if (hex[i] >= '0' && hex[i] <= '9') {
      digit = hex[i] - '0';
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      digit = hex[i] - 'a' + 10;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      digit = hex[i] - 'A' + 10;
    } else {
      fprintf(stderr, "Invalid hexadecimal digit: %c\n", hex[i]);
      exit(EXIT_FAILURE);
    }

    // Add the digit value to the result
    val += digit * base;
    base *= 16;
  }

  return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num) {
  char *hex = malloc(sizeof(char) * 100);
  int i = 0;

  while (num != 0) {
    int digit = num % 16;
    if (digit < 10) {
      hex[i++] = digit + '0';
    } else {
      hex[i++] = digit - 10 + 'A';
    }
    num /= 16;
  }

  hex[i] = '\0';

  // Reverse the hexadecimal string
  int len = strlen(hex);
  for (int j = 0; j < len / 2; j++) {
    char temp = hex[j];
    hex[j] = hex[len - j - 1];
    hex[len - j - 1] = temp;
  }

  return hex;
}

// Main function
int main() {
  // Get the hexadecimal string from the user
  char hex[100];
  printf("Enter a hexadecimal string: ");
  scanf("%s", hex);

  // Convert the hexadecimal string to an integer
  int num = hex_to_int(hex);

  // Print the integer
  printf("The integer value of the hexadecimal string is: %d\n", num);

  // Convert the integer to a hexadecimal string
  char *new_hex = int_to_hex(num);

  // Print the hexadecimal string
  printf("The hexadecimal string of the integer is: %s\n", new_hex);

  return 0;
}