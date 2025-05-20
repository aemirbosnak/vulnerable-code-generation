//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLS 3
#define EMPTY 0
#define AI 1
#define HUMAN 2

// Function to check if the game is over
int isGameOver(int board[][COLS]) {
  // Check rows
  for (int row = 0; row < ROWS; row++) {
    if (board[row][0] != EMPTY && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
      return board[row][0];
    }
  }
  
  // Check columns
  for (int col = 0; col < COLS; col++) {
    if (board[0][col] != EMPTY && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
      return board[0][col];
    }
  }
  
  // Check diagonals
  if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    return board[0][0];
  }
  if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
    return board[0][2];
  }
  
  // Check if there are any empty spaces left
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      if (board[row][col] == EMPTY) {
        return EMPTY;
      }
    }
  }
  
  // If all conditions fail, the game is tied
  return -1;
}

// Function to print the tic-tac-toe board
void printBoard(int board[][COLS]) {
  printf("\n    0    1    2\n");
  printf("  --------------\n");
  for (int row = 0; row < ROWS; row++) {
    printf("%d |", row);
    for (int col = 0; col < COLS; col++) {
      printf(" ");
      if (board[row][col] == EMPTY) {
        printf(" ");
      } else if (board[row][col] == AI) {
        printf("O");
      } else {
        printf("X");
      }
      printf(" |");
    }
    printf("\n");
    printf("  --------------\n");
  }
}

// Function to get the human player's move
void getHumanMove(int* row, int* col) {
  printf("Enter your move (row [0-2] column [0-2]): ");
  scanf("%d %d", row, col);
}

// Function to get the AI's move
void getAIMove(int board[][COLS], int* row, int* col) {
  while (1) {
    // Generate random move
    *row = rand() % ROWS;
    *col = rand() % COLS;
    if (board[*row][*col] == EMPTY) {
      break;
    }
  }
}

// The main function
int main() {
  int board[ROWS][COLS];
  int winner = EMPTY;
  int currPlayer = HUMAN;
  int row, col;
  
  srand(time(NULL));
  
  // Initialize board to be empty
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      board[row][col] = EMPTY;
    }
  }
  
  // Play until there's a winner or the game is tied
  while ((winner = isGameOver(board)) == EMPTY) {
    // Print board
    printBoard(board);
    
    if (currPlayer == HUMAN) {
      // Get human player's move
      getHumanMove(&row, &col);
      board[row][col] = HUMAN;
      currPlayer = AI;
    } else {
      // Get AI's move
      getAIMove(board, &row, &col);
      board[row][col] = AI;
      currPlayer = HUMAN;
    }
  }
  
  // Print final board
  printBoard(board);
  
  // Print result of game
  if (winner == HUMAN) {
    printf("\nYou win!\n");
  } else if (winner == AI) {
    printf("\nYou lose!\n");
  } else {
    printf("\nGame over. It's a tie.\n");
  }
  
  return 0;
}