//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// The game board
char board[BOARD_SIZE][BOARD_SIZE];

// The player's guesses
char guesses[BOARD_SIZE][BOARD_SIZE];

// The number of matches the player has made
int matches = 0;

// The main game loop
void play_game() {
  // Initialize the game board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = 'X';
      guesses[i][j] = ' ';
    }
  }

  // Generate random numbers for the game board
  srand(time(NULL));
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = rand() % 10 + '0';
    }
  }

  // Main game loop
  while (matches < BOARD_SIZE * BOARD_SIZE) {
    // Print the game board
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%c ", guesses[i][j]);
      }
      printf("\n");
    }

    // Get the player's guesses
    int guess1_row, guess1_col, guess2_row, guess2_col;
    printf("Enter the row and column of the first guess: ");
    scanf("%d %d", &guess1_row, &guess1_col);
    printf("Enter the row and column of the second guess: ");
    scanf("%d %d", &guess2_row, &guess2_col);

    // Check if the guesses are valid
    if (guess1_row < 0 || guess1_row >= BOARD_SIZE || guess1_col < 0 || guess1_col >= BOARD_SIZE ||
        guess2_row < 0 || guess2_row >= BOARD_SIZE || guess2_col < 0 || guess2_col >= BOARD_SIZE) {
      printf("Invalid guesses. Please enter valid row and column numbers.\n");
      continue;
    }

    // Check if the guesses match
    if (board[guess1_row][guess1_col] == board[guess2_row][guess2_col]) {
      matches++;
      guesses[guess1_row][guess1_col] = board[guess1_row][guess1_col];
      guesses[guess2_row][guess2_col] = board[guess2_row][guess2_col];
      printf("Match! You have %d matches.\n", matches);
    } else {
      printf("No match. Try again.\n");
    }
  }

  // Print the final game board
  printf("\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }

  // Congratulate the player
  printf("Congratulations! You found all the matches.\n");
}

int main() {
  // Play the game
  play_game();

  return 0;
}