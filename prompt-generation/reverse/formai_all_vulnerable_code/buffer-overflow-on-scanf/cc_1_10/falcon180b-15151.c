//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define BIT_SIZE 32

int main() {
   int num1, num2, result;
   char choice;

   printf("Enter 1 to perform bitwise operations\n");
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         printf("Enter two numbers to perform bitwise operations:\n");
         scanf("%d %d", &num1, &num2);

         // Bitwise AND
         result = num1 & num2;
         printf("Bitwise AND of %d and %d is %d\n", num1, num2, result);

         // Bitwise OR
         result = num1 | num2;
         printf("Bitwise OR of %d and %d is %d\n", num1, num2, result);

         // Bitwise XOR
         result = num1 ^ num2;
         printf("Bitwise XOR of %d and %d is %d\n", num1, num2, result);

         // Bitwise NOT
         result = ~num1;
         printf("Bitwise NOT of %d is %d\n", num1, result);

         // Left shift
         result = num1 << 2;
         printf("Left shift of %d by 2 is %d\n", num1, result);

         // Right shift
         result = num1 >> 2;
         printf("Right shift of %d by 2 is %d\n", num1, result);

         // Bitwise AND with a mask
         result = num1 & 0x0F;
         printf("Bitwise AND of %d and 0x0F is %d\n", num1, result);

         // Bitwise OR with a mask
         result = num1 | 0x0F;
         printf("Bitwise OR of %d and 0x0F is %d\n", num1, result);

         // Bitwise XOR with a mask
         result = num1 ^ 0x0F;
         printf("Bitwise XOR of %d and 0x0F is %d\n", num1, result);

         // Bitwise NOT with a mask
         result = ~num1 & 0x0F;
         printf("Bitwise NOT of %d with 0x0F as mask is %d\n", num1, result);

         break;

      default:
         printf("Invalid choice\n");
         break;
   }

   return 0;
}