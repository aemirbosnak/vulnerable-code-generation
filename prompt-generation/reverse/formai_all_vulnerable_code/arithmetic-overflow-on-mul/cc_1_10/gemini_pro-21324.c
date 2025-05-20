//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
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
      return -1;  // Invalid hexadecimal digit
    }

    // Add the digit value to the result
    val += digit * base;
    base *= 16;
  }
  return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num) {
  char *hex = malloc(11);  // Allocate enough space for 10 digits plus the null terminator
  int i = 0;
  while (num > 0) {
    // Get the remainder of the division by 16
    int remainder = num % 16;

    // Convert the remainder to a hexadecimal digit
    char digit;
    if (remainder >= 0 && remainder <= 9) {
      digit = remainder + '0';
    } else if (remainder >= 10 && remainder <= 15) {
      digit = remainder - 10 + 'a';
    } else {
      return NULL;  // Invalid integer value
    }

    // Store the digit in the hexadecimal string
    hex[i++] = digit;

    // Divide the number by 16
    num /= 16;
  }

  // Reverse the hexadecimal string
  for (int j = 0; j < i / 2; j++) {
    char temp = hex[j];
    hex[j] = hex[i - j - 1];
    hex[i - j - 1] = temp;
  }

  // Add the null terminator
  hex[i] = '\0';

  return hex;
}

int main() {
  // Test the hex_to_int function
  char *hex1 = "1234567890abcdef";
  int num1 = hex_to_int(hex1);
  printf("Hexadecimal: %s\n", hex1);
  printf("Integer: %d\n\n", num1);

  // Test the int_to_hex function
  int num2 = 1234567890;
  char *hex2 = int_to_hex(num2);
  printf("Integer: %d\n", num2);
  printf("Hexadecimal: %s\n", hex2);

  return 0;
}