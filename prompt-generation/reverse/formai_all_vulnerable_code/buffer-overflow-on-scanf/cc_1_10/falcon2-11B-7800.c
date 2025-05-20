//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void add(int *a, int *b, int *result);
void subtract(int *a, int *b, int *result);
void multiply(int *a, int *b, int *result);
void divide(int *a, int *b, int *result);

int main() {

   int num1, num2, num3, num4, answer;

   printf("Welcome to the Calculator!\n");

   do {
      // Prompt user for input
      printf("Enter two numbers: ");
      scanf("%d %d", &num1, &num2);

      // Perform arithmetic operation based on user choice
      printf("What operation would you like to perform? (+, -, *, /) ");
      scanf(" %c", &answer);

      switch(answer) {
         case '+':
            add(&num1, &num2, &num3);
            break;
         case '-':
            subtract(&num1, &num2, &num3);
            break;
         case '*':
            multiply(&num1, &num2, &num3);
            break;
         case '/':
            divide(&num1, &num2, &num3);
            break;
         default:
            printf("Invalid input!\n");
      }

      // Display result
      printf("%d + %d = %d\n", num1, num2, num3);
      printf("--------------------------------------\n");
      printf("Enter two more numbers: ");
      scanf("%d %d", &num4, &answer);

      switch(answer) {
         case '+':
            add(&num3, &num4, &answer);
            break;
         case '-':
            subtract(&num3, &num4, &answer);
            break;
         case '*':
            multiply(&num3, &num4, &answer);
            break;
         case '/':
            divide(&num3, &num4, &answer);
            break;
         default:
            printf("Invalid input!\n");
      }

      // Display final result
      printf("%d + %d = %d\n", num3, num4, answer);
      printf("--------------------------------------\n");
   } while(1);

   return 0;
}

void add(int *a, int *b, int *result) {
   *result = *a + *b;
}

void subtract(int *a, int *b, int *result) {
   *result = *a - *b;
}

void multiply(int *a, int *b, int *result) {
   *result = *a * *b;
}

void divide(int *a, int *b, int *result) {
   *result = *a / *b;
}