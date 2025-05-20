//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_PAIRS 8
#define GRID_SIZE 4

typedef struct {
  int value;
  bool revealed;
} Card;

void print_grid(Card grid[GRID_SIZE][GRID_SIZE]) {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (grid[i][j].revealed) {
        printf("%d ", grid[i][j].value);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
}

bool is_match(Card card1, Card card2) {
  return card1.value == card2.value;
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the game grid
  Card grid[GRID_SIZE][GRID_SIZE];

  // Generate the random numbers
  int numbers[NUM_PAIRS * 2];
  for (int i = 0; i < NUM_PAIRS * 2; i++) {
    numbers[i] = rand() % (NUM_PAIRS + 1);
  }

  // Assign the numbers to the cards
  int index = 0;
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      grid[i][j].value = numbers[index++];
      grid[i][j].revealed = false;
    }
  }

  // Print the initial grid
  print_grid(grid);

  // Start the game loop
  while (true) {
    // Get the user's input
    int row1, col1, row2, col2;
    printf("Enter the coordinates of the first card (row, column): ");
    scanf("%d %d", &row1, &col1);
    printf("Enter the coordinates of the second card (row, column): ");
    scanf("%d %d", &row2, &col2);

    // Check if the cards are valid
    if (row1 < 0 || row1 >= GRID_SIZE || col1 < 0 || col1 >= GRID_SIZE ||
        row2 < 0 || row2 >= GRID_SIZE || col2 < 0 || col2 >= GRID_SIZE) {
      printf("Invalid coordinates. Please try again.\n");
      continue;
    }

    // Reveal the cards
    grid[row1][col1].revealed = true;
    grid[row2][col2].revealed = true;

    // Print the updated grid
    print_grid(grid);

    // Check if the cards match
    if (is_match(grid[row1][col1], grid[row2][col2])) {
      printf("Match!\n");

      // Remove the cards from the board
      grid[row1][col1].value = 0;
      grid[row2][col2].value = 0;
    } else {
      printf("No match. Try again.\n");

      // Hide the cards
      grid[row1][col1].revealed = false;
      grid[row2][col2].revealed = false;
    }

    // Check if the game is over
    int num_revealed = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
      for (int j = 0; j < GRID_SIZE; j++) {
        if (grid[i][j].revealed) {
          num_revealed++;
        }
      }
    }

    if (num_revealed == NUM_PAIRS * 2) {
      printf("Congratulations! You won the game.\n");
      break;
    }
  }

  return 0;
}