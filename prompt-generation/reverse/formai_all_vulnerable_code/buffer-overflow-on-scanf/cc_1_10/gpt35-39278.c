//FormAI DATASET v1.0 Category: Educational ; Style: recursive
#include<stdio.h>

int sum(int n) {
   if(n != 0)
       return n + sum(n-1);
   else
       return n;
}

int factorial(int n) {
   if(n == 0)
       return 1;
   else
       return n * factorial(n-1);
}

int fibonacci(int n) {
   if(n == 0)
       return 0;
   else if(n == 1 || n == 2)
       return 1;
   else
       return fibonacci(n-1) + fibonacci(n-2);
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
   if(n == 1) {
       printf("\nMove disk 1 from rod %c to rod %c", from_rod, to_rod);
       return;
   }
   towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
   printf("\nMove disk %d from rod %c to rod %c", n, from_rod, to_rod);
   towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main() {
   int choice, n;
   printf("Enter your choice:\n1. Sum of n natural numbers\n2. Factorial of a number\n3. Fibonacci series upto n terms\n4. Tower of Hanoi\n");
   scanf("%d", &choice);

   switch(choice) {
     case 1: 
           printf("Enter a positive integer: ");
           scanf("%d", &n);
           printf("Sum = %d", sum(n));
           break;

     case 2: 
           printf("Enter a positive integer: ");
           scanf("%d", &n);
           printf("Factorial = %d", factorial(n));
           break;

     case 3: 
           printf("Enter a positive integer: ");
           scanf("%d", &n);
           printf("Fibonacci series: ");
           for(int i = 0; i < n; i++)
               printf("%d ", fibonacci(i));
           break;

     case 4: 
           printf("Enter the number of disks: ");
           scanf("%d", &n);
           towerOfHanoi(n, 'A', 'C', 'B');
           break;

     default: 
           printf("Invalid choice!");
   }
   return 0;
}