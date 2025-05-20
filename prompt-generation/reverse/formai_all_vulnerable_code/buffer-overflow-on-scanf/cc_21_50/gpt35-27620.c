//FormAI DATASET v1.0 Category: Table Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int i, j, num, player1 = 0, player2 = 0, player1_turn = 1;
   srand(time(NULL)); // Set random seed based on current time

   int board[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Initialize board to all empty squares

   printf("Welcome to C Table Game!\n\n");

   // Main game loop
   for (i = 0; i < 10; i++) {
      printf("---------------\n");
      printf("Board:\n");
      printf(" 1  2  3  4  5\n"); // Print board positions
      for (j = 0; j < 5; j++) {
         printf("|%c|", board[j] == 1 ? 'X' : (board[j] == 2 ? 'O' : ' '));
      }
      printf("\n");
      for (j = 5; j < 10; j++) {
         printf("|%c|", board[j] == 1 ? 'X' : (board[j] == 2 ? 'O' : ' '));
      }
      printf("\n\n");

      if (player1_turn) {
         printf("Player 1's turn:\n");
      } else {
         printf("Player 2's turn:\n");
      }
      printf("Enter a position to place your piece (1-5): ");
      scanf("%d", &num);

      while (num < 1 || num > 5 || board[num - 1] != 0) {
         printf("Invalid move. Enter a position to place your piece (1-5): ");
         scanf("%d", &num);
      }

      // Update board with player's move
      if (player1_turn) {
         board[num - 1] = 1; // Player 1 is X
      } else {
         board[num - 1] = 2; // Player 2 is O
      }

      // Check for win condition
      if ((board[0] == board[1] && board[1] == board[2] && board[2] == board[3] && board[3] == board[4] && board[4] != 0) ||
          (board[5] == board[6] && board[6] == board[7] && board[7] == board[8] && board[8] == board[9] && board[9] != 0)) {
         // Horizontal win condition
         if (player1_turn) {
            printf("Player 1 wins!\n");
            player1++;
         } else {
            printf("Player 2 wins!\n");
            player2++;
         }
         break;
      } else if ((board[0] == board[5] && board[5] == board[9] && board[9] != 0) ||
                 (board[1] == board[6] && board[6] == board[9] && board[9] == board[3] && board[3] != 0) ||
                 (board[2] == board[7] && board[7] == board[9] && board[9] == board[4] && board[4] != 0) ||
                 (board[3] == board[8] && board[8] == board[9] && board[9] == board[5] && board[5] != 0)) {
         // Diagonal win condition
         if (player1_turn) {
            printf("Player 1 wins!\n");
            player1++;
         } else {
            printf("Player 2 wins!\n");
            player2++;
         }
         break;
      } else if (i == 9) {
         // Board is full with no winner
         printf("Tie game.\n");
         break;
      }

      player1_turn = !player1_turn; // Switch players
   }

   // Print final score
   printf("\nFinal score:\n");
   printf("Player 1: %d\n", player1);
   printf("Player 2: %d\n", player2);

   return 0;
}