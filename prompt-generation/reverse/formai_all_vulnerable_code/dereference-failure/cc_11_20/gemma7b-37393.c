//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

int main() {
  int **board = NULL;
  int rows, cols;
  scanf("Enter the number of rows: ", &rows);
  scanf("Enter the number of columns: ", &cols);
  board = (int**)malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    board[i] = (int*)malloc(cols * sizeof(int));
  }
  // Initialize the board
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      board[i][j] = 0;
    }
  }
  // Get the rules of the game
  int rule1, rule2, rule3;
  printf("Enter rule 1: ");
  scanf("%d", &rule1);
  printf("Enter rule 2: ");
  scanf("%d", &rule2);
  printf("Enter rule 3: ");
  scanf("%d", &rule3);
  // Simulate the game
  int generation = 0;
  while (1) {
    // Calculate the next generation
    int **next_board = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
      next_board[i] = (int*)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        int num_alive = 0;
        for (int r = -1; r <= 1; r++) {
          for (int c = -1; c <= 1; c++) {
            if (board[i + r][j + c] == 1) {
              num_alive++;
            }
          }
        }
        next_board[i][j] = (num_alive == rule1) || (num_alive == rule2) || (num_alive == rule3);
      }
    }
    // Copy the next generation to the board
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        board[i][j] = next_board[i][j];
      }
    }
    // Free the memory of the next generation
    for (int i = 0; i < rows; i++) {
      free(next_board[i]);
    }
    free(next_board);
    // Increment the generation
    generation++;
    // Check if the game is over
    if (generation >= 10) {
      break;
    }
  }
  // Print the final board
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
  // Free the memory of the board
  for (int i = 0; i < rows; i++) {
    free(board[i]);
  }
  free(board);

  return 0;
}