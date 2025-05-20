//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

int max(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int min(int a, int b) {
  if (a < b)
    return a;
  return b;
}

int win(char player) {
  for (int i = 0; i < 3; i++)
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
      return 1;

  for (int i = 0; i < 3; i++)
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
      return 1;

  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    return 1;

  if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
    return 1;

  return 0;
}

int evaluate() {
  if (win('O'))
    return 10;

  if (win('X'))
    return -10;

  return 0;
}

int minimax(int depth, int isMax) {
  int score = evaluate();
  if (score != 0)
    return score;

  if (depth == 9)
    return 0;

  if (isMax) {
    int best = -1000;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == ' ') {
          board[i][j] = 'O';
          best = max(best, minimax(depth + 1, !isMax));
          board[i][j] = ' ';
        }
      }
    }
    return best;
  } else {
    int best = 1000;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == ' ') {
          board[i][j] = 'X';
          best = min(best, minimax(depth + 1, !isMax));
          board[i][j] = ' ';
        }
      }
    }
    return best;
  }
}

void play() {
  int bestVal = -1000;
  int bestI, bestJ;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        board[i][j] = 'O';
        int moveVal = minimax(0, 0);
        board[i][j] = ' ';

        if (moveVal > bestVal) {
          bestVal = moveVal;
          bestI = i;
          bestJ = j;
        }
      }
    }
  }

  board[bestI][bestJ] = 'O';
}

void printBoard() {
  printf("\n");
  printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int main() {
  printf("\nWelcome to the Tic Tac Toe Game! You are X and the computer is O.\n");

  for (int i = 1; i <= 9; i++) {
    printf("\nRound %d:\n", i);
    printf("\nYour turn:\n");
    int row, col;
    do {
      printf("Enter the row (1-3): ");
      scanf("%d", &row);
      printf("Enter the column (1-3): ");
      scanf("%d", &col);
      if (board[row - 1][col - 1] != ' ')
        printf("That cell is already occupied. Please choose again.\n");
    } while (board[row - 1][col - 1] != ' ');
    board[row - 1][col - 1] = 'X';
    printBoard();
    if (win('X')) {
      printf("\nYou win!\n");
      return 0;
    }
    if (i == 9) {
      printf("\nIt's a tie!\n");
      return 0;
    }
    printf("\nComputer's turn:\n");
    play();
    printBoard();
    if (win('O')) {
      printf("\nComputer wins!\n");
      return 0;
    }
  }

  return 0;
}