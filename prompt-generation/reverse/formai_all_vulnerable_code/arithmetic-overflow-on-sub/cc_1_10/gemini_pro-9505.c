//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_CARDS 16

// Card struct
typedef struct {
  int value;
  int flipped;
} Card;

// Game state
typedef struct {
  Card board[BOARD_SIZE][BOARD_SIZE];
  int flips;
  int matches;
} GameState;

// Initialize the game state
void initGameState(GameState *state) {
  // Create a deck of cards
  int deck[NUM_CARDS];
  for (int i = 0; i < NUM_CARDS; i++) {
    deck[i] = i / 2;
  }

  // Shuffle the deck
  srand(time(NULL));
  for (int i = 0; i < NUM_CARDS; i++) {
    int j = rand() % NUM_CARDS;
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }

  // Populate the board
  int k = 0;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      state->board[i][j].value = deck[k++];
      state->board[i][j].flipped = 0;
    }
  }

  // Reset game state
  state->flips = 0;
  state->matches = 0;
}

// Print the game board
void printBoard(GameState *state) {
  printf("  ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (state->board[i][j].flipped) {
        printf("%d ", state->board[i][j].value);
      } else {
        printf("X ");
      }
    }
    printf("\n");
  }
}

// Get the user's input
void getUserInput(GameState *state) {
  int row1, col1, row2, col2;

  printf("Enter the coordinates of the first card (row, column): ");
  scanf("%d %d", &row1, &col1);
  row1--;
  col1--;

  printf("Enter the coordinates of the second card (row, column): ");
  scanf("%d %d", &row2, &col2);
  row2--;
  col2--;

  // Flip the cards
  state->board[row1][col1].flipped = 1;
  state->board[row2][col2].flipped = 1;

  // Increment the number of flips
  state->flips++;

  // Check if the cards match
  if (state->board[row1][col1].value == state->board[row2][col2].value) {
    printf("Match!\n");
    state->matches++;
  } else {
    printf("No match.\n");
  }
}

// Check if the game is over
int isGameOver(GameState *state) {
  return state->matches == NUM_CARDS / 2;
}

// Play the game
void playGame() {
  GameState state;

  initGameState(&state);

  while (!isGameOver(&state)) {
    printBoard(&state);
    getUserInput(&state);
  }

  printf("Congratulations! You won in %d flips.\n", state.flips);
}

int main() {
  playGame();

  return 0;
}