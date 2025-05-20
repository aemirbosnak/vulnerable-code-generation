//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: invasive
#include <stdio.h>

int main() {
   int n, i, t1 = 0, t2 = 1, nextTerm;

   printf("Enter the number of terms (must be between 1-20): ");
   scanf("%d", &n);

   if (n < 1 || n > 20) {
       printf("Invalid input. Terminating program.\n");
       return 1;
   }

   printf("The first %d terms of the Fibonacci sequence are:\n", n);

   for (i = 1; i <= n; ++i) {
       printf("%d, ", t1);
       nextTerm = t1 + t2;
       t1 = t2;
       t2 = nextTerm;
   }

   printf("\n\nFibonacci Sequence Visualization:\n");

   // Visualization
   int f[n][n];
   for(i = 0; i < n; ++i) {
       for(int j = 0; j < n; ++j) {
           f[i][j] = 0;
       }
   }

   int middle = n/2;
   int col = middle;
   for(i = 0; i < n; ++i) {
       f[i][col] = 1;
       if(i % 2 == 0) {
           col++;
       }
   }

   for(i = 0; i < n; ++i) {
       for(int j = 0; j < n; ++j) {
           if(f[i][j] == 1) {
               printf("# ");
           } else {
               printf(". ");
           }
       }
       printf("\n");
   }

   return 0;
}