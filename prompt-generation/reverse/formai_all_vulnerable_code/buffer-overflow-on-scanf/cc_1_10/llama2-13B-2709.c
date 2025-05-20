//LLAMA2-13B DATASET v1.0 Category: Checkers Game ; Style: excited
// 🎉 Introducing the Most Epic Checkers Game Ever! 🎉

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

// 🔵🔴🔵🔴🔵🔴🔵🔴🔵🔴

// Structure to represent the checkerboard
typedef struct {
  char board[SIZE][SIZE];
  int turn;
} checkerboard;

// 🔵🔴🔵🔴🔵🔴🔵🔴🔵🔴

// Function to print the checkerboard
void print_board(checkerboard *board) {
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      if (board->board[i][j] == 'X') {
        printf("X");
      } else if (board->board[i][j] == 'O') {
        printf("O");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// 🔵🔴🔵🔴🔵🔴🔵🔴🔵🔴

// Function to make a move
void make_move(checkerboard *board, int row, int col) {
  // Check if the move is valid
  if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
    printf("Invalid move! 😠");
    return;
  }

  // Update the board
  board->board[row][col] = board->turn == 'X' ? 'O' : 'X';
  board->turn = board->turn == 'X' ? 'O' : 'X';

  // Print the updated board
  print_board(board);
}

// 🔵🔴🔵🔴🔵🔴🔵🔴🔵🔴

// Main game loop
int main() {
  checkerboard board;
  board.turn = 'X';

  while (1) {
    // Print the current board
    print_board(&board);

    // Ask the user for their move
    printf("Your move! 😄 (row, col)");

    // Get the user's move
    int row, col;
    scanf("%d%d", &row, &col);

    // Make the move
    make_move(&board, row, col);
  }

  return 0;
}