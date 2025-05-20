//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

// The game board
char board[BOARD_SIZE][BOARD_SIZE];

// The player's guesses
char guesses[2][2];

// The number of guesses the player has made
int num_guesses = 0;

// The number of pairs the player has found
int num_pairs_found = 0;

// The main game loop
void play_game() {
  // Initialize the game board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '*';
    }
  }

  // Place the pairs on the board
  int pairs[NUM_PAIRS][2];
  for (int i = 0; i < NUM_PAIRS; i++) {
    pairs[i][0] = rand() % BOARD_SIZE;
    pairs[i][1] = rand() % BOARD_SIZE;
    board[pairs[i][0]][pairs[i][1]] = 'A' + i;
  }

  // Get the player's guesses
  while (num_pairs_found < NUM_PAIRS) {
    printf("Enter your first guess (row, column): ");
    scanf("%d %d", &guesses[0][0], &guesses[0][1]);

    printf("Enter your second guess (row, column): ");
    scanf("%d %d", &guesses[1][0], &guesses[1][1]);

    // Check if the guesses are valid
    if (guesses[0][0] < 0 || guesses[0][0] >= BOARD_SIZE || guesses[0][1] < 0 || guesses[0][1] >= BOARD_SIZE ||
        guesses[1][0] < 0 || guesses[1][0] >= BOARD_SIZE || guesses[1][1] < 0 || guesses[1][1] >= BOARD_SIZE) {
      printf("Invalid guess. Please try again.\n");
      continue;
    }

    // Check if the guesses match
    if (board[guesses[0][0]][guesses[0][1]] == board[guesses[1][0]][guesses[1][1]]) {
      printf("You found a pair!\n");
      board[guesses[0][0]][guesses[0][1]] = ' ';
      board[guesses[1][0]][guesses[1][1]] = ' ';
      num_pairs_found++;
    } else {
      printf("Sorry, your guesses didn't match.\n");
    }

    num_guesses++;
  }

  // Print the final board
  printf("The final board:\n");
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }

  // Print the number of guesses the player made
  printf("You found all the pairs in %d guesses.\n", num_guesses);
}

// The main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}