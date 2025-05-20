//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ROWS 4
#define NUM_COLS 4
/*
This is a game where you have to match two cards with the same symbol.
The cards are placed in a 4x4 grid, and each card has a different symbol.
The player has to guess which two cards have the same symbol, and if they guess correctly, the cards will disappear.
The game ends when all the cards have been matched.
*/

// structure to keep track of cards
typedef struct {
  char symbol;
  int matched;
} card_t;

// game state
card_t grid[NUM_ROWS][NUM_COLS];
int num_matched;

// function to initialize the game
void init_game() {
  // initialize the grid
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      grid[i][j].matched = 0;
    }
  }
  // create a list of all the symbols
  char symbols[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  // randomize the symbols
  srand(time(NULL));
  for (int i = 0; i < NUM_ROWS * NUM_COLS; i++) {
    int r = rand() % (NUM_ROWS * NUM_COLS);
    char temp = symbols[i];
    symbols[i] = symbols[r];
    symbols[r] = temp;
  }
  // place the symbols in the grid
  int index = 0;
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      grid[i][j].symbol = symbols[index++];
    }
  }
  // set the number of matched cards to 0
  num_matched = 0;
}

// function to print the grid
void print_grid() {
  printf("  ");
  for (int i = 0; i < NUM_COLS; i++) {
    printf("%2d ", i + 1);
  }
  printf("\n");
  for (int i = 0; i < NUM_ROWS; i++) {
    printf("%2d ", i + 1);
    for (int j = 0; j < NUM_COLS; j++) {
      if (grid[i][j].matched) {
        printf("  ");
      } else {
        printf("%2c ", grid[i][j].symbol);
      }
    }
    printf("\n");
  }
}

// function to get player input
void get_input(int *row1, int *col1, int *row2, int *col2) {
  printf("Enter the coordinates of the first card (row, column): ");
  scanf("%d %d", row1, col1);
  printf("Enter the coordinates of the second card (row, column): ");
  scanf("%d %d", row2, col2);
}

// function to check if two cards match
int check_match(int row1, int col1, int row2, int col2) {
  return grid[row1][col1].symbol == grid[row2][col2].symbol;
}

// function to play the game
void play_game() {
  int row1, col1, row2, col2;
  while (num_matched < NUM_ROWS * NUM_COLS) {
    print_grid();
    get_input(&row1, &col1, &row2, &col2);
    if (check_match(row1, col1, row2, col2)) {
      grid[row1][col1].matched = 1;
      grid[row2][col2].matched = 1;
      num_matched += 2;
      printf("Match!\n");
    } else {
      printf("No match.\n");
    }
  }
  printf("Congratulations! You matched all the cards!\n");
}

int main() {
  init_game();
  play_game();
  return 0;
}