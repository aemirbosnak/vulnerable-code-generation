//FormAI DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
  // Initializing variables
  int binary[32];
  int index = 0;

  // Converting decimal to binary
  while (decimal > 0) {
    binary[index] = decimal % 2;
    decimal = decimal / 2;
    index++;
  }

  // Printing binary
  printf("Binary: ");
  for (int j = index - 1; j >= 0; j--) {
    printf("%d", binary[j]);
  }
  printf("\n");
}

// Function to convert binary to decimal
void binaryToDecimal(char binary[]) {
  // Initializing variables
  int decimal = 0;
  int base = 1;
  int length = strlen(binary);

  // Converting binary to decimal
  for (int i = length - 1; i >= 0; i--) {
    if (binary[i] == '1') {
      decimal += base;
    }
    base *= 2;
  }

  // Printing decimal
  printf("Decimal: %d\n", decimal);
}

int main() {
  int option;
  printf("Welcome to Brave Binary Converter\n");
  printf("1. Convert Decimal to Binary\n");
  printf("2. Convert Binary to Decimal\n");
  printf("Select an option: ");
  scanf("%d", &option);

  switch (option) {
    case 1: {
      int decimal;
      printf("Enter decimal number: ");
      scanf("%d", &decimal);
      decimalToBinary(decimal);
      break;
    }
    case 2: {
      char binary[32];
      printf("Enter binary number: ");
      scanf("%s", binary);
      binaryToDecimal(binary);
      break;
    }
    default: {
      printf("Invalid option\n");
      break;
    }
  }

  return 0;
}