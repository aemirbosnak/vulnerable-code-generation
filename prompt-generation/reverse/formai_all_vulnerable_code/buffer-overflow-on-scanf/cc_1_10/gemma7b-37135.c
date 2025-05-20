//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int decimal) {
  int quotient = decimal / 16;
  int remainder = decimal % 16;
  char hexChar;

  if (quotient) {
    convertToHex(quotient);
  }

  switch (remainder) {
    case 0:
      hexChar = '0';
      break;
    case 1:
      hexChar = '1';
      break;
    case 2:
      hexChar = '2';
      break;
    case 3:
      hexChar = '3';
      break;
    case 4:
      hexChar = '4';
      break;
    case 5:
      hexChar = '5';
      break;
    case 6:
      hexChar = '6';
      break;
    case 7:
      hexChar = '7';
      break;
    case 8:
      hexChar = '8';
      break;
    case 9:
      hexChar = '9';
      break;
    case 10:
      hexChar = 'A';
      break;
    case 11:
      hexChar = 'B';
      break;
    case 12:
      hexChar = 'C';
      break;
    case 13:
      hexChar = 'D';
      break;
    case 14:
      hexChar = 'E';
      break;
    case 15:
      hexChar = 'F';
      break;
  }

  printf("%c", hexChar);
}

int main() {
  int decimal;

  printf("Enter a decimal number: ");
  scanf("%d", &decimal);

  convertToHex(decimal);

  printf("\nHexadecimal equivalent: ");
  printf("%x", decimal);

  return 0;
}