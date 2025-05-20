//FormAI DATASET v1.0 Category: Binary Converter ; Style: curious
/*
   Name: Curious Binary Converter
   Author: CuriousBot
   Date: July 2021
   Description: This program converts decimal numbers to binary and binary numbers to decimal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* function to convert decimal to binary */
void decimalToBinary(long long decimalNumber) {
   int binaryNumber[100], index = 0, isNegative = 0;
   
   /* Check if the input number is negative */
   if(decimalNumber < 0) {
      isNegative = 1;
      decimalNumber = abs(decimalNumber);
   }
   
   /* Handle the case when the input number is 0 */
   if(decimalNumber == 0) {
      printf("0\n");
      return;
   }
   
   while(decimalNumber > 0) {
      binaryNumber[index] = decimalNumber % 2; // get the remainder when the decimal number is divided by 2
      decimalNumber /= 2; // divide the decimal number by 2
      index++;
   }
   
   /* Print the binary number */
   printf("Binary number: ");
   if(isNegative) printf("-");
   for(int i = index - 1; i >= 0; i--) {
      printf("%d", binaryNumber[i]);
   }
   printf("\n");
}

/* function to convert binary to decimal */
void binaryToDecimal(long long binaryNumber) {
   int decimalNumber = 0, index = 0;
   bool isNegative = false;
   
   /* Check if the input number is negative */
   if(binaryNumber < 0) {
      isNegative = true;
      binaryNumber = abs(binaryNumber);
   }
   
   /* Handle the case when the input number is 0 */
   if(binaryNumber == 0) {
      printf("0\n");
      return;
   }
   
   while(binaryNumber > 0) {
      int remainder = binaryNumber % 10;
      if(remainder != 0 && remainder != 1) {
         printf("Invalid input. Please enter a binary number.\n");
         return;
      }
      decimalNumber += remainder * (1 << index); // use the left shift operator to calculate power of 2
      binaryNumber /= 10;
      index++;
   }
   
   /* Print the decimal number */
   printf("Decimal number: ");
   if(isNegative) printf("-");
   printf("%d\n", decimalNumber);
}

int main() {
   int choice;
   long long decimalNumber, binaryNumber;
   
   printf("Welcome to Curious Binary Converter!\n");
   
   while(true) {
      printf("\nEnter 1 to convert decimal to binary\nEnter 2 to convert binary to decimal\nEnter 3 to exit\n\n");
      scanf("%d", &choice);
      
      if(choice == 1) {
         printf("\nEnter a decimal number: ");
         scanf("%lld", &decimalNumber);
         decimalToBinary(decimalNumber);
      }
      else if(choice == 2) {
         printf("\nEnter a binary number: ");
         scanf("%lld", &binaryNumber);
         binaryToDecimal(binaryNumber);
      }
      else if(choice == 3) {
         printf("\nThank you for using Curious Binary Converter!\n");
         return 0;
      }
      else {
         printf("\nInvalid choice. Please try again.\n");
      }
   }
   
   return 0;
}