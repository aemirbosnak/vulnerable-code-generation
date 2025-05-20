//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int table[ROWS][COLS];

void print_table() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }
}

int check_winner() {
  // check rows
  for (int i = 0; i < ROWS; i++) {
    if (table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] != 0) {
      return table[i][0];
    }
  }

  // check columns
  for (int j = 0; j < COLS; j++) {
    if (table[0][j] == table[1][j] && table[1][j] == table[2][j] && table[0][j] != 0) {
      return table[0][j];
    }
  }

  // check diagonals
  if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] != 0) {
    return table[0][0];
  }

  if (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] != 0) {
    return table[0][2];
  }

  // check for a draw
  int count = 0;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (table[i][j] != 0) {
        count++;
      }
    }
  }

  if (count == ROWS * COLS) {
    return -1;
  }

  // no winner yet
  return 0;
}

int main() {
  // initialize the table
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      table[i][j] = 0;
    }
  }

  // print the table
  print_table();

  // get the player's move
  int player;
  int row, col;
  while (1) {
    printf("Player %d, enter your move (row, col): ", player);
    scanf("%d %d", &row, &col);

    // check if the move is valid
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || table[row][col] != 0) {
      printf("Invalid move. Try again.\n");
      continue;
    }

    // make the move
    table[row][col] = player;

    // print the table
    print_table();

    // check if there is a winner
    int winner = check_winner();
    if (winner == 1) {
      printf("Player 1 wins!\n");
      break;
    } else if (winner == 2) {
      printf("Player 2 wins!\n");
      break;
    } else if (winner == -1) {
      printf("Draw!\n");
      break;
    }

    // switch players
    player = 3 - player;
  }

  return 0;
}