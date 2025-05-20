//FormAI DATASET v1.0 Category: Arithmetic ; Style: genious
#include <stdio.h>

int main() {
   int num1, num2, num3, sum;
   printf("Enter three numbers: ");
   scanf("%d %d %d", &num1, &num2, &num3);

   sum = num1 + num2 + num3;

   if (sum % 2 == 0) {
      printf("The sum of the three numbers is even.\n");
   } else {
      printf("The sum of the three numbers is odd.\n");
   }

   int diff = num1 - num2 - num3;

   if (diff < 0) {
      diff = -diff;
   }

   printf("The absolute difference between %d, %d, %d is %d\n", num1, num2, num3, diff);

   int product = num1 * num2 * num3;

   if (product > 100) {
      printf("The product of the three numbers is greater than 100.\n");
   } else {
      printf("The product of the three numbers is less than or equal to 100.\n");
   }

   // Let's check if the user input three increasing numbers
   if (num1 < num2 && num2 < num3) {
      printf("The input numbers are in increasing order.\n");
   } else {
      printf("The input numbers are not in increasing order.\n");
      
      int temp;
      if (num1 > num2) {
         temp = num2;
         num2 = num1;
         num1 = temp;
      }
      if (num2 > num3) {
         temp = num3;
         num3 = num2;
         num2 = temp;
      }
      if (num1 > num2) {
         temp = num2;
         num2 = num1;
         num1 = temp;
      }

      printf("The numbers in increasing order are: %d %d %d\n", num1, num2, num3);
   }

   return 0;
}