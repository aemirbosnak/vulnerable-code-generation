//FormAI DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>

int main() {
   int i, j, rows;
   printf("Enter number of rows: ");
   scanf("%d", &rows);

   for (i = 1; i <= rows; i++) {
      for (j = 1; j <= i; j++) {
         if(j == 1 || j == i || i == rows)
            printf("*");
         else
            printf(" ");
      }
      for (j = i + 1; j <= rows; j++) {
         printf(" ");
      }
      for (j = rows - 1; j >= i; j--) {
         printf(" ");
      }
      for (j = i; j >= 1; j--) {
         if(j == 1 || j == i || i == rows)
            printf("*");
         else
            printf(" ");
      }
      printf("\n");
   }

   for (i = rows-1; i >= 1; i--) {
      for (j = 1; j <= i; j++) {
         if(j == 1 || j == i || i == rows)
            printf("*");
         else
            printf(" ");
      }
      for (j = i + 1; j <= rows; j++) {
         printf(" ");
      }
      for (j = rows - 1; j >= i; j--) {
         printf(" ");
      }
      for (j = i; j >= 1; j--) {
         if(j == 1 || j == i || i == rows)
            printf("*");
         else
            printf(" ");
      }
      printf("\n");
   }

   return 0;
}