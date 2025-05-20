//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

int table[ROWS][COLUMNS];
int player1, player2;

void init_table() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      table[i][j] = 0;
    }
  }
}

void print_table() {
  printf("\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
}

int check_win() {
  // Check rows
  for (int i = 0; i < ROWS; i++) {
    if (table[i][0] != 0 && table[i][0] == table[i][1] && table[i][0] == table[i][2]) {
      return table[i][0];
    }
  }

  // Check columns
  for (int j = 0; j < COLUMNS; j++) {
    if (table[0][j] != 0 && table[0][j] == table[1][j] && table[0][j] == table[2][j]) {
      return table[0][j];
    }
  }

  // Check diagonals
  if (table[0][0] != 0 && table[0][0] == table[1][1] && table[0][0] == table[2][2]) {
    return table[0][0];
  }

  if (table[0][2] != 0 && table[0][2] == table[1][1] && table[0][2] == table[2][0]) {
    return table[0][2];
  }

  // Check for draw
  int count = 0;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      if (table[i][j] != 0) {
        count++;
      }
    }
  }

  if (count == ROWS * COLUMNS) {
    return -1;
  }

  return 0;
}

int main() {
  srand(time(NULL));

  init_table();

  player1 = 1;
  player2 = 2;

  int winner = 0;
  int turn = 0;

  while (winner == 0) {
    int player = turn % 2 == 0 ? player1 : player2;
    int row, column;

    do {
      printf("Player %d, enter a row and column (0-2): ", player);
      scanf("%d %d", &row, &column);
    } while (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS || table[row][column] != 0);

    table[row][column] = player;
    print_table();

    winner = check_win();
    turn++;
  }

  if (winner == player1) {
    printf("Player 1 wins!\n");
  } else if (winner == player2) {
    printf("Player 2 wins!\n");
  } else {
    printf("Draw!\n");
  }

  return 0;
}