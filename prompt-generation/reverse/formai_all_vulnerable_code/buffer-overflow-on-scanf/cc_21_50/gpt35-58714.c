//FormAI DATASET v1.0 Category: Pattern printing ; Style: configurable
#include<stdio.h>

int main() {
   int i, j, k;
   int size, flag;

   // Get size of pattern from user
   printf("Enter size of pattern: ");
   scanf("%d", &size);

   // Get flag from user (1 for increasing pattern and 0 for decreasing pattern)
   printf("Enter flag (1 for increasing and 0 for decreasing): ");
   scanf("%d", &flag);

   if (flag) { // If flag is 1, print increasing pattern
      for (i = 1; i <= size; i++) {
         for (j = 1; j <= i; j++) {
            printf("*");
         }
         printf("\n");
      }
   }
   else { // If flag is 0, print decreasing pattern
      for (i = size; i >= 1; i--) {
         for (j = 1; j <= i; j++) {
            printf("*");
         }
         printf("\n");
      }
   }

   // Print a horizontal line
   for (i = 1; i <= 3 * size; i++) {
      printf("-");
   }
   printf("\n");

   if (flag) { // If flag is 1, print increasing pattern
      for (i = 1; i <= size; i++) {
         for (j = 1; j <= size - i; j++) {
            printf(" ");
         }
         for (k = 1; k <= i; k++) {
            printf("* ");
         }
         printf("\n");
      }
   }
   else { // If flag is 0, print decreasing pattern
      for (i = size; i >= 1; i--) {
         for (j = 1; j <= size - i; j++) {
            printf(" ");
         }
         for (k = 1; k <= i; k++) {
            printf("* ");
         }
         printf("\n");
      }
   }

   // Print a horizontal line
   for (i = 1; i <= 3 * size; i++) {
      printf("-");
   }
   printf("\n");

   if (flag) { // If flag is 1, print increasing pattern
      for (i = size; i >= 1; i--) {
         for (j = 1; j <= size - i; j++) {
            printf(" ");
         }
         for (k = 1; k <= i; k++) {
            printf("* ");
         }
         printf("\n");
      }
   }
   else { // If flag is 0, print decreasing pattern
      for (i = 1; i <= size; i++) {
         for (j = 1; j <= size - i; j++) {
            printf(" ");
         }
         for (k = 1; k <= i; k++) {
            printf("* ");
         }
         printf("\n");
      }
   }

   return 0;
}