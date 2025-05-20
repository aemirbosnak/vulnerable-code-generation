//FormAI DATASET v1.0 Category: Table Game ; Style: mathematical
#include <stdio.h>

int main() {
   int matrix[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
   int player = 1;
   int row, column;
   int i, j;

   printf("Welcome to the C Table Game!\n");

   for(i=0; i<3; i++) {
      for(j=0; j<3; j++)
         printf("| %d |", matrix[i][j]);
      printf("\n");
   }

   while(1) {
      printf("Player %d, enter a row and column: ", player);
      scanf("%d %d", &row, &column);

      if(matrix[row-1][column-1] == 0) {
         if(player == 1) {
            matrix[row-1][column-1] = 1;
            player = 2;
         }
         else {
            matrix[row-1][column-1] = 2;
            player = 1;
         }
      }
      else {
         printf("The location is already used. Try again.\n");
         continue;
      }

      for(i=0; i<3; i++) {
         for(j=0; j<3; j++)
            printf("| %d |", matrix[i][j]);
         printf("\n");
      }

      for(i=0; i<3; i++) {
         if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) {
            if(matrix[i][0] == 1)
               printf("Player 1 wins.\n");
            else if (matrix[i][0] == 2)
               printf("Player 2 wins.\n");
            return 0;
         }
      }

      for(i=0; i<3; i++) {
         if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) {
            if(matrix[0][i] == 1)
               printf("Player 1 wins.\n");
            else if (matrix[0][i] == 2)
               printf("Player 2 wins.\n");
            return 0;
         }
      }

      if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
         if(matrix[0][0] == 1)
            printf("Player 1 wins.\n");
         else if (matrix[0][0] == 2)
            printf("Player 2 wins.\n");
         return 0;
      }

      if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
         if(matrix[0][2] == 1)
            printf("Player 1 wins.\n");
         else if (matrix[0][2] == 2)
            printf("Player 2 wins.\n");
         return 0;
      }
   }

   return 0;
}