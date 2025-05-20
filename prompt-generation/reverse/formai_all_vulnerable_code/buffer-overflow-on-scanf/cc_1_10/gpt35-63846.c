//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void decimalToHexadecimal(int decimal);
void hexadecimalToDecimal(char hexadecimal[]);

int main() {
  int choice, decimal;
  char hexadecimal[100];

  printf("*********************************\n");
  printf("* Welcome to the Hex Converter! *\n");
  printf("*********************************\n\n");

  while (1) {
    printf("What would you like to convert?\n");
    printf("[1] Decimal to Hexadecimal\n");
    printf("[2] Hexadecimal to Decimal\n");
    printf("[3] Quit\n");

    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("\nEnter a decimal number: ");
        scanf("%d", &decimal);
        decimalToHexadecimal(decimal);
        break;
      case 2:
        printf("\nEnter a hexadecimal number: ");
        scanf("%s", hexadecimal);
        hexadecimalToDecimal(hexadecimal);
        break;
      case 3:
        printf("\nGoodbye!\n");
        exit(0);
      default:
        printf("\nInvalid choice. Try again.\n");
        break;
    }

    printf("\n");
  }

  return 0;
}

void decimalToHexadecimal(int decimal) {
  int remainder, quotient;
  char hex[100];
  int i = 0;

  quotient = decimal;

  while (quotient != 0) {
    remainder = quotient % 16;
    if (remainder < 10)
      hex[i++] = remainder + 48;
    else
      hex[i++] = remainder + 55;
    quotient = quotient / 16;
  }

  printf("Hexadecimal: ");

  for (int j = i - 1; j >= 0; j--) {
    printf("%c", hex[j]);
  }

  printf("\n");
}

void hexadecimalToDecimal(char hexadecimal[]) {
  int decimal = 0;
  int i = 0;
  char c;

  while (hexadecimal[i] != '\0') {
    c = hexadecimal[i];

    if (c >= '0' && c <= '9')
      decimal = decimal * 16 + c - '0';
    else if (c >= 'a' && c <= 'f')
      decimal = decimal * 16 + c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
      decimal = decimal * 16 + c - 'A' + 10;
    else {
      printf("Invalid hexadecimal number!\n");
      return;
    }

    i++;
  }

  printf("Decimal: %d\n", decimal);
}