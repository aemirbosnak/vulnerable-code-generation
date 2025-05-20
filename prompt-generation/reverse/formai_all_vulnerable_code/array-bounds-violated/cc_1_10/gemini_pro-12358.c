//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid size
#define WIDTH 80
#define HEIGHT 25

// Number of generations
#define GENERATIONS 1000

// Probability of a cell being alive
#define PROBABILITY 0.5

// Grid of cells
int grid[WIDTH][HEIGHT];

// Function to print the grid
void printGrid() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", grid[i][j] ? 'O' : ' ');
    }
    printf("\n");
  }
}

// Function to update the grid
void updateGrid() {
  int newGrid[WIDTH][HEIGHT];

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      // Count the number of alive neighbors
      int neighbors = 0;
      for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
          if (k == 0 && l == 0) continue;
          if (i + k >= 0 && i + k < HEIGHT && j + l >= 0 && j + l < WIDTH) {
            neighbors += grid[i + k][j + l];
          }
        }
      }

      // Apply the rules of the game
      if (grid[i][j]) {
        newGrid[i][j] = (neighbors == 2 || neighbors == 3);
      } else {
        newGrid[i][j] = (neighbors == 3);
      }
    }
  }

  // Copy the new grid to the old grid
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      grid[i][j] = newGrid[i][j];
    }
  }
}

int main() {
  // Initialize the grid
  srand(time(NULL));
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      grid[i][j] = (rand() < RAND_MAX * PROBABILITY);
    }
  }

  // Print the grid
  printGrid();

  // Update the grid
  for (int i = 0; i < GENERATIONS; i++) {
    updateGrid();
  }

  // Print the grid
  printGrid();

  return 0;
}