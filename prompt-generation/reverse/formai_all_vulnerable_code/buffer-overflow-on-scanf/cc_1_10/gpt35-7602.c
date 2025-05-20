//FormAI DATASET v1.0 Category: Memory Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printBoard(int board[][COLS], int rows);
void shuffleBoard(int board[][COLS], int rows);
void playGame(int board[][COLS], int rows);

int main() {
  int board[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}
  };

  srand(time(NULL));

  shuffleBoard(board, ROWS);

  printBoard(board, ROWS);

  playGame(board, ROWS);

  return 0;
}

void printBoard(int board[][COLS], int rows) {
  printf("\nMemory Game\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < COLS; j++) {
      if (board[i][j] == 0) {
        printf("[ %c ] ", ' ');
      } else {
        printf("[ %d ] ", board[i][j]);
      }
    }
    printf("\n");
  }
}

void shuffleBoard(int board[][COLS], int rows) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < COLS; j++) {
      int randRow = rand() % rows;
      int randCol = rand() % COLS;
      int temp = board[i][j];
      board[i][j] = board[randRow][randCol];
      board[randRow][randCol] = temp;
    }
  }
}

void playGame(int board[][COLS], int rows) {
  int moves = 0;
  while (1) {
    int firstRow, firstCol, secondRow, secondCol;
    puts("");
    printf("Enter the first row and column: ");
    scanf("%d %d", &firstRow, &firstCol);
    printf("Enter the second row and column: ");
    scanf("%d %d", &secondRow, &secondCol);

    if (board[firstRow][firstCol] == board[secondRow][secondCol]) {
      printf("\nYou found a match!\n");
      board[firstRow][firstCol] = 0;
      board[secondRow][secondCol] = 0;
      moves += 1;
      printBoard(board, rows);

      int count = 0;
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
          if (board[i][j] == 0) {
            count += 1;
          }
        }
      }

      if (count == (rows * COLS)) {
        printf("Congratulations! You won the game in %d moves!\n", moves);
        break;
      }
    } else {
      printf("\nSorry, those tiles do not match.\n");
      moves += 1;
      printBoard(board, rows);
    }
  }
}