//FormAI DATASET v1.0 Category: Math exercise ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
   int num1, num2, result;
   float num3, num4, resultf;

   // get two integer inputs from the user
   printf("Enter the first integer number: ");
   scanf("%d", &num1);
   printf("Enter the second integer number: ");
   scanf("%d", &num2);

   // perform arithmetic operations on the two integers
   result = num1 + num2;
   printf("The sum of the two integers is: %d\n", result);
   result = num1 * num2;
   printf("The product of the two integers is: %d\n", result);
   result = num1 / num2;
   printf("The quotient of the two integers is: %d\n", result);
   result = num1 - num2;
   printf("The difference of the two integers is: %d\n", result);

   // get two floating point inputs from the user
   printf("Enter the first floating point number: ");
   scanf("%f", &num3);
   printf("Enter the second floating point number: ");
   scanf("%f", &num4);

   // perform arithmetic operations on the two floating point numbers
   resultf = num3 + num4;
   printf("The sum of the two floating point numbers is: %f\n", resultf);
   resultf = num3 * num4;
   printf("The product of the two floating point numbers is: %f\n", resultf);
   resultf = num3 / num4;
   printf("The quotient of the two floating point numbers is: %f\n", resultf);
   resultf = num3 - num4;
   printf("The difference of the two floating point numbers is: %f\n", resultf);

   // perform other math functions
   printf("\nThe square root of %d is: %f\n", num1, sqrt(num1));
   printf("The square root of %f is: %f\n", num3, sqrt(num3));
   printf("The cosine of %d is: %f\n", num2, cos(num2));
   printf("The sine of %f is: %f\n", num4, sin(num4));
   printf("The natural logarithm of %d is: %f\n", num1, log(num1));
   printf("The base-10 logarithm of %f is: %f\n", num3, log10(num3));
   printf("The absolute value of %d is: %d\n", result, abs(result));
   printf("The rounding of %f is: %d\n", num4, (int)(num4+0.5));

   return 0;
}