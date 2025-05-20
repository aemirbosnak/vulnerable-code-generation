//FormAI DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binaryToDecimal(char *binary) {
  int decimal = 0, factor = 1;
  int length = strlen(binary);

  for(int i = length - 1; i >= 0; i--) {
    if(binary[i] == '1') {
      decimal += factor;
    }
    factor *= 2;
  }

  printf("The decimal equivalent is: %d\n", decimal);
}

void decimalToBinary(int decimal) {
  int binary[32];
  int i = 0;

  while(decimal > 0) {
    binary[i] = decimal % 2;
    decimal /= 2;
    i++;
  }

  printf("The binary equivalent is: ");
  for(int j = i - 1; j >= 0; j--) {
    printf("%d", binary[j]);
  }
  printf("\n");
}

int main() {
  int choice;
  printf("Enter 1 to convert binary to decimal\n");
  printf("Enter 2 to convert decimal to binary\n");
  scanf("%d", &choice);

  if(choice == 1) {
    char binary[32];
    printf("Enter the binary number: ");
    scanf("%s", binary);
    binaryToDecimal(binary);
  } else if(choice == 2) {
    int decimal;
    printf("Enter the decimal number: ");
    scanf("%d", &decimal);
    decimalToBinary(decimal);
  } else {
    printf("Invalid choice\n");
  }

  return 0;
}