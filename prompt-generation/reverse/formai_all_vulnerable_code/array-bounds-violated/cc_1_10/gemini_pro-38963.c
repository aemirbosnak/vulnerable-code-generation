//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: puzzling
// Embark on a perplexing memory maze!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 4  // Customize the grid size here, must be > 1
#define COUNT (SIZE * SIZE)  // Number of tiles

// Declare the grid and variables
int grid[SIZE][SIZE];
int discovered[SIZE][SIZE];
int score, attempts;

// Randomly initialize the grid with numbers
void initGrid() {
  srand(time(NULL));
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      grid[i][j] = rand() % (COUNT / 2) + 1;
    }
  }
}

// Conceal the grid, revealed tiles are marked with 0
void hideGrid() {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      discovered[i][j] = 0;
    }
  }
}

// Display the grid with revealed tiles
void showGrid() {
  printf("      ");
  for (int i = 0; i < SIZE; i++) {
    printf("%2d ", i + 1);
  }
  printf("\n    +---+---+---+---+");
  for (int i = 0; i < SIZE; i++) {
    printf("\n %2d |", i + 1);
    for (int j = 0; j < SIZE; j++) {
      printf(" %2d |", discovered[i][j] ? grid[i][j] : ' ');
    }
    printf("\n    +---+---+---+---+");
  }
  printf("\n");
}

// Get tile coordinates from the user
void getTile(int *row, int *col) {
  printf("Enter row (1-%d): ", SIZE);
  scanf("%d", row);
  (*row)--;  // Adjust for zero-indexing
  printf("Enter column (1-%d): ", SIZE);
  scanf("%d", col);
  (*col)--;
}

// Check if the tiles match
bool checkMatch(int r1, int c1, int r2, int c2) {
  if (discovered[r1][c1] && discovered[r2][c2]) {
    return grid[r1][c1] == grid[r2][c2];
  }
  return false;
}

// Reveal the tiles at the given coordinates
void revealTiles(int r1, int c1, int r2, int c2) {
  discovered[r1][c1] = 1;
  discovered[r2][c2] = 1;
  if (grid[r1][c1] == grid[r2][c2]) {
    score++;
    printf("Match found at (%d, %d) and (%d, %d)!\n", r1 + 1, c1 + 1, r2 + 1, c2 + 1);
    if (score == COUNT / 2) {
      printf("Congratulations! You won the memory game in %d attempts!\n", attempts);
      exit(0);
    }
  } else {
    printf("No match found at (%d, %d) and (%d, %d)!\n", r1 + 1, c1 + 1, r2 + 1, c2 + 1);
  }
}

// Play the memory game
void playGame() {
  int r1, c1, r2, c2;
  attempts = 0;
  score = 0;

  while (attempts < COUNT) {
    attempts++;

    system("clear");
    printf("Attempts: %d\nScore: %d\n", attempts, score);
    showGrid();

    printf("Choose the first tile (row, column): ");
    getTile(&r1, &c1);
    while (discovered[r1][c1]) {
      printf("This tile has already been revealed. Please choose another:\n");
      getTile(&r1, &c1);
    }

    system("clear");
    printf("Attempts: %d\nScore: %d\n", attempts, score);
    showGrid();

    printf("Choose the second tile (row, column): ");
    getTile(&r2, &c2);
    while ((r1 == r2 && c1 == c2) || discovered[r2][c2]) {
      printf("This tile has already been revealed or it's the same as the first one. Please choose another:\n");
      getTile(&r2, &c2);
    }

    revealTiles(r1, c1, r2, c2);
  }

  printf("Game over! You couldn't find all matches in %d attempts.\n", attempts);
}

int main() {
  initGrid();
  hideGrid();
  playGame();
  return 0;
}