//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the game board
#define BOARD_SIZE 5
char board[BOARD_SIZE][BOARD_SIZE];

// Define the player symbols
#define PLAYER1 'X'
#define PLAYER2 'O'

// Function to initialize the game board
void initBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

// Function to print the game board
void printBoard() {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a player has won
int checkWin(char player) {
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

// Function to get the next move from a player
int getMove(char player) {
  int move;
  printf("Player %c, enter your move (1-9): ", player);
  scanf("%d", &move);
  return move - 1;
}

// Function to make a move on the game board
void makeMove(int move, char player) {
  int row = move / BOARD_SIZE;
  int col = move % BOARD_SIZE;
  board[row][col] = player;
}

// Function to play the game
void playGame() {
  initBoard();

  int turn = 0; // 0 for player 1, 1 for player 2
  while (1) {
    int move = getMove(turn == 0 ? PLAYER1 : PLAYER2);
    makeMove(move, turn == 0 ? PLAYER1 : PLAYER2);
    printBoard();

    if (checkWin(turn == 0 ? PLAYER1 : PLAYER2)) {
      printf("Player %c wins!\n", turn == 0 ? PLAYER1 : PLAYER2);
      break;
    }

    turn = !turn;
  }
}

int main() {
  playGame();
  return 0;
}