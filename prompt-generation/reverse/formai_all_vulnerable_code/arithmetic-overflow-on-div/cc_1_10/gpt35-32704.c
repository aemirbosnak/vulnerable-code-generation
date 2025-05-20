//FormAI DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if number is prime or not
int isPrime(int n) {
   if(n <= 1) {
      return 0;
   }
   for(int i = 2; i <= sqrt(n); i++) {
      if(n % i == 0) {
         return 0;
      }
   }
   return 1;
}

// Function to generate fibonacci series
int fibonacci(int n) {
   if(n <= 1) {
      return n;
   }
   return fibonacci(n - 1) + fibonacci(n - 2);
}

// Main function
int main() {
   int num1, num2, result;
   char operator;
   printf("Welcome to the C Calculator!\n\n");

   do {
      // Select operation
      printf("Please select the operation (+,-,*,/,%): ");
      scanf(" %c", &operator);

      // If operator is invalid, exit program
      if(operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%') {
         printf("Invalid operator selected.\n");
         exit(1);
      }

      // Get input numbers
      printf("Please enter the first number: ");
      scanf("%d", &num1);
      printf("Please enter the second number: ");
      scanf("%d", &num2);

      // Perform selected operation
      switch(operator) {
         case '+':
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
         case '-':
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
         case '*':
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
         case '/':
            if(num2 == 0) {
               printf("Error: cannot divide by zero.\n");
               break;
            }
            result = num1 / num2;
            printf("Result: %d\n", result);
            break;
         case '%':
            if(num2 == 0) {
               printf("Error: cannot divide by zero.\n");
               break;
            }
            result = num1 % num2;
            printf("Result: %d\n", result);
            break;
         default:
            printf("Invalid operator selected.\n");
            break;
      }

      // Check if result is prime
      if(isPrime(result)) {
         printf("%d is a prime number.\n", result);
      } else {
         printf("%d is not a prime number.\n", result);
      }

      // Generate and print fibonacci series up to result
      printf("Fibonacci series up to %d: ", result);
      for(int i = 1; i <= result; i++) {
         printf("%d ", fibonacci(i));
      }
      printf("\n\n");

   } while(1);

   return 0;
}