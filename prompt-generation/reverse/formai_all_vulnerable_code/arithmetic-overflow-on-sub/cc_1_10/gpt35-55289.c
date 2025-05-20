//FormAI DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>

/* This program demonstrates the use of bitwise operators */


/* Function to check if a number is odd */
int isOdd(int num) {
   return (num & 1);
}

/* Function to check if a number is even*/
int isEven(int num) {
   return !(num & 1);
}

/* Function to check if a number is power of 2 */
int isPowerOfTwo(int num) {
   return (num && !(num & (num - 1)));
}

/* Function to set nth bit of a number */
int setNthBit(int num, int n) {
   return (num | (1 << n));
}

/* Function to clear nth bit of a number */
int clearNthBit(int num, int n) {
   return (num & (~(1 << n)));
}

/* Function to toggle nth bit of a number */
int toggleNthBit(int num, int n) {
   return (num ^ (1 << n));
}

int main() {
   int num, n;
   
   printf("Enter a number: ");
   scanf("%d", &num);

   printf("\n");
   printf("%d is %s\n", num, isOdd(num) ? "odd" : "even");
   printf("%d is %s\n", num, isEven(num) ? "even" : "odd");

   printf("%d is %spower of 2\n", num, isPowerOfTwo(num) ? "" : "not ");

   printf("Enter the position of the bit you want to set (0-31): ");
   scanf("%d", &n);

   printf("%d with %dth bit SET: %d\n", num, n, setNthBit(num, n));
   

   printf("Enter the position of the bit you want to clear (0-31): ");
   scanf("%d", &n);

   printf("%d with %dth bit CLEAR: %d\n", num, n, clearNthBit(num, n));

   printf("Enter the position of the bit you want to toggle (0-31): ");
   scanf("%d", &n);

   printf("%d with %dth bit TOGGLED: %d\n", num, n, toggleNthBit(num, n));

   return 0;
}