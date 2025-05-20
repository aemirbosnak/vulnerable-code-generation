//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
   int n, i, j, k;
   printf("Enter a positive number: ");
   scanf("%d", &n);
   
   // Print Pattern A
   printf("Pattern A:\n");
   for (i = 1; i <= n; i++) {
      for (j = 1; j <= n-i+1; j++) {
         printf("*");
      }
      printf("\n");
   }

   // Print Pattern B
   printf("Pattern B:\n");
   for (i = 1; i <= n; i++) {
      for (j = 1; j <= n-i+1; j++) {
         printf("%d", j);
      }
      printf("\n");
   }

   // Print Pattern C
   printf("Pattern C:\n");
   for (i = n; i >= 1; i--) {
      for (j = 1; j <= i-1; j++) {
         printf(" ");
      }
      for (k = 1; k <= n-i+1; k++) {
         printf("*");
      }
      printf("\n");
   }

   // Print Pattern D
   printf("Pattern D:\n");
   for (i = 1; i <= n; i++) {
      for (j = 1; j <= i-1; j++) {
         printf(" ");
      }
      for (k = 1; k <= n-i+1; k++) {
         printf("%d", k);
      }
      printf("\n");
   }

   return 0;
}