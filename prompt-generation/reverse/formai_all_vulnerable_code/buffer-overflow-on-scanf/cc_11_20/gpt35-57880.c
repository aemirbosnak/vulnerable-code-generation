//FormAI DATASET v1.0 Category: Chess engine ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Initialize the chess board
  char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
  };
  
  // Print the initial state of the board
  printf("Initial state of the board:\n");
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  
  // Game loop
  while (1) {
    // Get input from the user
    int from_row, from_col, to_row, to_col;
    printf("Enter your move (from row, from col, to row, to col):\n");
    scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);
    
    // Validate the move
    if (from_row < 0 || from_row > 7 || from_col < 0 || from_col > 7 ||
        to_row < 0 || to_row > 7 || to_col < 0 || to_col > 7) {
      printf("Invalid move!\n");
      continue;
    }
    
    // Execute the move
    char piece = board[from_row][from_col];
    board[from_row][from_col] = '.';
    board[to_row][to_col] = piece;
    
    // Print the new state of the board
    printf("New state of the board:\n");
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        printf("%c ", board[i][j]);
      }
      printf("\n");
    }
    
    // Check for game over conditions
    // TODO: Implement game over conditions
  }
  
  return 0;
}