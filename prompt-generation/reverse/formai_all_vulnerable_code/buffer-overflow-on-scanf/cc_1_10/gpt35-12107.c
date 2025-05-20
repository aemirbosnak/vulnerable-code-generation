//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// function prototypes
void convertDecimalToHexadecimal(int decimalNumber);
void convertHexadecimalToDecimal(char *hexadecimalNumber);

// main function
int main() {
  int choice, decimalNumber;
  char hexadecimalNumber[100];

  while(1) {
    printf("Choose an option: \n");
    printf("1. Convert decimal to hexadecimal\n");
    printf("2. Convert hexadecimal to decimal\n");
    printf("3. Quit\n");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter decimal number: ");
        scanf("%d", &decimalNumber);
        convertDecimalToHexadecimal(decimalNumber);
        break;
      case 2:
        printf("Enter hexadecimal number: ");
        scanf("%s", hexadecimalNumber);
        convertHexadecimalToDecimal(hexadecimalNumber);
        break;
      case 3:
        printf("Exiting program...");
        exit(0);
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}

// function to convert decimal to hexadecimal
void convertDecimalToHexadecimal(int decimalNumber) {
  char hexadecimalNumber[100];
  int i = 0;

  while(decimalNumber != 0) {
    int remainder = decimalNumber % 16;
    if(remainder < 10) {
      hexadecimalNumber[i++] = 48 + remainder;
    } else {
      hexadecimalNumber[i++] = 55 + remainder;
    }
    decimalNumber /= 16;
  }

  printf("Hexadecimal equivalent is: ");
  for(int j = i - 1; j >= 0; j--) {
    printf("%c", hexadecimalNumber[j]);
  }

  printf("\n");
}

// function to convert hexadecimal to decimal
void convertHexadecimalToDecimal(char *hexadecimalNumber) {
  int decimalNumber = 0;
  int length = strlen(hexadecimalNumber) - 1;

  for(int i = 0; hexadecimalNumber[i] != '\0'; i++) {
    if(hexadecimalNumber[i] >= 48 && hexadecimalNumber[i] <= 57) {
      decimalNumber += (hexadecimalNumber[i] - 48) * pow(16, length);
    } else if(hexadecimalNumber[i] >= 65 && hexadecimalNumber[i] <= 70) {
      decimalNumber += (hexadecimalNumber[i] - 55) * pow(16, length);
    } else if(hexadecimalNumber[i] >= 97 && hexadecimalNumber[i] <= 102) {
      decimalNumber += (hexadecimalNumber[i] - 87) * pow(16, length);
    }
    length--;
  }

  printf("Decimal equivalent is: %d\n", decimalNumber);
}