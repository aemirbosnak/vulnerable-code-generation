//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros for the binary digits
#define ZERO 0
#define ONE 1

// Function to convert a decimal number to binary
char* decToBin(int dec) {
  // Allocate memory for the binary string
  char* bin = malloc(sizeof(char) * 33);

  // Initialize the binary string to all zeros
  memset(bin, ZERO, 33);

  // Convert the decimal number to binary
  int i = 31;
  while (dec > 0) {
    bin[i--] = dec % 2 + '0';
    dec /= 2;
  }

  // Return the binary string
  return bin;
}

// Function to convert a binary string to decimal
int binToDec(char* bin) {
  // Initialize the decimal value to 0
  int dec = 0;

  // Convert the binary string to decimal
  int i = strlen(bin) - 1;
  int pow = 1;
  while (i >= 0) {
    dec += (bin[i--] - '0') * pow;
    pow *= 2;
  }

  // Return the decimal value
  return dec;
}

// Function to print the binary representation of a number
void printBin(int num) {
  // Convert the number to binary
  char* bin = decToBin(num);

  // Print the binary string
  printf("%s\n", bin);

  // Free the memory allocated for the binary string
  free(bin);
}

// Main function
int main() {
  // Declare the variables
  int dec;
  char bin[33];

  // Get the decimal number from the user
  printf("Enter the decimal number: ");
  scanf("%d", &dec);

  // Convert the decimal number to binary
  char* binStr = decToBin(dec);

  // Print the binary representation of the number
  printf("The binary representation of %d is: %s\n", dec, binStr);

  // Free the memory allocated for the binary string
  free(binStr);

  // Get the binary string from the user
  printf("Enter the binary string: ");
  scanf("%s", bin);

  // Convert the binary string to decimal
  int decNum = binToDec(bin);

  // Print the decimal representation of the binary string
  printf("The decimal representation of %s is: %d\n", bin, decNum);

  return 0;
}