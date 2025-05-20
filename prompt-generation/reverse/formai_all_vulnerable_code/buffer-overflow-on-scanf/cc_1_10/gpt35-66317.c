//FormAI DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void display_table(int *);
void update_table(int *, int, int);
int check_winner(int *);

int main() {
  int table[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int player = 1, position, winner = 0, filled_positions = 0;

  printf("\nWelcome to the unique C Table Game!\n");

  printf("\nHere's your table:\n");
  display_table(table);

  printf("\nLet's get started! Player 1 will be 'X' and Player 2 will be 'O'.\n");

  // Game loop
  while (winner == 0 && filled_positions < 9) {
    printf("\nPlayer %d, it's your turn. Please enter a position between 1 and 9: ", player);
    scanf("%d", &position);

    // Make sure the position is valid
    while (position < 1 || position > 9 || table[position - 1] != 0) {
      printf("Invalid position. Please try again: ");
      scanf("%d", &position);
    }

    // Update the table and display it
    update_table(table, position, player);
    display_table(table);

    // Check for a winner
    winner = check_winner(table);

    // Switch players
    if (player == 1) {
      player = 2;
    } else {
      player = 1;
    }

    filled_positions++;
  }

  // Game over
  if (winner != 0) {
    printf("\nCongratulations Player %d, you won!\n", winner);
  } else {
    printf("\nIt's a tie!\n");
  }

  return 0;
}

// Function to display the table
void display_table(int *table) {
  for (int i = 0; i < 9; i++) {
    if (table[i] == 0) {
      printf(" ");
    } else if (table[i] == 1) {
      printf("X");
    } else {
      printf("O");
    }

    if (i == 2 || i == 5 || i == 8) {
      printf("\n");
    } else {
      printf(" | ");
    }
  }
}

// Function to update the table
void update_table(int *table, int position, int player) {
  if (player == 1) {
    table[position - 1] = 1;
  } else {
    table[position - 1] = 2;
  }
}

// Function to check for a winner
int check_winner(int *table) {
  // Check rows
  for (int i = 0; i < 9; i += 3) {
    if (table[i] == table[i + 1] && table[i + 1] == table[i + 2] && table[i] != 0) {
      return table[i];
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (table[i] == table[i + 3] && table[i + 3] == table[i + 6] && table[i] != 0) {
      return table[i];
    }
  }

  // Check diagonals
  if (table[0] == table[4] && table[4] == table[8] && table[0] != 0) {
    return table[0];
  }

  if (table[2] == table[4] && table[4] == table[6] && table[2] != 0) {
    return table[2];
  }

  return 0;
}