//FormAI DATASET v1.0 Category: Binary Converter ; Style: curious
#include<stdio.h>
#include<math.h>

void decimalToBinary(int decimal){

  int remainder, binary = 0, i = 0;

  //Calculating binary equivalent
  while(decimal!=0){
    remainder = decimal%2;
    decimal = decimal/2;
    binary = binary + remainder*pow(10,i);
    i++;
  }

  printf("Binary Equivalent = %d\n", binary);
}

void binaryToDecimal(int binary){

  int decimal = 0, i=0, remainder;

  //Calculating decimal equivalent
  while(binary!=0){
    remainder = binary%10;
    binary = binary/10;
    decimal = decimal + remainder*pow(2,i);
    i++;
  }

  printf("Decimal Equivalent = %d\n", decimal);
}

int main(){

  int choice, decimal, binary;

  printf("Welcome to the Binary Converter Program! \n");
  printf("====================================== \n");

  while(1){

    printf("\n 1. Decimal to Binary \n 2. Binary to Decimal \n 3. Exit \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("\nEnter a decimal number: ");
        scanf("%d", &decimal);
        printf("\n");
        decimalToBinary(decimal);
        break;
      case 2:
        printf("\nEnter a binary number: ");
        scanf("%d", &binary);
        printf("\n");
        binaryToDecimal(binary);
        break;
      case 3:
        printf("\nGoodbye! \n\n");
        exit(0);
      default:
        printf("\nInvalid Choice! Please Try Again \n\n");
    }
  }

  return 0;
}