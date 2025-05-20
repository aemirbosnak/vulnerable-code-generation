//FormAI DATASET v1.0 Category: Funny ; Style: portable
#include <stdio.h>

/* Function to print a diamond shape */
void diamond(int n) {
   int i, j, space = 1;
   space = n - 1;

   for (j = 1; j <= n; j++) {
      for (i = 1; i <= space; i++) {
         printf(" ");
      }

      space--;

      for (i = 1; i <= 2 * j - 1; i++) {
         printf("*");
      }
      printf("\n");
   }

   space = 1;

   for (j = 1; j <= n - 1; j++) {
      for (i = 1; i <= space; i++) {
         printf(" ");
      }
      space++;

      for (i = 1; i <= 2 * (n - j) - 1; i++) {
         printf("*");
      }
      printf("\n");
   }
}

int main() {

   int n;

   printf("Enter the number of rows for the diamond pattern: ");
   scanf("%d", &n);

   // Check if the number is odd or even
   if (n % 2 == 0) {
      printf("Please enter an odd number!\n");
      return 0;
   }

   diamond(n);

   return 0;
}