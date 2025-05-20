//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 5
#define MAX_NAME_LENGTH 20

char playerOne[MAX_NAME_LENGTH];
char playerTwo[MAX_NAME_LENGTH];
char gameBoard[ROWS][COLS];

void printTitle() {
  printf("\n");
  printf("_____ ____  _    ____ ____ ___ ____ ____    ____ ____ ___ ____ ____ ___ ____ \n");
  printf("|__|  |  |  |    |__| [__   |  |___ [__     |___ |___  |  |___ |__/  |  |  |  \n");
  printf("|  |__|__|  |___ |  | ___]  |  |___ ___]    |    |___  |  |___ |  \\  |  |__|  \n");
  printf("\nWelcome to the ASCII Art Generator Game!\n\n");
}

void initializeGameBoard() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      gameBoard[i][j] = ' ';
    }
  }
}

void printGameBoard() {
  printf("  1   2   3   4   5 \n");
  printf(" ────┼───┼───┼───┼───\n");
  for (int i = 0; i < ROWS; i++) {
    printf(" ");
    for (int j = 0; j < COLS; j++) {
      printf("| %c ", gameBoard[i][j]);
    }
    printf("|\n");
    printf(" ────┼───┼───┼───┼───\n");
  }
}

void getPlayerNames() {
  printf("Enter Player One's Name: ");
  fgets(playerOne, MAX_NAME_LENGTH, stdin);
  printf("\nEnter Player Two's Name: ");
  fgets(playerTwo, MAX_NAME_LENGTH, stdin);
}

void updateGameBoard(int row, int col, char marker) {
  gameBoard[row][col] = marker;
}

int hasWon(char marker) {
  for (int i = 0; i < ROWS; i++) {
    if (gameBoard[i][0] == marker && gameBoard[i][1] == marker && gameBoard[i][2] == marker && gameBoard[i][3] == marker && gameBoard[i][4] == marker) {
      return 1;
    }
  }
  for (int j = 0; j < COLS; j++) {
    if (gameBoard[0][j] == marker && gameBoard[1][j] == marker && gameBoard[2][j] == marker && gameBoard[3][j] == marker && gameBoard[4][j] == marker) {
      return 1;
    }
  }
  if (gameBoard[0][0] == marker && gameBoard[1][1] == marker && gameBoard[2][2] == marker && gameBoard[3][3] == marker && gameBoard[4][4] == marker) {
    return 1;
  }
  if (gameBoard[0][4] == marker && gameBoard[1][3] == marker && gameBoard[2][2] == marker && gameBoard[3][1] == marker && gameBoard[4][0] == marker) {
    return 1;
  }
  return 0;
}

int isBoardFull() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (gameBoard[i][j] == ' ') {
        return 0;
      }
    }
  }
  return 1;
}

void playGame() {
  int row, col, turn = 0, win = 0;
  char marker;

  while (!win && !isBoardFull()) {
    printf("\n%s's turn: ", turn % 2 == 0 ? playerOne : playerTwo);
    scanf("%d %d", &row, &col);

    if (row < 1 || row > ROWS || col < 1 || col > COLS) {
      printf("Invalid input, try again.\n");
      continue;
    }
    if (gameBoard[row - 1][col - 1] != ' ') {
      printf("That spot is already taken, try again.\n");
      continue;
    }

    marker = turn % 2 == 0 ? 'X' : 'O';
    updateGameBoard(row - 1, col - 1, marker);
    printGameBoard();
    win = hasWon(marker);
    turn++;
  }

  if (win) {
    printf("\nCongratulations, %s! You win!\n", turn % 2 == 0 ? playerOne : playerTwo);
  } else {
    printf("\nIt's a tie! Game over.\n");
  }
}

int main() {
  printTitle();
  getPlayerNames();
  initializeGameBoard();
  printGameBoard();
  playGame();
  return 0;
}