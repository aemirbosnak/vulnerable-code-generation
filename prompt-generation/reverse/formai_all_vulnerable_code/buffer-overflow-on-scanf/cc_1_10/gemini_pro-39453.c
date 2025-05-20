//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
  int len = strlen(hex);
  int base = 1;
  int val = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      val += (hex[i] - '0') * base;
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      val += (hex[i] - 'a' + 10) * base;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      val += (hex[i] - 'A' + 10) * base;
    }
    base *= 16;
  }
  return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num) {
  char *hex = malloc(100);
  int i = 0;
  while (num != 0) {
    int temp = num % 16;
    if (temp < 10) {
      hex[i] = temp + '0';
    } else {
      hex[i] = temp + 'a' - 10;
    }
    num /= 16;
    i++;
  }
  hex[i] = '\0';
  return hex;
}

int main() {
  // Get the hexadecimal string from the user
  char hex[100];
  printf("Enter a hexadecimal string: ");
  scanf("%s", hex);

  // Convert the hexadecimal string to an integer
  int num = hex_to_int(hex);

  // Print the integer
  printf("The integer equivalent of the hexadecimal string is: %d\n", num);

  // Convert the integer back to a hexadecimal string
  char *hex2 = int_to_hex(num);

  // Print the hexadecimal string
  printf("The hexadecimal string equivalent of the integer is: %s\n", hex2);

  return 0;
}