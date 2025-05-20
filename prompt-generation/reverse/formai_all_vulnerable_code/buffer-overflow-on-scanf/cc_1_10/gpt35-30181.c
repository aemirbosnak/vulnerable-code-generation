//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: systematic
#include <stdio.h>

// Function prototypes
long decimalToHexadecimal(int decimal);
void printHexadecimal(long hexadecimal);

int main() {
  
  int decimal;
  
  // Take input decimal number from user
  printf("Enter a decimal number: ");
  scanf("%d", &decimal);
  
  // Convert decimal to hexadecimal
  long hexadecimal = decimalToHexadecimal(decimal);
  
  // Print hexadecimal number
  printf("Hexadecimal Equivalent: ");
  printHexadecimal(hexadecimal);
  
  return 0;
}

// Function to convert decimal to hexadecimal
long decimalToHexadecimal(int decimal) {
  
  int remainder, quotient;
  long hexadecimal = 0, i = 1;
  
  while (decimal != 0) {
    remainder = decimal % 16;
    quotient = decimal / 16;
    decimal = quotient;
    hexadecimal += remainder * i;
    i *= 10;
  }
  
  return hexadecimal;
}

// Function to print hexadecimal number
void printHexadecimal(long hexadecimal) {
  
  long reversedHexadecimal = 0, remainder;
  
  // Reverse the digits of hexadecimal number
  while (hexadecimal != 0) {
    remainder = hexadecimal % 10;
    reversedHexadecimal = reversedHexadecimal * 10 + remainder;
    hexadecimal /= 10;
  }
  
  // Convert the digits to their corresponding hexadecimal characters
  while (reversedHexadecimal != 0) {
    remainder = reversedHexadecimal % 100;
    if (remainder < 10) {
      printf("%c", remainder + 48);
    } else {
      printf("%c", remainder + 55);
    }
    reversedHexadecimal /= 100;
  }
  
}