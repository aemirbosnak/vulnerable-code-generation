//FormAI DATASET v1.0 Category: Arithmetic ; Style: mathematical
/*We are going to write a program to generate the N terms of the Fibonacci series, 
  store the terms in an array and then compute the sum of the even-valued terms
  of the series*/

#include <stdio.h>

int main()
{
   //Variables declaration 
   int n, i;
   long long fib[50]; // Array to store the terms of the Fibonacci sequence
   long long sum = 0;

   // Ask user to enter the number of terms to be generated
   printf("Enter the number of terms to generate in the Fibonacci sequence: ");
   scanf("%d", &n);

   // First two terms of the Fibonacci sequence
   fib[0] = 0;
   fib[1] = 1;

   // Generate the remaining terms of the sequence
   for(i=2; i<n; i++)
   {
      fib[i] = fib[i-1] + fib[i-2]; /*The ith term of the Fibonacci sequence is the sum of
                                      the (i-1)th and (i-2)th terms*/
   }

   // Compute the sum of the even-valued terms in the series
   for(i=0; i<n; i++)
   {
      if(fib[i] % 2 == 0) // Check if the term is even
      {
         sum+= fib[i]; /*If the term is even, add it to the sum. 
                        Otherwise, move to the next term in the series*/
      }
   }

   // Display the results
   printf("\nThe first %d terms of the Fibonacci series are: \n", n);

   for(i=0; i<n; i++)
   {
      printf("%lld ", fib[i]); // Display each term of the fibonacci sequence
   }

   printf("\n\nThe sum of the even-valued terms in the series is: %lld", sum);

   return 0;
}