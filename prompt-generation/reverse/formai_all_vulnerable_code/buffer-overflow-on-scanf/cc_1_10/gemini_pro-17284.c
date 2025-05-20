//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5

// Function to initialize the game board
void initBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 0;
    }
  }
}

// Function to print the game board
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a move is valid
int isValidMove(int board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
  return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0);
}

// Function to make a move
void makeMove(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int player) {
  if (isValidMove(board, row, col)) {
    board[row][col] = player;
  }
}

// Function to check if a player has won
int hasWon(int board[BOARD_SIZE][BOARD_SIZE], int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    int count = 0;
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board[i][j] == player) {
        count++;
      }
    }
    if (count == BOARD_SIZE) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
      if (board[i][j] == player) {
        count++;
      }
    }
    if (count == BOARD_SIZE) {
      return 1;
    }
  }

  // Check diagonals
  int count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][i] == player) {
      count++;
    }
  }
  if (count == BOARD_SIZE) {
    return 1;
  }

  count = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][BOARD_SIZE - 1 - i] == player) {
      count++;
    }
  }
  if (count == BOARD_SIZE) {
    return 1;
  }

  return 0;
}

// Function to get the next move from the player
int getNextMove(int board[BOARD_SIZE][BOARD_SIZE], int player) {
  int row, col;

  printf("Player %d, enter your move (row, col): ", player);
  scanf("%d %d", &row, &col);

  return isValidMove(board, row, col);
}

// Main game loop
int main() {
  // Initialize the game board
  int board[BOARD_SIZE][BOARD_SIZE];
  initBoard(board);

  // Print the game board
  printBoard(board);

  // Get the next move from the player
  int player = 1;
  while (1) {
    int move = getNextMove(board, player);

    // Make the move
    makeMove(board, move / BOARD_SIZE, move % BOARD_SIZE, player);

    // Print the game board
    printBoard(board);

    // Check if the player has won
    if (hasWon(board, player)) {
      printf("Player %d wins!\n", player);
      break;
    }

    // Switch to the other player
    player = 3 - player;
  }

  return 0;
}