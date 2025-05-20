//FormAI DATASET v1.0 Category: Funny ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
   int x = 2;
   int y = 3;
   int z;

   printf("Let's do some math with x = %d and y = %d\n", x, y);

   z = x * y;
   printf("Multiplication of x and y is: %d\n", z);

   z = pow(y, x);
   printf("y raised to the power of x is: %d\n", z);

   z = sqrt(y);
   printf("The square root of y is: %d\n", z);

   z = abs(x - y);
   printf("The absolute value of the difference between x and y is: %d\n", z);

   printf("Let's see some more interesting math operations:\n");

   z = sin(x);
   printf("The sine of x is: %d\n", z);

   z = cos(y);
   printf("The cosine of y is: %d\n", z);

   z = pow(x, 2) + pow(y, 2);
   printf("The sum of the squares of x and y is: %d\n", z);

   printf("Now let's have some fun!\n");

   printf("Please enter a number: ");
   scanf("%d", &x);

   if (x % 2 == 0) {
      printf("You entered an even number!\n");
   } else {
      printf("You entered an odd number!\n");
   }

   printf("Please enter another number: ");
   scanf("%d", &y);

   z = pow(x, y);
   printf("%d raised to the power of %d is: %d\n", x, y, z);

   printf("Thanks for doing some math with me!\n");
   return 0;
}