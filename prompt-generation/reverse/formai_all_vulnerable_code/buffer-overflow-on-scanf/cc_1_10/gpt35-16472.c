//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>

int factorial(int n) {
   if(n==0 || n==1) {
      return 1;
   }
   else {
      return n * factorial(n-1);
   }
}

int fibonacci(int n) {
   if(n<=1) {
      return n;
   }
   else {
      return fibonacci(n-1) + fibonacci(n-2);
   }
}

int gcd(int a, int b) {
   if(a == 0) {
      return b;
   }
   else {
      return gcd(b % a, a);
   }
}

void printArray(int *arr, int size) {
   if(size == 0) {
      return;
   }
   else {
      printf("%d ", *(arr + size - 1));
      printArray(arr, size - 1);
   }
}

int main() {
   int choice, n, a, b;
   int arr[] = {1, 2, 3, 4, 5};
   int size = sizeof(arr)/sizeof(int);

   printf("Enter choice:\n");
   printf("1. Factorial\n");
   printf("2. Fibonacci\n");
   printf("3. GCD\n");
   printf("4. Print array in reverse\n");

   scanf("%d", &choice);

   switch(choice) {

      case 1: 
         printf("Enter the number:\n");
         scanf("%d", &n);
         printf("Factorial of %d is %d", n, factorial(n));
         break;

      case 2:
         printf("Enter the number:\n");
         scanf("%d", &n);
         printf("Fibonacci of %d is %d", n, fibonacci(n));
         break;

      case 3:
         printf("Enter the two numbers:\n");
         scanf("%d %d", &a, &b);
         printf("GCD of %d and %d is %d", a, b, gcd(a, b));
         break;

      case 4:
         printf("Array in reverse is:\n");
         printArray(arr, size);
         break;

      default:
         printf("Invalid choice");
         break;

   }

   return 0;
}