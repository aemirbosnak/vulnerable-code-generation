//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <math.h>

int main() {
   char operator;
   double first_num, second_num, answer;

   printf("Welcome to the Simple Calculator!\n");
   printf("Enter an arithmetic operation (+, -, *, /, %%) and two numbers, separated by spaces.\n");
   printf("Type 'exit' or 'quit' to terminate the program.\n\n");

   while(1) {
      printf("> ");
      scanf("%c %lf %lf", &operator, &first_num, &second_num);
      if(operator == 'e' || operator == 'q') {
         printf("Goodbye! Thank you for using the Simple Calculator.\n");
         break;
      }

      switch(operator) {
         case '+':
            answer = first_num + second_num;
            printf("%.2lf + %.2lf = %.2lf\n", first_num, second_num, answer);
            break;

         case '-':
            answer = first_num - second_num;
            printf("%.2lf - %.2lf = %.2lf\n", first_num, second_num, answer);
            break;

         case '*':
            answer = first_num * second_num;
            printf("%.2lf * %.2lf = %.2lf\n", first_num, second_num, answer);
            break;

         case '/':
            if(second_num == 0) {
               printf("Error: division by zero.\n");
            }
            else {
               answer = first_num / second_num;
               printf("%.2lf / %.2lf = %.2lf\n", first_num, second_num, answer);
            }
            break;

         case '%':
            if(second_num == 0) {
               printf("Error: modulus by zero.\n");
            }
            else {
               answer = fmod(first_num, second_num);
               printf("%.2lf %% %.2lf = %.2lf\n", first_num, second_num, answer);
            }
            break;

         default:
            printf("Error: invalid operator '%c'.\n", operator);
            break;
      }
   }
   return 0;
}