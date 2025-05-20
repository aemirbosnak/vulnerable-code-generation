//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLUMNS 4

void printMatrix(int matrix[ROWS][COLUMNS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Let's create a 3x4 matrix and fill it with some curious numbers.
  int matrix[ROWS][COLUMNS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };

  // Let's introduce a peculiar character named Professor Perplexed.
  // He wants to explore the matrix in a unique way.
  int row, column;
  printf("Greetings, I am Professor Perplexed. I wish to traverse this matrix in a curious manner.\n");
  printf("Choose a starting row (0 to %d): ", ROWS - 1);
  scanf("%d", &row);
  printf("Choose a starting column (0 to %d): ", COLUMNS - 1);
  scanf("%d", &column);

  // Professor Perplexed begins his journey at the specified cell.
  printf("Professor Perplexed starts at (%d, %d).\n", row, column);

  // Now, let's define the curious rules of Professor Perplexed's movement.
  // He can move right, down, or diagonally down-right.
  // But there's a twist: he can only move to cells with even numbers.
  while (row < ROWS && column < COLUMNS) {
    // If the current cell has an even number, Professor Perplexed stays put.
    if (matrix[row][column] % 2 == 0) {
      printf("(%d, %d) is even. Professor Perplexed remains there.\n", row, column);
    } else {
      // If the current cell has an odd number, Professor Perplexed moves.
      if (column + 1 < COLUMNS && matrix[row][column + 1] % 2 == 0) {
        // Right move is possible.
        column++;
        printf("(%d, %d) is odd. Professor Perplexed moves right.\n", row, column);
      } else if (row + 1 < ROWS && matrix[row + 1][column] % 2 == 0) {
        // Down move is possible.
        row++;
        printf("(%d, %d) is odd. Professor Perplexed moves down.\n", row, column);
      } else if (row + 1 < ROWS && column + 1 < COLUMNS && matrix[row + 1][column + 1] % 2 == 0) {
        // Diagonal move is possible.
        row++;
        column++;
        printf("(%d, %d) is odd. Professor Perplexed moves diagonally down-right.\n", row, column);
      } else {
        // No valid moves possible.
        printf("(%d, %d) is odd and Professor Perplexed is perplexed. He gets stuck.\n", row, column);
        break;
      }
    }
  }

  // Professor Perplexed has finished his curious journey.
  printf("Professor Perplexed has completed his exploration. Thank you for your time.\n");

  return 0;
}