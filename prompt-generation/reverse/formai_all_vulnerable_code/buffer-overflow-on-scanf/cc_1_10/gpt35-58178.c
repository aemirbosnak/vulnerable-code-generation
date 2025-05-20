//FormAI DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int);
void binaryToDecimal(char[]);

int main() {
  int choice;

  // Creating a menu
  printf("-----------------------------\n");
  printf("         BINARY CONVERTER     \n");
  printf("-----------------------------\n");
  printf("1. Decimal to Binary Conversion\n");
  printf("2. Binary to Decimal Conversion\n");
  printf("3. Exit\n");

  // Taking user input for the desired conversion option
  printf("\nEnter your choice (1, 2 or 3): ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      {
        int decimal;
        printf("Enter decimal number: ");
        scanf("%d", &decimal);
        decimalToBinary(decimal);
        break;
      }
    case 2:
      {
        char binary[20];
        printf("Enter binary number: ");
        scanf("%s", &binary);
        binaryToDecimal(binary);
        break;
      }
    case 3:
      exit(0);
    default:
      printf("Invalid choice.\n");
      main();
  }
  return 0;
}

// Function for decimal to binary conversion
void decimalToBinary(int decimal) {
  int binary[20];
  int i = 0;
  while(decimal > 0) {
    binary[i] = decimal % 2;
    decimal = decimal/2;
    i++;
  }
  printf("\nBinary number: ");
  for(int j=i-1; j>=0; j--) {
    printf("%d",binary[j]);
  }
  printf("\n");
  main();
}

// Function for binary to decimal conversion
void binaryToDecimal(char binary[]) {
  int decimal = 0;
  int base = 1;
  int len = strlen(binary);
  for(int i=len-1; i>=0; i--) {
    if(binary[i] == '1') {
      decimal += base;
    }
    base *= 2;
  }
  printf("\nDecimal number: %d", decimal);
  printf("\n");
  main();
}