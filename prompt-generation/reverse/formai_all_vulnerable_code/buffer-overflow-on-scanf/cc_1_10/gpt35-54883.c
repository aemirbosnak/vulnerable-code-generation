//FormAI DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include<stdio.h>
#include<math.h>

// function to convert decimal to binary
int decimalToBinary(int decimal){
  int binary=0,i=1;
  while(decimal>0){
    int rem=decimal%2;
    binary+=rem*i;
    decimal/=2;
    i*=10;
  }
  return binary;
}

// function to convert binary to decimal
int binaryToDecimal(int binary){
  int decimal=0,i=0;
  while(binary>0){
    int rem=binary%10;
    decimal+=rem*pow(2,i);
    binary/=10;
    i++;
  }
  return decimal;
}

int main(){
  int decimal,binary,choice;
  printf("Please select the conversion type\n");
  printf("1. Decimal to Binary\n2. Binary to Decimal\n");
  scanf("%d",&choice);
  switch(choice){
    case 1:
      printf("\nEnter decimal number: ");
      scanf("%d",&decimal);
      binary = decimalToBinary(decimal);
      printf("\nBinary conversion of %d is %d\n",decimal,binary);
      break;
    case 2:
      printf("\nEnter binary number: ");
      scanf("%d",&binary);
      decimal = binaryToDecimal(binary);
      printf("\nDecimal conversion of %d is %d\n",binary,decimal);
      break;
    default:
      printf("\nInvalid choice!\n");
  }
  return 0;
}