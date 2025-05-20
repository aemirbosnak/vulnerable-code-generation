//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 4
#define NUM_CARDS (GRID_SIZE * GRID_SIZE)

// Card structure
typedef struct {
  int value;
  int is_flipped;
} Card;

// Game board
Card grid[GRID_SIZE][GRID_SIZE];

// Function to initialize the game board
void init_board() {
  // Create a deck of cards
  int deck[NUM_CARDS];
  for (int i = 0; i < NUM_CARDS; i++) {
    deck[i] = i % (NUM_CARDS / 2);
  }

  // Shuffle the deck
  srand(time(NULL));
  for (int i = 0; i < NUM_CARDS; i++) {
    int j = rand() % NUM_CARDS;
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }

  // Place the cards on the game board
  int k = 0;
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid[i][j].value = deck[k++];
      grid[i][j].is_flipped = 0;
    }
  }
}

// Function to print the game board
void print_board() {
  printf("  ");
  for (int i = 0; i < GRID_SIZE; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  for (int i = 0; i < GRID_SIZE; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < GRID_SIZE; j++) {
      if (grid[i][j].is_flipped) {
        printf("%d ", grid[i][j].value + 1);
      } else {
        printf("X ");
      }
    }
    printf("\n");
  }
}

// Function to get a move from the player
void get_move(int *row, int *col) {
  printf("Enter the row and column of the card you want to flip (e.g. 1 3): ");
  scanf("%d %d", row, col);
  *row--;
  *col--;
}

// Function to check if the game is over
int is_game_over() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (!grid[i][j].is_flipped) {
        return 0;
      }
    }
  }
  return 1;
}

// Main function
int main() {
  // Initialize the game board
  init_board();

  // Print the game board
  print_board();

  // Get the player's move
  int row, col;
  get_move(&row, &col);

  // Flip the card
  grid[row][col].is_flipped = 1;

  // Print the new board
  print_board();

  // Check if the game is over
  if (is_game_over()) {
    printf("Congratulations! You won!\n");
  } else {
    printf("Keep playing!\n");
  }

  return 0;
}