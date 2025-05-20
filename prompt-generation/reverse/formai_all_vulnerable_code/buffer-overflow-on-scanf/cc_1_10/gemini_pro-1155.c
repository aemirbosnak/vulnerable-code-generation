//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char * decToBinary(int n) {
  // Check if the number is negative
  if (n < 0) {
    printf("Error: The number must be non-negative.\n");
    return NULL;
  }

  // Create a string to store the binary representation
  char * binary = malloc(33);

  // Initialize the string to all 0s
  for (int i = 0; i < 32; i++) {
    binary[i] = '0';
  }

  // Convert the number to binary by repeatedly dividing by 2
  int i = 31;
  while (n > 0) {
    binary[i--] = (n % 2) + '0';
    n /= 2;
  }

  // Add the null terminator to the end of the string
  binary[32] = '\0';

  // Return the binary representation
  return binary;
}

// Function to convert a binary number to decimal
int binaryToDec(char * binary) {
  // Check if the string is valid
  if (binary == NULL || strlen(binary) > 32) {
    printf("Error: Invalid binary string.\n");
    return -1;
  }

  // Convert the binary number to decimal by multiplying each bit by 2^n
  int decimal = 0;
  for (int i = 0; i < 32; i++) {
    if (binary[i] == '1') {
      decimal += 1 << (31 - i);
    }
  }

  // Return the decimal representation
  return decimal;
}

int main() {
  // Get the number to convert from the user
  int number;
  printf("Enter a decimal number: ");
  scanf("%d", &number);

  // Convert the number to binary
  char * binary = decToBinary(number);

  // Print the binary representation
  printf("Binary representation: %s\n", binary);

  // Convert the binary number back to decimal
  int decimal = binaryToDec(binary);

  // Print the decimal representation
  printf("Decimal representation: %d\n", decimal);

  // Free the memory allocated for the binary string
  free(binary);

  return 0;
}