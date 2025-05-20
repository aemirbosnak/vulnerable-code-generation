//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

int squares[N][N];
int rows[N][N];
int cols[N][N];

int main() {
  int i, j, k, l, m, n;
  int count = 0;

  // Read the puzzle from the input file.
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      scanf("%d", &squares[i][j]);
    }
  }

  // Initialize the data structures.
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      rows[i][j] = 1 << (squares[i][j] - 1);
      cols[j][i] = 1 << (squares[i][j] - 1);
      if (i % 3 == 0 && j % 3 == 0) {
        for (k = 0; k < 3; k++) {
          for (l = 0; l < 3; l++) {
            squares[i + k][j + l] |= 1 << (squares[i + k][j + l] - 1);
          }
        }
      }
    }
  }

  // Solve the puzzle.
  while (count < 81) {
    for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        // If the square is already filled in, skip it.
        if (squares[i][j] != 0) {
          continue;
        }

        // Get the possible values for the square.
        int possible = rows[i][j] & cols[j][i] & squares[i][j];

        // If there is only one possible value, fill it in.
        if (possible & (possible - 1) == 0) {
          count++;
          squares[i][j] = __builtin_ctz(possible) + 1;
          rows[i][j] |= 1 << (squares[i][j] - 1);
          cols[j][i] |= 1 << (squares[i][j] - 1);
          for (k = 0; k < 3; k++) {
            for (l = 0; l < 3; l++) {
              squares[i + k][j + l] |= 1 << (squares[i][j] - 1);
            }
          }
        }
      }
    }
  }

  // Print the solution to the output file.
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%d ", squares[i][j]);
    }
    printf("\n");
  }

  return 0;
}