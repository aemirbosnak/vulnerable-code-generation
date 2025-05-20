//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>

int main() {
   int board[3][3] = {0}; // Initialize the board with empty spaces
   int player = 1;
   int row, col, move;

   printf("Welcome to the Tic Tac Toe game!\n");

   for(int i = 0; i < 9; i++) {
      printf("Player %d, enter your move: ", player);
      scanf("%d", &move);

      row = (move - 1) / 3;
      col = (move - 1) % 3;

      if(board[row][col] == 0) {
         board[row][col] = player;
      } else {
         printf("Invalid move!\n");
         i--;
         continue;
      }

      // Print the board
      printf("   1 2 3\n");
      printf("  -------\n");
      for(int j = 0; j < 3; j++) {
         printf("%d |", j+1);
         for(int k = 0; k < 3; k++) {
            if(board[j][k] == 0) {
               printf(" ");
            } else if(board[j][k] == 1) {
               printf("X");
            } else {
               printf("O");
            }
            printf("|");
         }
         printf("\n");
         printf("  -------\n");
      }

      // Check if player wins
      if(board[row][0] == player && board[row][1] == player && board[row][2] == player) {
         printf("Player %d wins!\n", player);
         break;
      }
      if(board[0][col] == player && board[1][col] == player && board[2][col] == player) {
         printf("Player %d wins!\n", player);
         break;
      }
      if(row == col && board[0][0] == player && board[1][1] == player && board[2][2] == player) {
         printf("Player %d wins!\n", player);
         break;
      }
      if(row + col == 2 && board[0][2] == player && board[1][1] == player && board[2][0] == player) {
         printf("Player %d wins!\n", player);
         break;
      }

      // Switch players
      if(player == 1) {
         player = 2;
      } else {
         player = 1;
      }
   }

   printf("Game over!\n");

   return 0;
}