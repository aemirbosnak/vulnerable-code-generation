//FormAI DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_MOVES 16

int main() {
   int board[BOARD_SIZE][BOARD_SIZE];
   int moves[MAX_MOVES];
   int moveCount = 0;
   int row1, row2, col1, col2;
   int i, j;

   srand(time(0));
   
   // Initialize the board with random numbers
   for (i = 0; i < BOARD_SIZE; i++) {
      for (j = 0; j < BOARD_SIZE; j++) {
         board[i][j] = rand() % 10;
      }
   }

   // Print the board
   printf("Initial Board:\n");
   for (i = 0; i < BOARD_SIZE; i++) {
      for (j = 0; j < BOARD_SIZE; j++) {
         printf("%d ", board[i][j]);
      }
      printf("\n");
   }

   // Ask the user to enter two positions to swap
   while (moveCount < MAX_MOVES) {
      printf("Enter two positions to swap (row1 col1 row2 col2): ");
      scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

      // Check if the positions are valid
      if (row1 >= 0 && row1 < BOARD_SIZE &&
          col1 >= 0 && col1 < BOARD_SIZE &&
          row2 >= 0 && row2 < BOARD_SIZE &&
          col2 >= 0 && col2 < BOARD_SIZE) {
         // Perform the swap
         int temp = board[row1][col1];
         board[row1][col1] = board[row2][col2];
         board[row2][col2] = temp;

         // Record the move
         moves[moveCount] = (row1 * 1000) + (col1 * 100) + (row2 * 10) + col2;
         moveCount++;

         // Print the board
         printf("\nBoard after swap:\n");
         for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
               printf("%d ", board[i][j]);
            }
            printf("\n");
         }
      } else {
         printf("Invalid positions\n");
      }
   }

   // Print the moves
   printf("\nMoves:\n");
   for (i = 0; i < MAX_MOVES; i++) {
      printf("%d %d %d %d\n",
             moves[i] / 1000, (moves[i] / 100) % 10,
             (moves[i] / 10) % 10, moves[i] % 10);
   }

   return 0;
}