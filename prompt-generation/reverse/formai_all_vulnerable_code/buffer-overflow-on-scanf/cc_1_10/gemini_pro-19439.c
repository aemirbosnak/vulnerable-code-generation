//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Our beloved game board, ready for action!
int gameBoard[5][5];
int currentPlayer = 1;
int movesCount = 0;

// Let the excitement begin!
void initializeGame() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      gameBoard[i][j] = 0;
    }
  }
  srand(time(NULL));
  currentPlayer = 1;
  movesCount = 0;
}

// Who's up next?
void switchPlayer() {
  currentPlayer = 3 - currentPlayer;
}

// Place your marker, claim your spot!
int makeMove(int x, int y, int player) {
  if (x < 0 || x > 4 || y < 0 || y > 4) {
    printf("Oops! That's not a valid move.\n");
    return -1;
  }
  if (gameBoard[x][y] != 0) {
    printf("Sorry, that spot's already taken.\n");
    return -1;
  }
  gameBoard[x][y] = player;
  movesCount++;
  return 0;
}

// Check for a victorious row, column, or diagonal
int checkForWin() {
  // Check rows
  for (int i = 0; i < 5; i++) {
    if (gameBoard[i][0] != 0 && gameBoard[i][0] == gameBoard[i][1] &&
        gameBoard[i][0] == gameBoard[i][2] && gameBoard[i][0] == gameBoard[i][3] &&
        gameBoard[i][0] == gameBoard[i][4]) {
      return gameBoard[i][0];
    }
  }
  // Check columns
  for (int j = 0; j < 5; j++) {
    if (gameBoard[0][j] != 0 && gameBoard[0][j] == gameBoard[1][j] &&
        gameBoard[0][j] == gameBoard[2][j] && gameBoard[0][j] == gameBoard[3][j] &&
        gameBoard[0][j] == gameBoard[4][j]) {
      return gameBoard[0][j];
    }
  }
  // Check diagonals
  if (gameBoard[0][0] != 0 && gameBoard[0][0] == gameBoard[1][1] &&
      gameBoard[0][0] == gameBoard[2][2] && gameBoard[0][0] == gameBoard[3][3] &&
      gameBoard[0][0] == gameBoard[4][4]) {
    return gameBoard[0][0];
  }
  if (gameBoard[0][4] != 0 && gameBoard[0][4] == gameBoard[1][3] &&
      gameBoard[0][4] == gameBoard[2][2] && gameBoard[0][4] == gameBoard[3][1] &&
      gameBoard[0][4] == gameBoard[4][0]) {
    return gameBoard[0][4];
  }
  return 0;
}

// Let's see the board, shall we?
void printGameBoard() {
  printf("+---+---+---+---+---+\n");
  for (int i = 0; i < 5; i++) {
    printf("| ");
    for (int j = 0; j < 5; j++) {
      if (gameBoard[i][j] == 0) {
        printf("   ");
      } else if (gameBoard[i][j] == 1) {
        printf(" X ");
      } else if (gameBoard[i][j] == 2) {
        printf(" O ");
      }
      printf("| ");
    }
    printf("\n+---+---+---+---+---+\n");
  }
}

// Time to play, folks!
int main() {
  initializeGame();
  int winner = 0;
  while (winner == 0 && movesCount < 25) {
    printGameBoard();
    int x, y;
    if (currentPlayer == 1) {
      printf("Player 1 (X), it's your turn: ");
    } else {
      printf("Player 2 (O), it's your turn: ");
    }
    scanf("%d %d", &x, &y);
    if (makeMove(x, y, currentPlayer) == -1) {
      continue;
    }
    switchPlayer();
    winner = checkForWin();
  }
  printGameBoard();
  if (winner == 0) {
    printf("It's a draw! Better luck next time.\n");
  } else {
    printf("Congratulations, Player %d! You've conquered the game.\n", winner);
  }
  return 0;
}