//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand((unsigned int)time(NULL)); // Seed the random number generator

   // Define the haunted house layout
   char house[5][5] = {
      {' ', ' ', ' ', ' ', ' '},
      {'X', '.', '.', '.', 'X'},
      {'X', '.', '.', '.', 'X'},
      {'X', '.', '.', '.', 'X'},
      {'X', 'X', 'X', 'X', 'X'}
   };

   int playerX = 1, playerY = 1; // Starting position for the player
   int ghostX = 3, ghostY = 3; // Starting position for the ghost

   // Game loop
   while (1) {
      // Print the house layout
      for (int y = 0; y < 5; y++) {
         for (int x = 0; x < 5; x++) {
            if (x == playerX && y == playerY) { // Print the player symbol at the player's position
               printf("O");
            } else if (x == ghostX && y == ghostY) { // Print the ghost symbol at the ghost's position
               printf("G");
            } else {
               printf("%c", house[y][x]);
            }
         }
         printf("\n");
      }

      // Check if the player and ghost are on the same position
      if (playerX == ghostX && playerY == ghostY) {
         printf("You were caught by the ghost! Game over.\n");
         break;
      }

      // Ask the player to input their next move
      char input;
      printf("Enter your next move [WASD]: ");
      scanf(" %c", &input);

      // Move the player according to the input
      switch (input) {
         case 'W': // Move up
            if (playerY > 0 && house[playerY-1][playerX] != 'X') {
               playerY--;
            }
            break;
         case 'A': // Move left
            if (playerX > 0 && house[playerY][playerX-1] != 'X') {
               playerX--;
            }
            break;
         case 'S': // Move down
            if (playerY < 4 && house[playerY+1][playerX] != 'X') {
               playerY++;
            }
            break;
         case 'D': // Move right
            if (playerX < 4 && house[playerY][playerX+1] != 'X') {
               playerX++;
            }
            break;
      }

      // Move the ghost randomly
      int ghostMove = rand() % 4;
      switch (ghostMove) {
         case 0: // Move up
            if (ghostY > 0 && house[ghostY-1][ghostX] != 'X') {
               ghostY--;
            }
            break;
         case 1: // Move left
            if (ghostX > 0 && house[ghostY][ghostX-1] != 'X') {
               ghostX--;
            }
            break;
         case 2: // Move down
            if (ghostY < 4 && house[ghostY+1][ghostX] != 'X') {
               ghostY++;
            }
            break;
         case 3: // Move right
            if (ghostX < 4 && house[ghostY][ghostX+1] != 'X') {
               ghostX++;
            }
            break;
      }
   }

   return 0;
}