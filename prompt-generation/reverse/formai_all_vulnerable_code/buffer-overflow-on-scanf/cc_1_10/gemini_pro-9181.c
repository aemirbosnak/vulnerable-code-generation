//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: scientific
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
    // Multiply the base by 16
    base *= 16;
  }
  return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int val) {
  char *hex = malloc(sizeof(char) * 100);
  int i = 0;
  while (val > 0) {
    int digit = val % 16;
    if (digit < 10) {
      hex[i++] = digit + '0';
    } else {
      hex[i++] = digit - 10 + 'a';
    }
    val /= 16;
  }
  hex[i] = '\0';
  return hex;
}

// Main function
int main() {
  // Get the hexadecimal string from the user
  char hex[100];
  printf("Enter a hexadecimal string: ");
  scanf("%s", hex);

  // Convert the hexadecimal string to an integer
  int val = hex_to_int(hex);
  if (val == -1) {
    printf("Invalid hexadecimal string\n");
    return 1;
  }

  // Print the integer value
  printf("Integer value: %d\n", val);

  // Convert the integer back to a hexadecimal string
  char *hex2 = int_to_hex(val);
  printf("Hexadecimal string: %s\n", hex2);

  // Free the allocated memory
  free(hex2);

  return 0;
}