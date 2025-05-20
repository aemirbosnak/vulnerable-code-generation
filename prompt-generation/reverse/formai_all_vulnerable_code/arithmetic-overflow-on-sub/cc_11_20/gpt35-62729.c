//FormAI DATASET v1.0 Category: Pattern printing ; Style: imaginative
#include <stdio.h>

int main() {

   int rows, i, j, k;
   char letter = 'A';

   printf("Enter the number of rows: ");
   scanf("%d", &rows);

   for(i = 1; i <= rows; i++) {

      for(j = 1; j <= i; j++) {
         printf("%c ", letter++);
         if(letter > 'Z') {
            letter = 'A';
         }
      }

      for(k = i+1; k <= rows; k++) {
         printf("%c ", letter++);
         if(letter > 'Z') {
            letter = 'A';
         }
      }

      printf("\n");
   }
   
   for(i = rows-1; i >= 1; i--) {

      for(j = 1; j <= i; j++) {
         printf("%c ", letter++);
         if(letter > 'Z') {
            letter = 'A';
         }
      }

      for(k = i+1; k <= rows; k++) {
         printf("%c ", letter++);
         if(letter > 'Z') {
            letter = 'A';
         }
      }

      printf("\n");
   }

   return 0;
}