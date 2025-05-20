//FormAI DATASET v1.0 Category: Funny ; Style: creative
#include <stdio.h>

int main() {
   int num = 10;
   char ch = 'A';
   float decimal = 10.5;
   char string[] = "Hello World!";
   printf("The value of num is: %d\n", num);
   printf("The value of ch is: %c\n", ch);
   printf("The value of decimal is: %f\n", decimal);
   printf("The value of string is: %s\n", string);

   printf("ASCII value of %c is %d\n", ch, ch);

   printf("Using ternary operator to get the maximum between two numbers.\n");
   int a = 5;
   int b = 10;
   int max = (a>b) ? a : b;
   printf("The maximum between %d and %d is: %d\n", a, b, max);

   printf("Creating a simple calculator using switch statements.\n");
   float x;
   float y;
   char operator;
   printf("Enter the first number: ");
   scanf("%f", &x);
   printf("Enter the operator (+, -, *, /): ");
   scanf(" %c", &operator);
   printf("Enter the second number: ");
   scanf("%f", &y);
   switch (operator) {
      case '+':
         printf("%f + %f = %f", x, y, x+y);
         break;
      case '-':
         printf("%f - %f = %f", x, y, x-y);
         break;
      case '*':
         printf("%f * %f = %f", x, y, x*y);
         break;
      case '/':
         printf("%f / %f = %f", x, y, x/y);
         break;
      default:
         printf("Invalid input!");
   }

   printf("Printing the Armstrong numbers between 1 and 1000.\n");
   int i, originalNum, remainder, result = 0;
   for (i = 1; i <= 1000; ++i) {
      originalNum = i;
      while (originalNum != 0) {
         remainder = originalNum % 10;
         result += remainder*remainder*remainder;
         originalNum /= 10;
      }
      if (result == i) {
         printf("%d ", i);
      }
      result = 0;
   }

   return 0;
}