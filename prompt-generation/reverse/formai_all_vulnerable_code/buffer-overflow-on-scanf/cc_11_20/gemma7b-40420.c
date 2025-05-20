//Gemma-7B DATASET v1.0 Category: Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m, i, j, k, l, score = 0;
  scanf("%d %d", &n, &m);

  // Allocate memory for the game board
  int **board = (int **)malloc(n * sizeof(int *) + m * sizeof(int));
  for (i = 0; i < n; i++) {
    board[i] = (int *)malloc(m * sizeof(int));
  }

  // Initialize the game board
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      board[i][j] = 0;
    }
  }

  // Place the initial pieces
  scanf("%d", &k);
  for (i = 0; i < k; i++) {
    scanf("%d %d", &l, &score);
    board[l][score] = 1;
  }

  // Play the game
  while (score < n * m) {
    scanf("%d", &i);
    scanf("%d", &j);

    // Check if the move is valid
    if (board[i][j] == 0 && board[i][j] != -1) {
      // Place the piece
      board[i][j] = 1;

      // Calculate the score
      score++;

      // Update the game board
      for (k = 0; k < n; k++) {
        for (l = 0; l < m; l++) {
          if (board[k][l] == 1) {
            board[k][l] = -1;
          }
        }
      }
    }
  }

  // Print the final score
  printf("The final score is: %d", score);

  // Free the memory
  for (i = 0; i < n; i++) {
    free(board[i]);
  }
  free(board);

  return 0;
}