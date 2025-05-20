//FormAI DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int row, col, i, j, player = 1, move, winner = 0;
   char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
   
   // Seed the random number generator
   srand(time(NULL));
   
   printf("Welcome to the C Table Game!\n");
   printf("Player 1: X\nPlayer 2: O\n\n");
   
   // Print the initial game board
   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         printf(" %c ", board[i][j]);
         if (j < 2) printf("|");
      }
      printf("\n");
      if (i < 2) printf("---|---|---\n");
   }
   
   // Player 1 goes first
   player = 1;
   
   while (winner == 0) {
      if (player == 1) {
         // Player 1's turn
         printf("\nPlayer 1, enter a move (1-9): ");
         scanf("%d", &move);
         
         // Check if the move is valid
         if (move < 1 || move > 9) {
            printf("Invalid move, please try again.\n");
            continue;
         }
         
         row = (move - 1) / 3;
         col = (move - 1) % 3;
         
         if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Square already taken, please try again.\n");
            continue;
         }
         
         board[row][col] = 'X';
      } else {
         // Player 2's turn
         printf("\nPlayer 2's turn (computer)...\n");
         
         // Generate a random move
         move = rand() % 9 + 1;
         
         row = (move - 1) / 3;
         col = (move - 1) % 3;
         
         if (board[row][col] == 'X' || board[row][col] == 'O') {
            continue;
         }
         
         board[row][col] = 'O';
         printf("Computer picks: %d\n", move);
      }
      
      // Print the updated game board
      for (i = 0; i < 3; i++) {
         for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
         }
         printf("\n");
         if (i < 2) printf("---|---|---\n");
      }
      
      // Check if there is a winner or a tie
      for (i = 0; i < 3; i++) {
         if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner = player;
         }
      }
      
      for (j = 0; j < 3; j++) {
         if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            winner = player;
         }
      }
      
      if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
         winner = player;
      }
      
      if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
         winner = player;
      }
      
      // Switch to the other player
      player = (player == 1) ? 2 : 1;
   }
   
   // Print the winner
   if (winner == 1) {
      printf("\nCongratulations! Player 1 wins!\n");
   } else {
      printf("\nSorry, player 2 (computer) wins!\n");
   }
   
   return 0;
}