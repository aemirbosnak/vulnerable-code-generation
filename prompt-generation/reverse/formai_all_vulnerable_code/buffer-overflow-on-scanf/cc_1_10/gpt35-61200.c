//FormAI DATASET v1.0 Category: Educational ; Style: peaceful
/* Peaceful C Program */

#include<stdio.h>

// Function to check if a number is prime or not
int isPrime(int num)
{
   int i, flag = 1;

   for(i=2; i<=num/2; i++)
   {
      if(num%i == 0)
      {
         flag = 0;
         break;
      }
   }

   if(flag == 1)
      return 1;
   else
      return 0;
}

// Function to print the prime numbers within a range
void printPrimeRange(int start, int end)
{
   int i;
   printf("Prime numbers between %d and %d are: \n", start, end);

   for(i=start; i<=end; i++)
   {
      if(isPrime(i))
         printf("%d ", i);
   }
}

int main()
{
   int start, end;

   printf("Enter the starting number: ");
   scanf("%d", &start);

   printf("Enter the ending number: ");
   scanf("%d", &end);

   printPrimeRange(start, end);

   return 0;
}