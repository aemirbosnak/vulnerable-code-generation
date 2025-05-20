//FormAI DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int grid[3][3];
   int i, j;
    
   printf("Welcome to the C Table Game!\n");
   printf("-----------------------------\n");
    
   srand((unsigned) time(NULL));
    
   // Initialize the grid
   for(i = 0; i < 3; i++) {
      for(j = 0; j < 3; j++) {
         grid[i][j] = 0;
      }
   }
    
   // Display the empty grid
   for(i = 0; i < 3; i++) {
      printf("\n-------------\n");
      for(j = 0; j < 3; j++) {
         printf("| %d ", grid[i][j]);
      }
      printf("|");
   }
   printf("\n-------------\n");
    
   // Start the game
   int player = 1;
   int winner = 0;
   int turn = 0;
   int row, col;
    
   while(winner == 0 && turn < 9) {
      printf("\nPlayer %d, enter a row (0, 1, or 2): ", player);
      scanf("%d", &row);
      printf("Player %d, enter a column (0, 1, or 2): ", player);
      scanf("%d", &col);
      if(grid[row][col] == 0) {
         grid[row][col] = player;
         turn++;
         // Display the updated grid
         for(i = 0; i < 3; i++) {
            printf("\n-------------\n");
            for(j = 0; j < 3; j++) {
               printf("| %d ", grid[i][j]);
            }
            printf("|");
         }
         printf("\n-------------\n");
         // Check for a winner
         for(i = 0; i < 3; i++) {
            if(grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) {
               winner = player;
            }
            if(grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) {
               winner = player;
            }
         }
         if(grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) {
            winner = player;
         }
         if(grid[2][0] == player && grid[1][1] == player && grid[0][2] == player) {
            winner = player;
         }
         // Switch player
         if(player == 1) {
            player = 2;
         } else {
            player = 1;
         }
      } else {
         printf("\nThat spot is already taken. Try again.\n");
      }
   }
   // End of game
   if(winner) {
      printf("\nCongratulations! Player %d wins!\n", winner);
   } else {
      printf("\nIt's a tie!\n");
   }
   return 0;
}