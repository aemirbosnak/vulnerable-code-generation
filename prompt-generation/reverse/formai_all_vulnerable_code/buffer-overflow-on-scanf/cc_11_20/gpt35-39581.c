//FormAI DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between minNum and maxNum
int randomNum(int minNum, int maxNum) {
   return (rand() % (maxNum - minNum + 1)) + minNum;
}

int main() {

   int gridSize = 4; // Grid size
   int grid[gridSize][gridSize]; // Array to store grid values
   int i, j, ii, jj, moves;

   srand(time(NULL)); // Initialize random seed

   // Assign random number pairs to the grid
   for(i=0; i<gridSize; i++){
      for(j=0; j<gridSize; j++){
         grid[i][j] = randomNum(1, 6);
      }
   }
   
   // Print the initial grid
   printf("Welcome to the Memory Game! Here is your grid:\n");
   for(i=0; i<gridSize; i++){
      for(j=0; j<gridSize; j++){
         printf("%d ", grid[i][j]);
      }
      printf("\n");
   }
   
   printf("You have 10 moves to uncover all pairs. Good Luck!\n");
   moves=0;
   
   // Start game loop
   do {
      int num1=0, num2=0, num3=0, num4=0;
      
      printf("Enter the indices of the first tile: ");
      scanf("%d %d", &i, &j);
      printf("Enter the indices of the second tile: ");
      scanf("%d %d", &ii, &jj);
      
      // Check whether the entered indices are adjacent
      if(i-ii>1 || i-ii<-1 || j-jj>1 || j-jj<-1 || i==ii || j==jj){
         printf("The two tiles are not adjacent! Try again.\n");
      }
      // Check whether the entered indices are valid
      else if(i<0 || i>=gridSize || j<0 || j>=gridSize || ii<0 || ii>=gridSize || jj<0 || jj>=gridSize){
         printf("Invalid indices! Try again.\n");
      }
      // Check if the two tiles match
      else if(grid[i][j] != grid[ii][jj]){
         printf("Wrong match! Try again.\n");
      }
      else {
         // Mark both tiles as uncovered
         grid[i][j] = 0;
         grid[ii][jj] = 0;
         moves++;
         
         // Print the current grid
         printf("You uncovered a pair!\n");
         for(i=0; i<gridSize; i++){
            for(j=0; j<gridSize; j++){
               printf("%d ", grid[i][j]);
            }
            printf("\n");
         }
      }
      
   } while(moves<10); // End game loop
   
   printf("You have made 10 moves. Game Over.");

   return 0;
}