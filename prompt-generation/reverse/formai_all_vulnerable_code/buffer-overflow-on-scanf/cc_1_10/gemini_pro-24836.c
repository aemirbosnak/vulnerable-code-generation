//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 6
#define NUM_COLS 7

char table[NUM_ROWS][NUM_COLS];
int player_turn = 1;

void init_table() {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      table[i][j] = ' ';
    }
  }
}

void print_table() {
  printf("  1 2 3 4 5 6 7\n");
  for (int i = 0; i < NUM_ROWS; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < NUM_COLS; j++) {
      printf("|%c", table[i][j]);
    }
    printf("|\n");
  }
  printf("  -+-+-+-+-+-+-+-");
  printf("\n\n");
}

int check_winner() {
  // Check rows
  for (int i = 0; i < NUM_ROWS; i++) {
    if (table[i][0] != ' ' &&
        table[i][0] == table[i][1] &&
        table[i][1] == table[i][2] &&
        table[i][2] == table[i][3]) {
      return table[i][0];
    }
  }

  // Check columns
  for (int j = 0; j < NUM_COLS; j++) {
    if (table[0][j] != ' ' &&
        table[0][j] == table[1][j] &&
        table[1][j] == table[2][j] &&
        table[2][j] == table[3][j]) {
      return table[0][j];
    }
  }

  // Check diagonals
  if (table[0][0] != ' ' &&
      table[0][0] == table[1][1] &&
      table[1][1] == table[2][2] &&
      table[2][2] == table[3][3]) {
    return table[0][0];
  }

  if (table[0][3] != ' ' &&
      table[0][3] == table[1][2] &&
      table[1][2] == table[2][1] &&
      table[2][1] == table[3][0]) {
    return table[0][3];
  }

  return 0;
}

int main() {
  srand(time(NULL));
  init_table();
  print_table();

  while (1) {
    int row, col;

    // Get player input
    printf("Player %d's turn (row, col): ", player_turn);
    scanf("%d %d", &row, &col);

    // Validate input
    if (row < 1 || row > NUM_ROWS ||
        col < 1 || col > NUM_COLS ||
        table[row - 1][col - 1] != ' ') {
      printf("Invalid input. Please try again.\n");
      continue;
    }

    // Place player's symbol in the table
    table[row - 1][col - 1] = (player_turn == 1) ? 'X' : 'O';

    // Check for a winner
    int winner = check_winner();
    if (winner != 0) {
      printf("Player %d wins!\n", winner);
      break;
    }

    // Switch to the other player
    player_turn = (player_turn == 1) ? 2 : 1;

    // Print the updated table
    print_table();
  }

  return 0;
}