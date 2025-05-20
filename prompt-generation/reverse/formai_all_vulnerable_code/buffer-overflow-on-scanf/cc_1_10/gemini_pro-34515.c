//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <string.h>

// Define the hexadecimal digits
char hex_digits[] = "0123456789ABCDEF";

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int value = 0;
  for (int i = 0; i < len; i++) {
    char c = hex[i];
    int digit = -1;
    for (int j = 0; j < 16; j++) {
      if (c == hex_digits[j]) {
        digit = j;
        break;
      }
    }
    if (digit == -1) {
      // Invalid hexadecimal character
      return -1;
    }
    value = value * 16 + digit;
  }
  return value;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int value) {
  char *hex = malloc(10);
  int i = 0;
  while (value > 0) {
    int digit = value % 16;
    hex[i++] = hex_digits[digit];
    value /= 16;
  }
  hex[i] = '\0';
  return hex;
}

int main() {
  // Get the input hexadecimal string
  char hex[100];
  printf("Enter a hexadecimal string: ");
  scanf("%s", hex);

  // Convert the hexadecimal string to an integer
  int value = hex_to_int(hex);
  if (value == -1) {
    printf("Invalid hexadecimal string\n");
    return 1;
  }

  // Print the integer
  printf("The integer value is: %d\n", value);

  // Convert the integer to a hexadecimal string
  char *new_hex = int_to_hex(value);

  // Print the hexadecimal string
  printf("The hexadecimal string is: %s\n", new_hex);

  // Free the memory allocated for the new hexadecimal string
  free(new_hex);

  return 0;
}