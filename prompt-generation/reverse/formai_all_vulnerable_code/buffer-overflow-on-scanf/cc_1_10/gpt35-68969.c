//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: synchronous
#include <stdio.h>
#include <string.h>

int hexToDec(char hex[]);
int decToHex(int dec);
void printResult(int dec, char hex[]);

int main() {
  char hexInput[10];
  int decInput;
  printf("Enter a hexadecimal number: ");
  scanf("%s", hexInput);

  int decimal = hexToDec(hexInput);
  printf("Decimal Representation: %d \n", decimal);
  
  printf("\nEnter a decimal number: ");
  scanf("%d", &decInput);

  char hex[10] = { 0 }; // initialize hex array with 0s
  int i = 1, quotient = decInput;

  while (quotient != 0) {
    int remainder = quotient % 16;
    hex[i++] = decToHex(remainder);
    quotient /= 16;
  }

  printResult(decInput, hex);
  return 0;
}

int hexToDec(char hex[]) {
  int decimal = 0, base = 1, len = strlen(hex);
  for (int i = len - 1; i >= 0; i--) {
    if (hex[i] >= '0' && hex[i] <= '9') {
      decimal += (hex[i] - 48) * base;
      base *= 16;
    }
    else if (hex[i] >= 'A' && hex[i] <= 'F') {
      decimal += (hex[i] - 55) * base;
      base *= 16;
    }
  }
  return decimal;
}

int decToHex(int dec) {
    if (dec >= 0 && dec <= 9) {
        return dec + 48;
    }
    else {
        return dec + 55;
    }
}

void printResult(int dec, char hex[]) {
  printf("\nHexadecimal Representation: ");
  for (int i = strlen(hex); i > 0; i--) {
    printf("%c", hex[i]);
  }
  printf("\nDecimal: %d, Hexadecimal: 0x%s", dec, hex);
}