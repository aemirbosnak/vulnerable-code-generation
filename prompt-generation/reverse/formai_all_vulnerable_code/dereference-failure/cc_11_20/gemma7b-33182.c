//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20

int main()
{
  // Allocate memory for the board
  int **board = (int **)malloc(BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
  }

  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      board[i][j] = 0;
    }
  }

  // Simulate percolations
  for (int t = 0; t < 1000; t++)
  {
    // Randomly choose a cell
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;

    // If the cell is not already wet and has a chance to be wet
    if (board[x][y] == 0 && rand() % 2 == 0)
    {
      // Make the cell wet
      board[x][y] = 1;

      // Simulate spreading water
      for (int dx = -1; dx <= 1; dx++)
      {
        for (int dy = -1; dy <= 1; dy++)
        {
          // If the cell is within the board and is not already wet
          if (x + dx >= 0 && x + dx < BOARD_SIZE && y + dy >= 0 && y + dy < BOARD_SIZE && board[x + dx][y + dy] == 0)
          {
            // Make the cell wet
            board[x + dx][y + dy] = 1;
          }
        }
      }
    }
  }

  // Print the board
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    for (int j = 0; j < BOARD_SIZE; j++)
    {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  // Free the memory
  for (int i = 0; i < BOARD_SIZE; i++)
  {
    free(board[i]);
  }
  free(board);

  return 0;
}