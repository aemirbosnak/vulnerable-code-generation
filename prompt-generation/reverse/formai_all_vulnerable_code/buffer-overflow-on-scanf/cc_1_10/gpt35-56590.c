//FormAI DATASET v1.0 Category: Pattern printing ; Style: grateful
#include <stdio.h>

int main() {
   int i, j, rows, k, space;

   printf("Thank you for choosing this pattern printing program!\n");
   printf("Please input the number of rows you would like to print: ");
   scanf("%d", &rows);

   space = rows - 1;
   for (i = 1; i <= rows; i++) {
      for (j = 1; j <= space; j++) {
         printf(" ");
      }

      if (i == 1) {
         printf("*\n");
      } else {
         printf("*");

         for (k = 1; k < 2 * (i - 1); k++) {
            printf(" ");
         }

         printf("*\n");
      }

      space--;
   }

   space = 1;
   for (i = rows - 1; i >= 1; i--) {
      for (j = 1; j <= space; j++) {
         printf(" ");
      }

      if (i == 1) {
         printf("*\n");
      } else {
         printf("*");

         for (k = 1; k < 2 * (i - 1); k++) {
            printf(" ");
         }

         printf("*\n");
      }

      space++;
   }

   printf("Thank you for using this program! Have a great day!");

   return 0;
}