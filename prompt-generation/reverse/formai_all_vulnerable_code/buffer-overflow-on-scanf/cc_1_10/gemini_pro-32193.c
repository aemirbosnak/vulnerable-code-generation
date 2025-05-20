//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a 4x4 grid of cards
char grid[4][4];

// Create an array of card values
char values[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A'};

// Initialize the grid with random values
void initializeGrid() {
  // Seed the random number generator
  srand(time(NULL));

  // Shuffle the values array
  for (int i = 0; i < 14; i++) {
    int j = rand() % 14;
    char temp = values[i];
    values[i] = values[j];
    values[j] = temp;
  }

  // Fill the grid with the shuffled values
  int index = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      grid[i][j] = values[index];
      index++;
    }
  }
}

// Print the grid to the console
void printGrid() {
  // Print the top border
  printf("   +---+---+---+---+\n");

  // Print the grid
  for (int i = 0; i < 4; i++) {
    printf("   ");
    for (int j = 0; j < 4; j++) {
      printf("| %c ", grid[i][j]);
    }
    printf("|\n   +---+---+---+---+\n");
  }
}

// Get the user's input
void getUserInput(int *row1, int *col1, int *row2, int *col2) {
  // Get the first card's row and column
  printf("Enter the row of the first card (1-4): ");
  scanf("%d", row1);
  printf("Enter the column of the first card (1-4): ");
  scanf("%d", col1);

  // Get the second card's row and column
  printf("Enter the row of the second card (1-4): ");
  scanf("%d", row2);
  printf("Enter the column of the second card (1-4): ");
  scanf("%d", col2);
}

// Check if the two cards match
int checkMatch(int row1, int col1, int row2, int col2) {
  return grid[row1 - 1][col1 - 1] == grid[row2 - 1][col2 - 1];
}

// Main game loop
int main() {
  // Initialize the grid
  initializeGrid();

  // Print the grid
  printGrid();

  // Get the user's input
  int row1, col1, row2, col2;
  getUserInput(&row1, &col1, &row2, &col2);

  // Check if the two cards match
  if (checkMatch(row1, col1, row2, col2)) {
    printf("Match!\n");
  } else {
    printf("No match.\n");
  }

  return 0;
}