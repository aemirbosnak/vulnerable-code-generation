//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>

int main() {
   int size, i;
   int fib[50];

   /* Input Size of Fibonacci Series */
   printf("Enter the size of Fibonacci Series: ");
   scanf("%d", &size);

   /* Generate Fibonacci Series and Store it in an Array */
   fib[0] = 0;
   fib[1] = 1;

   for(i=2; i<size; i++) {
      fib[i] = fib[i-1] + fib[i-2];
   }

   /* Output the Fibonacci Series */
   printf("\nThe Fibonacci Series of size %d is:\n", size);

   for(i=0; i<size; i++) {
      printf("%d ", fib[i]);
   }

   printf("\n\n");

   /* Visualize the Fibonacci Series */
   for(i=0; i<size; i++) {
      printf("|%d|", fib[i]);
   }

   printf("\n");

   for(i=0; i<size; i++) {
      printf("|%2d|", i);
   }

   printf("\n\n");

   /* Paranoid Checks */
   for(i=0; i<size; i++) {
      /* Check if Current Fibonacci Number is Greater than Previous Number */
      if(i > 0 && fib[i] < fib[i-1]) {
         printf("Paranoid Check Failed: Current Fibonacci Number (%d) is Less than Previous Fibonacci Number (%d)\n\n", fib[i], fib[i-1]);
         return 1;
      }

      /* Check if Current Fibonacci Number is Greater than or Equal to Zero */
      if(fib[i] < 0) {
         printf("Paranoid Check Failed: Current Fibonacci Number (%d) is Less than Zero\n\n", fib[i]);
         return 1;
      }

      /* Check if Current Fibonacci Number is Less than or Equal to 1 (except for the first two numbers) */
      if(i > 1 && fib[i] <= 1) {
         printf("Paranoid Check Failed: Current Fibonacci Number (%d) is Less than or Equal to One\n\n", fib[i]);
         return 1;
      }
   }

   printf("Paranoid Checks Successful!\n\n");

   return 0;
}