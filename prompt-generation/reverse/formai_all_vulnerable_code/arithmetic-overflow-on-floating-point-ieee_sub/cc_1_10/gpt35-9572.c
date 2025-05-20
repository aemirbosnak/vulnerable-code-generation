//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: authentic
#include <stdio.h>
#include <math.h>

int main() {
   char operator;
   double num1, num2, result;

   printf("Enter an operator (+, -, *, /, sin, cos, tan, sqrt): ");
   scanf("%c", &operator);

   switch(operator) {
      case '+':
         printf("Enter two numbers: ");
         scanf("%lf %lf", &num1, &num2);
         result = num1 + num2;
         printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
         break;

      case '-':
         printf("Enter two numbers: ");
         scanf("%lf %lf", &num1, &num2);
         result = num1 - num2;
         printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
         break;

      case '*':
         printf("Enter two numbers: ");
         scanf("%lf %lf", &num1, &num2);
         result = num1 * num2;
         printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
         break;

      case '/':
         printf("Enter two numbers: ");
         scanf("%lf %lf", &num1, &num2);
         if(num2 == 0) {
            printf("Error! Divide by zero.");
         } else {
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
         }
         break;

      case 's':
         printf("Enter a number: ");
         scanf("%lf", &num1);
         result = sin(num1);
         printf("sin(%lf) = %.2lf", num1, result);
         break;

      case 'c':
         printf("Enter a number: ");
         scanf("%lf", &num1);
         result = cos(num1);
         printf("cos(%lf) = %.2lf", num1, result);
         break;

      case 't':
         printf("Enter a number: ");
         scanf("%lf", &num1);
         result = tan(num1);
         printf("tan(%lf) = %.2lf", num1, result);
         break;

      case 'q':
         printf("Enter a number: ");
         scanf("%lf", &num1);
         result = sqrt(num1);
         printf("sqrt(%lf) = %.2lf", num1, result);
         break;

      default:
         printf("Error! Invalid operator.");
   }

   return 0;
}