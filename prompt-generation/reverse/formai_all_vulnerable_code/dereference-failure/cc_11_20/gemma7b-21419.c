//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
  int **board = NULL;
  int rows, cols;

  // Allocate memory for the game board
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);
  board = (int **)malloc(rows * sizeof(int *) + rows);
  for (int i = 0; i < rows; i++) {
    board[i] = (int *)malloc(cols * sizeof(int) + cols);
  }

  // Initialize the game board
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      board[r][c] = 0;
    }
  }

  // Play the game of life
  int generation = 0;
  while (1) {
    // Display the game board
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        printf("%d ", board[r][c]);
      }
      printf("\n");
    }

    // Calculate the next generation
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int num_alive = 0;
        for (int dr = -1; dr <= 1; dr++) {
          for (int dc = -1; dc <= 1; dc++) {
            if (board[r + dr][c + dc] == 1) {
              num_alive++;
            }
          }
        }
        if (num_alive < 2) {
          board[r][c] = 0;
        } else if (num_alive == 2) {
          board[r][c] = 1;
        } else if (num_alive == 3) {
          board[r][c] = 1;
        }
      }
    }

    // Increment the generation number
    generation++;

    // Ask the player if they want to continue
    char continue_game = 'y';
    printf("Do you want to continue playing? (y/n): ");
    scanf("%c", &continue_game);

    // Break out of the game if the player does not want to continue
    if (continue_game != 'y') {
      break;
    }
  }

  // Free the memory allocated for the game board
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      free(board[r][c]);
    }
    free(board[r]);
  }
  free(board);

  return 0;
}