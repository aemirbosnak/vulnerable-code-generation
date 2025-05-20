//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 5

typedef enum {EMPTY, CROSS, CIRCLE, DRAW} GameStatus;

void printBoard(char board[ROWS][COLS]) {
  printf("\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf(" %c ", board[i][j]);
      if (j < COLS - 1) {
        printf("|");
      }
    }
    printf("\n");
    if (i < ROWS - 1) {
      printf("---+---+---+---+---+\n");
    }
  }
  printf("\n");
}

bool checkWin(char board[ROWS][COLS], char symbol) {
  // Check rows
  for (int i = 0; i < ROWS; i++) {
    bool win = true;
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] != symbol) {
        win = false;
        break;
      }
    }
    if (win) {
      return true;
    }
  }

  // Check columns
  for (int j = 0; j < COLS; j++) {
    bool win = true;
    for (int i = 0; i < ROWS; i++) {
      if (board[i][j] != symbol) {
        win = false;
        break;
      }
    }
    if (win) {
      return true;
    }
  }

  // Check diagonals
  bool win1 = true;
  bool win2 = true;
  for (int i = 0; i < ROWS; i++) {
    if (board[i][i] != symbol) {
      win1 = false;
    }
    if (board[i][ROWS - 1 - i] != symbol) {
      win2 = false;
    }
  }
  if (win1 || win2) {
    return true;
  }

  return false;
}

bool checkDraw(char board[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] == EMPTY) {
        return false;
      }
    }
  }
  return true;
}

void playGame() {
  char board[ROWS][COLS];

  // Initialize board
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = EMPTY;
    }
  }

  // Randomly determine which player goes first
  srand(time(NULL));
  int player = rand() % 2 + 1;

  // Game loop
  bool gameOver = false;
  GameStatus status = EMPTY;
  while (!gameOver) {
    // Print board
    printBoard(board);

    // Get player input
    int x, y;
    if (player == 1) {
      printf("Player 1 (X), enter your move (row, column): ");
      scanf("%d %d", &x, &y);
    } else {
      printf("Player 2 (O), enter your move (row, column): ");
      scanf("%d %d", &x, &y);
    }

    // Validate input
    if (x < 1 || x > ROWS || y < 1 || y > COLS || board[x - 1][y - 1] != EMPTY) {
      printf("Invalid move. Please try again.\n");
      continue;
    }

    // Update board
    if (player == 1) {
      board[x - 1][y - 1] = CROSS;
    } else {
      board[x - 1][y - 1] = CIRCLE;
    }

    // Check win
    if (checkWin(board, CROSS)) {
      status = CROSS;
      gameOver = true;
    } else if (checkWin(board, CIRCLE)) {
      status = CIRCLE;
      gameOver = true;
    } else if (checkDraw(board)) {
      status = DRAW;
      gameOver = true;
    }

    // Switch players
    player = 3 - player;
  }

  // Print final board and game status
  printBoard(board);
  switch (status) {
    case CROSS:
      printf("Player 1 (X) wins!\n");
      break;
    case CIRCLE:
      printf("Player 2 (O) wins!\n");
      break;
    case DRAW:
      printf("Draw!\n");
      break;
    default:
      printf("Error: Invalid game status.\n");
  }
}

int main() {
  playGame();
  return 0;
}