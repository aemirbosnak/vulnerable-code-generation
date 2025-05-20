//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>

int count(int n) {
   if (n == 0)
      return 0;
   else
      return 1 + count(n - 1);
}

int fib(int n) {
   if (n == 1 || n == 2)
      return 1;
   else
      return fib(n-1) + fib(n-2);
}

int fact(int n) {
   if (n == 0)
      return 1;
   else
      return n * fact(n-1);
}

int main() {
   int choice;
   int num;

   printf("Select a function to run:\n");
   printf("1. Count\n");
   printf("2. Fibonacci\n");
   printf("3. Factorial\n");

   scanf("%d", &choice);

   switch (choice) {
      case 1:
         printf("Enter a number to count from:\n");
         scanf("%d", &num);
         printf("Count from %d to 1:\n", num);
         printf("Count: %d", count(num));
         break;
      case 2:
         printf("Enter a number to get the Fibonacci sequence until:\n");
         scanf("%d", &num);
         printf("The Fibonacci sequence until %d:\n", num);
         for (int i = 1; i <= num; i++) {
            printf("%d ", fib(i));
         }
         break;
      case 3:
         printf("Enter a number to get the factorial of:\n");
         scanf("%d", &num);
         printf("The factorial of %d is: %d", num, fact(num));
         break;
      default:
         printf("Invalid choice.");
   }

   return 0;
}