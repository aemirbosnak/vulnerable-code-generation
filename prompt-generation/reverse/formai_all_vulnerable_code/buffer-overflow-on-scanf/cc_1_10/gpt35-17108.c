//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>

// Function to convert decimal to hexadecimal
void decToHex(int decimal_num) {
  int remainder, quotient;
  char hexadecimal_num[100];
  quotient = decimal_num;
  int i = 0;
  
  while (quotient != 0) {
    remainder = quotient % 16;
    if (remainder < 10) {
      hexadecimal_num[i] = 48 + remainder;
      i++;
    } else {
      hexadecimal_num[i] = 55 + remainder;
      i++;
    }
    quotient = quotient / 16;
  }
  // Printing the equivalent hexadecimal
  printf("The hexadecimal equivalent of decimal number %d is: ", decimal_num);
  for (int j = i - 1; j >= 0; j--){
    printf("%c", hexadecimal_num[j]);
  }
  printf("\n");
}

// Function to convert hexadecimal to decimal
int hexToDec(char *hexadecimal_num){
  int decimal_num = 0;
  int length = strlen(hexadecimal_num);
  int base = 1;
  
  for (int i = length - 1; i >= 0; i--) {
    if (hexadecimal_num[i] >= '0' && hexadecimal_num[i] <= '9') {
      decimal_num += (hexadecimal_num[i] - 48) * base;
      base = base * 16;
    } else if (hexadecimal_num[i] >= 'A' && hexadecimal_num[i] <= 'F') {
      decimal_num += (hexadecimal_num[i] - 55) * base;
      base = base * 16;
    } 
  }
  // Returning the equivalent decimal number
  return decimal_num;
}

int main() {
  char hexadecimal_num[100];
  int decimal_num;
  int choice;
  
  printf("Welcome to the Hexadecimal Converter Program!\n");
  printf("Choose an option:\n");
  printf("1. Decimal to hexadecimal conversion\n");
  printf("2. Hexadecimal to decimal conversion\n");
  printf("Enter your choice (1 or 2): ");
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      printf("Enter the decimal number to be converted: ");
      scanf("%d", &decimal_num);
      decToHex(decimal_num);
      break;
      
    case 2:
      printf("Enter the hexadecimal number to be converted: ");
      scanf("%s", hexadecimal_num);
      decimal_num = hexToDec(hexadecimal_num);
      printf("The decimal equivalent of hexadecimal number %s is: %d\n", hexadecimal_num, decimal_num);
      break;
      
    default:
      printf("Invalid choice!\n");
  }
  return 0;
}