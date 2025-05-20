//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int row, col, i, j, count, player, num_players, choice, max_moves;
  char board[10][10];
  srand(time(NULL));
  
  // User Input
  printf("How many players? ");
  scanf("%d", &num_players);
  if (num_players < 2 || num_players > 4) {
    printf("Invalid number of players.\n");
    return 0;
  }
  
  printf("Rows: ");
  scanf("%d", &row);
  printf("Columns: ");
  scanf("%d", &col);
  
  // Initialize Board
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      board[i][j] = '-';
    }
  }
  
  max_moves = row * col;
  count = 0;
  player = 0;
  
  while (count < max_moves) {
    // Display Board
    printf("\n");
    for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
        printf("%c ", board[i][j]);
      }
      printf("\n");
    }
    
    // Player Input
    printf("Player %d's turn.\n", player + 1);
    printf("Choose a column (1-%d): ", col);
    scanf("%d", &choice);
    if (choice < 1 || choice > col) {
      printf("Invalid choice.\n");
      continue;
    }
    choice--;
    
    // Check for Available Cell
    int available = 0;
    for (i = 0; i < row; i++) {
      if (board[i][choice] == '-') {
        available = 1;
        break;
      }
    }
    if (!available) {
      printf("Column is full.\n");
      continue;
    }
    
    // Place Token
    char token;
    switch(player) {
      case 0:
        token = 'X';
        break;
      case 1:
        token = 'O';
        break;
      case 2:
        token = 'A';
        break;
      case 3:
        token = 'B';
        break;
    }
    for (i = row-1; i >= 0; i--) {
      if (board[i][choice] == '-') {
        board[i][choice] = token;
        break;
      }
    }
    count++;
    
    // Check for Win
    for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
        if (board[i][j] == token) {
          // Check Horizontal
          if (j <= col - 4) {
            if (board[i][j+1] == token && board[i][j+2] == token && board[i][j+3] == token) {
              printf("\nPlayer %d wins!\n", player + 1);
              for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                  printf("%c ", board[i][j]);
                }
                printf("\n");
              }
              return 0;
            }
          }
          // Check Vertical
          if (i <= row - 4) {
            if (board[i+1][j] == token && board[i+2][j] == token && board[i+3][j] == token) {
              printf("\nPlayer %d wins!\n", player + 1);
              for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                  printf("%c ", board[i][j]);
                }
                printf("\n");
              }
              return 0;
            }
          }
          // Check Diagonal Left
          if (i >= 3 && j <= col - 4) {
            if (board[i-1][j+1] == token && board[i-2][j+2] == token && board[i-3][j+3] == token) {
              printf("\nPlayer %d wins!\n", player + 1);
              for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                  printf("%c ", board[i][j]);
                }
                printf("\n");
              }
              return 0;
            }
          }
          // Check Diagonal Right
          if (i <= row - 4 && j <= col - 4) {
            if (board[i+1][j+1] == token && board[i+2][j+2] == token && board[i+3][j+3] == token) {
              printf("\nPlayer %d wins!\n", player + 1);
              for (i = 0; i < row; i++) {
                for (j = 0; j < col; j++) {
                  printf("%c ", board[i][j]);
                }
                printf("\n");
              }
              return 0;
            }
          }
        }
      }
    }
    
    // Switch Player
    player = (player + 1) % num_players;
  }
  
  // Tie
  printf("\nTie game.\n");
  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}