//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Initial grid
  int grid[5][5] = {
      0, 0, 0, 0, 0,
      0, 0, 0, 0, 0,
      0, 0, 0, 0, 0,
      0, 0, 0, 0, 0,
      0, 0, 0, 0, 0
  };
  
  // Get user input
  printf("Enter the initial grid:\n");
  int i, j;
  for(i = 0; i < 5; i++) {
    for(j = 0; j < 5; j++) {
      printf("Enter the value for cell (%d,%d): ", i, j);
      scanf("%d", &grid[i][j]);
    }
    printf("\n");
  }
  
  // Print initial grid
  printf("\nInitial grid:\n");
  for(i = 0; i < 5; i++) {
    for(j = 0; j < 5; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
  
  // Game of Life rules
  for(i = 0; i < 5; i++) {
    for(j = 0; j < 5; j++) {
      // Rule 1: Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
      int neighbors = 0;
      for(int k = -1; k <= 1; k += 2) {
        for(int l = -1; l <= 1; l += 2) {
          if(i+k >= 0 && i+k < 5 && j+l >= 0 && j+l < 5) {
            if(grid[i+k][j+l] == 1) {
              neighbors++;
            }
          }
        }
      }
      
      // Rule 2: Any live cell with two or three live neighbours lives on to the next generation.
      if(grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
        grid[i][j] = 1;
      } else {
        grid[i][j] = 0;
      }
    }
  }
  
  // Print updated grid
  printf("\nUpdated grid:\n");
  for(i = 0; i < 5; i++) {
    for(j = 0; j < 5; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}