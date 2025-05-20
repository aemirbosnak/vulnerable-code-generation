//Code Llama-13B DATASET v1.0 Category: Binary Converter ; Style: Sherlock Holmes
/*
 * A unique C Binary Converter example program in a Sherlock Holmes style
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int binary_to_decimal(char *binary) {
  int decimal = 0, i = 0;
  while (binary[i] != '\0') {
    decimal = decimal * 2 + binary[i] - '0';
    i++;
  }
  return decimal;
}

// Function to convert decimal to binary
char *decimal_to_binary(int decimal) {
  char *binary = (char *)malloc(sizeof(char) * 32);
  int i = 0;
  while (decimal > 0) {
    binary[i++] = decimal % 2 + '0';
    decimal /= 2;
  }
  binary[i] = '\0';
  return binary;
}

int main() {
  // Declare variables
  char binary[32];
  int decimal;

  // Prompt user for input
  printf("Enter a binary number: ");
  scanf("%s", binary);

  // Convert binary to decimal
  decimal = binary_to_decimal(binary);
  printf("The decimal equivalent of %s is %d\n", binary, decimal);

  // Convert decimal to binary
  char *binary_str = decimal_to_binary(decimal);
  printf("The binary equivalent of %d is %s\n", decimal, binary_str);

  // Free memory
  free(binary_str);

  return 0;
}