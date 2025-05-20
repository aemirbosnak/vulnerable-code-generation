//FormAI DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printGrid(char grid[ROWS][COLS]) {
  printf("\n\n== Memory Game ==\n\n");
  printf(" | 1 | 2 | 3 | 4 |\n");
  printf("--+---+---+---+--\n");
  for (int i = 0; i < ROWS; i++) {
    printf("%d | %c | %c | %c | %c |\n", i+1, grid[i][0], grid[i][1], grid[i][2], grid[i][3]);
    printf("--+---+---+---+--\n");
  }
}

void initializeGrid(char grid[ROWS][COLS]) {
  char values[] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D',
                   'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H'};
  int i, j, idx = 0;
  srand(time(NULL));
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      idx = rand() % 16;
      grid[i][j] = values[idx];
      values[idx] = values[15];
      values[15] = grid[i][j];
    }
  }
}

void clearScreen() {
  printf("\033[2J\033[1;1H");
}

int getGuess() {
  int guess = 0;
  printf("Enter row col to reveal (e.g., '2 3'): ");
  scanf("%d %d", &guess, &guess);
  return guess-1;
}

int checkWin(char grid[ROWS][COLS], char revealed[ROWS][COLS]) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      if (!revealed[i][j])
        return 0;
    }
  }
  return 1;
}

int main() {
  char grid[ROWS][COLS];
  char revealed[ROWS][COLS] = {0};
  char firstChar = '\0', secondChar = '\0';
  int firstRow = -1, firstCol = -1, secondRow = -1, secondCol = -1;

  initializeGrid(grid);

  while(!checkWin(grid, revealed)) {
    clearScreen();
    printGrid(grid);

    int guess = getGuess();
    int row = guess / ROWS;
    int col = guess % COLS;

    if (revealed[row][col]) {
      printf("\nThat tile is already revealed. Please choose another.\n\n");
      continue;
    }

    revealed[row][col] = 1;

    if (firstRow < 0) {
      firstRow = row;
      firstCol = col;
      firstChar = grid[row][col];
    } else {
      secondRow = row;
      secondCol = col;
      secondChar = grid[row][col];
      if (firstChar == secondChar) {
        printf("\nMatch found! The tiles will stay revealed.\n\n");
      } else {
        printf("\nNo match. Hiding the tiles.\n\n");
        revealed[firstRow][firstCol] = 0;
        revealed[secondRow][secondCol] = 0;
      }
      firstRow = -1;
      firstCol = -1;
      firstChar = '\0';
      secondRow = -1;
      secondCol = -1;
      secondChar = '\0';
    }
  }

  clearScreen();
  printGrid(grid);
  printf("\nCongratulations! You won the game!\n\n");
  return 0;
}