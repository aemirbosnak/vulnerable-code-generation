//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// These are the 3 states of a cell
#define ALIVE     1 // Cell is alive
#define DEAD      0 // Cell is dead
#define NEWBORN   2 // Cell was dead but is now alive

// Maximum number of rows and columns
#define MAX_ROWS    100
#define MAX_COLS    100

// The game board
int board[MAX_ROWS][MAX_COLS];

// The number of rows and columns in the game board
int num_rows, num_cols;

// The number of generations to run the game for
int num_generations;

// Function to initialize the game board
void init_board() {
  // Set all cells to dead
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      board[i][j] = DEAD;
    }
  }

  // Set some cells to alive
  board[10][10] = ALIVE;
  board[10][11] = ALIVE;
  board[10][12] = ALIVE;
}

// Function to display the game board
void display_board() {
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      if (board[i][j] == ALIVE) {
        printf("O");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Function to count the number of alive neighbors of a cell
int count_neighbors(int row, int col) {
  int count = 0;

  // Check all 8 neighbors of the cell
  for (int i = row - 1; i <= row + 1; i++) {
    for (int j = col - 1; j <= col + 1; j++) {
      // Make sure the neighbor is within the bounds of the board
      if (i >= 0 && i < num_rows && j >= 0 && j < num_cols) {
        // If the neighbor is alive, increment the count
        if (board[i][j] == ALIVE) {
          count++;
        }
      }
    }
  }

  // Subtract 1 from the count to account for the cell itself
  return count - (board[row][col] == ALIVE);
}

// Function to update the game board to the next generation
void update_board() {
  // Create a temporary board to store the new generation
  int new_board[MAX_ROWS][MAX_COLS];

  // Copy the current board to the temporary board
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      new_board[i][j] = board[i][j];
    }
  }

  // Update each cell of the temporary board based on the rules of the game
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      int num_neighbors = count_neighbors(i, j);

      // If the cell is alive and has 2 or 3 alive neighbors, it remains alive
      if (board[i][j] == ALIVE && (num_neighbors == 2 || num_neighbors == 3)) {
        new_board[i][j] = ALIVE;
      }
      // If the cell is dead and has exactly 3 alive neighbors, it becomes alive
      else if (board[i][j] == DEAD && num_neighbors == 3) {
        new_board[i][j] = NEWBORN;
      }
      // Otherwise, the cell dies
      else {
        new_board[i][j] = DEAD;
      }
    }
  }

  // Copy the temporary board to the current board
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      board[i][j] = new_board[i][j];
    }
  }
}

// Main function
int main() {
  // Get the number of rows, columns, and generations from the user
  printf("Enter the number of rows: ");
  scanf("%d", &num_rows);

  printf("Enter the number of columns: ");
  scanf("%d", &num_cols);

  printf("Enter the number of generations: ");
  scanf("%d", &num_generations);

  // Initialize the game board
  init_board();

  // Display the initial game board
  printf("Initial game board:\n");
  display_board();

  // Run the game for the specified number of generations
  for (int i = 0; i < num_generations; i++) {
    // Update the game board to the next generation
    update_board();

    // Display the game board after each generation
    printf("Generation %d:\n", i + 1);
    display_board();
  }

  return 0;
}