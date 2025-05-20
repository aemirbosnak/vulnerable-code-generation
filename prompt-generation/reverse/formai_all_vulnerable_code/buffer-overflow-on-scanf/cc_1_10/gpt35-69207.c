//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>

int main() {
  int decimal_number;
  printf("Welcome to our Hexadecimal Converter program!\n");
  
  // Prompt user for input
  printf("Please enter a decimal number: ");
  scanf("%d", &decimal_number);
  
  // Convert decimal to hexadecimal
  int quotient, remainder;
  int i = 0;
  char hex_number[20];
  quotient = decimal_number;
  
  while (quotient != 0) {
    remainder = quotient % 16;
    
    if (remainder < 10) {
      hex_number[i] = 48 + remainder;
      i++;
    } else {
      hex_number[i] = 55 + remainder;
      i++;
    }
    
    quotient = quotient / 16;
  }
  
  // Reverse the array to get correct result
  int j;
  char temp;
  
  for (j = 0; j < i/2; j++) {
    temp = hex_number[j];
    hex_number[j] = hex_number[i-j-1];
    hex_number[i-j-1] = temp;
  }
  
  // Print the hexadecimal equivalent
  printf("The hexadecimal equivalent of %d is: ", decimal_number);
  for (j = 0; j < i; j++) {
    printf("%c", hex_number[j]);
  }
  
  printf("\nThank you for using our Hexadecimal Converter program!\n");
  
  return 0;
}