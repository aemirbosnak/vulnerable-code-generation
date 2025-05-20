//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <math.h>

void convertHexToDecimal(char hex[]) {
  int len = strlen(hex);
  int base = 1;
  int decimal = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      decimal += (hex[i] - 48) * base;
      base *= 16;
    }
    else if (hex[i] >= 'a' && hex[i] <= 'f') {
      decimal += (hex[i] - 87) * base;
      base *= 16;
    }
    else if (hex[i] >= 'A' && hex[i] <= 'F') {
      decimal += (hex[i] - 55) * base;
      base *= 16;
    }
  }
  printf("Hexadecimal = %s\nDecimal = %d\n", hex, decimal);
}

void convertDecimalToHex(int decimal) {
  char hex[16];
  int i = 0;
  while(decimal != 0) {
    int remainder = decimal % 16;
    if (remainder < 10) {
      hex[i] = remainder + 48;
    }
    else {
      hex[i] = remainder + 55;
    }
    decimal /= 16;
    i++;
  }
  hex[i] = '\0';
  int len = strlen(hex);
  char rev[len];
  for (int j = len - 1; j >= 0; j--) {
    rev[len - j - 1] = hex[j];
  }
  rev[len] = '\0';
  printf("Decimal = %d\nHexadecimal = %s\n", decimal, rev);
}

void menu() {
  printf("1. Convert hexadecimal to decimal\n");
  printf("2. Convert decimal to hexadecimal\n");
  printf("3. Exit\n");
}

int main() {
  int choice;
  char hex[16];
  int decimal;
  do {
    menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1: // Hexadecimal to Decimal
        printf("Enter a hexadecimal number: ");
        scanf("%s", hex);
        convertHexToDecimal(hex);
        break;
        
      case 2: // Decimal to Hexadecimal
        printf("Enter a decimal number: ");
        scanf("%d", &decimal);
        convertDecimalToHex(decimal);
        break;
      
      case 3: // Exit
        printf("Goodbye!\n");
        break;
        
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while(choice != 3);
  
  return 0;
}