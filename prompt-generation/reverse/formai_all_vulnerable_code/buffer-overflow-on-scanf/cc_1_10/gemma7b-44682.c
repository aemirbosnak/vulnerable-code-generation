//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define the Game of Life rules
int game_of_life(int **board, int rows, int cols) {
  int i, j, neighbor_count;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      neighbor_count = 0;
      // Check the neighbors to the current cell
      if (i > 0) neighbor_count++;
      if (i < rows - 1) neighbor_count++;
      if (j > 0) neighbor_count++;
      if (j < cols - 1) neighbor_count++;

      // Apply the Game of Life rules
      if (board[i][j] == 1 && neighbor_count < 2) board[i][j] = 0;
      if (board[i][j] == 0 && neighbor_count == 3) board[i][j] = 1;
    }
  }

  return 0;
}

int main() {
  int rows, cols, i, j;
  int **board;

  // Get the dimensions of the board
  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  // Allocate memory for the board
  board = (int **)malloc(rows * sizeof(int *));
  for (i = 0; i < rows; i++) board[i] = (int *)malloc(cols * sizeof(int));

  // Initialize the board
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      board[i][j] = 0;
    }
  }

  // Set the initial state of the board
  board[1][1] = 1;
  board[2][2] = 1;
  board[3][3] = 1;

  // Play the Game of Life
  game_of_life(board, rows, cols);

  // Print the final state of the board
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the board
  for (i = 0; i < rows; i++) free(board[i]);
  free(board);

  return 0;
}