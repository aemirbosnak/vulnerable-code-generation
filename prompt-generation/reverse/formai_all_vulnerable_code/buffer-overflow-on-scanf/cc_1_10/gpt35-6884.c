//FormAI DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binaryToDecimal(int binary) {
   int decimal = 0, base = 1, remainder;
   
   while(binary > 0) {
      remainder = binary % 10;
      decimal += remainder * base;
      base *= 2;
      binary /= 10;
   }
   
   return decimal;
}

int decimalToBinary(int decimal) {
   int binary = 0, base = 1, remainder;
   
   while(decimal > 0) {
      remainder = decimal % 2;
      binary += remainder * base;
      base *= 10;
      decimal /= 2;
   }
   
   return binary;
}

int main() {
   int choice = 0, num;
   
   printf("Welcome to the Binary Converter!\n");
   
   while(choice != 3) {
      printf("\nChoose an option:\n");
      printf("1. Convert binary to decimal\n");
      printf("2. Convert decimal to binary\n");
      printf("3. Quit\n");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1: {
            printf("Enter a binary number: ");
            scanf("%d", &num);
            
            int decimal = binaryToDecimal(num);
            
            printf("%d in binary = %d in decimal.", num, decimal);
            break;
         }
         
         case 2: {
            printf("Enter a decimal number: ");
            scanf("%d", &num);
            
            int binary = decimalToBinary(num);
            
            printf("%d in decimal = %d in binary.", num, binary);
            break;
         }
         
         case 3: {
            printf("Goodbye!");
            break;
         }
         
         default: {
            printf("Invalid option. Please try again.");
            break;
         }
      }
   }
   
   return 0;
}