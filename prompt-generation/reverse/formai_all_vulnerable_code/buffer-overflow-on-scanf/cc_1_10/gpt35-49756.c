//FormAI DATASET v1.0 Category: Arithmetic ; Style: multivariable
#include <stdio.h>

int main() {
   int num1, num2, num3, sum, average, product, max, min;
   
   // Asking user for input
   printf("Enter three numbers separated by spaces: ");
   scanf("%d %d %d", &num1, &num2, &num3);
   
   // Calculating sum of three numbers
   sum = num1 + num2 + num3;
   
   // Calculating average of three numbers
   average = sum / 3;
   
   // Calculating product of three numbers
   product = num1 * num2 * num3;
   
   // Setting initial values of max and min
   max = num1;
   min = num1;
   
   // Checking if num2 is greater than max
   if (num2 > max) {
      max = num2;
   }
   
   // Checking if num3 is greater than max
   if (num3 > max) {
      max = num3;
   }
   
   // Checking if num2 is smaller than min
   if (num2 < min) {
      min = num2;
   }
   
   // Checking if num3 is smaller than min
   if (num3 < min) {
      min = num3;
   }
   
   // Printing output
   printf("Sum is: %d\n", sum);
   printf("Average is: %d\n", average);
   printf("Product is: %d\n", product);
   printf("Maximum number is: %d\n", max);
   printf("Minimum number is: %d", min);
   
   return 0;
}