//FormAI DATASET v1.0 Category: Game ; Style: automated
#include <stdio.h>

#define SIZE 3

int main(void) {
   int board[SIZE][SIZE] = { {0,0,0}, {0,0,0}, {0,0,0} };
   int x, y, turn = 0;

   // Game loop
   while (1) {
       // Print the board
       printf("\n\n\n\n\n");
       printf("        1   2   3\n");
       printf("      +---+---+---+\n");
       for (x = 0; x < SIZE; x++) {
           printf("    %d |", x + 1);
           for (y = 0; y < SIZE; y++) {
               printf(" %c |", board[x][y] == 0 ? ' ' : (board[x][y] == 1 ? 'X' : 'O'));
           }
           printf("\n");
           printf("      +---+---+---+\n");
       }

       // Check if there's a winner
       int winner = 0;
       for (int i = 0; i < SIZE; i++) {
           // Check rows
           if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
               winner = board[i][0];
           }
           // Check columns
           if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
               winner = board[0][i];
           }
       }
       // Check diagonal
       if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
           winner = board[0][0];
       }
       if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
           winner = board[0][2];
       }
       if (winner != 0) {
           printf("\n\n\n\n\n\n\n\n");
           printf("   +-------------------+\n");
           printf("   |    GAME OVER!     |\n");
           printf("   +-------------------+\n");
           printf("   | Player %d wins!   |\n", winner);
           printf("   +-------------------+\n");
           printf("\n\n\n\n\n\n\n\n");
           return 0;
       }

       // Check for tie
       int tie = 1;
       for (x = 0; x < SIZE; x++) {
           for (y = 0; y < SIZE; y++) {
               if (board[x][y] == 0) {
                   tie = 0;
               }
           }
       }
       if (tie == 1) {
           printf("\n\n\n\n\n\n\n\n");
           printf("   +-------------------+\n");
           printf("   |    GAME OVER!     |\n");
           printf("   +-------------------+\n");
           printf("   |  No one won! :-(  |\n");
           printf("   +-------------------+\n");
           printf("\n\n\n\n\n\n\n\n");
           return 0;
       }

       // Get player move
       int row, col;
       do {
           printf("\n\n\n\n\n");
           printf("Player %d's turn! Enter row (1-3): ", turn % 2 + 1);
           scanf("%d", &row);
           printf("Player %d's turn! Enter column (1-3): ", turn % 2 + 1);
           scanf("%d", &col);
       } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != 0);

       // Set the new move on the board
       board[row - 1][col - 1] = turn % 2 + 1;

       // Switch to next player's turn
       turn++;
   }
}