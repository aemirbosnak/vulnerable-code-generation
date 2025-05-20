//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <math.h>

int main() {
   double num1, num2;
   char op;

   printf("Enter two numbers: ");
   scanf("%lf %lf", &num1, &num2);

   printf("Enter an operator (+, -, *, /, %%, sin, cos, tan, log, sqrt): ");
   scanf(" %c", &op);

   switch(op) {
      case '+':
         printf("%.2lf + %.2lf = %.2lf", num1, num2, num1 + num2);
         break;

      case '-':
         printf("%.2lf - %.2lf = %.2lf", num1, num2, num1 - num2);
         break;

      case '*':
         printf("%.2lf * %.2lf = %.2lf", num1, num2, num1 * num2);
         break;

      case '/':
         printf("%.2lf / %.2lf = %.2lf", num1, num2, num1 / num2);
         break;

      case '%':
         printf("%.lf %% %.lf = %.lf", num1, num2, fmod(num1, num2));
         break;

      case 's':
         printf("sin(%.lf) = %.2lf", num1, sin(num1));
         break;

      case 'c':
         printf("cos(%.lf) = %.2lf", num1, cos(num1));
         break;

      case 't':
         printf("tan(%.lf) = %.2lf", num1, tan(num1));
         break;

      case 'l':
         printf("log(%.lf) = %.2lf", num1, log10(num1));
         break;

      case 'q':
         printf("sqrt(%.lf) = %.2lf", num1, sqrt(num1));
         break;

      // operator doesn't match any case constant (+, -, *, /, %%, sin, cos, tan, log, sqrt)
      default:
         printf("Error! operator is not correct");
   }

   return 0;
}