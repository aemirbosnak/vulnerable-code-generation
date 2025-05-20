//FormAI DATASET v1.0 Category: Memory Game ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void clearScreen() {
  printf("\033[2J\033[1;1H");
}

int main() {
  srand(time(0));
  clearScreen();

  printf("\tSherlock Holmes Memory Game\n\n");
  printf("Welcome to the Sherlock Holmes Memory Game!\n\n");
  printf("The game is simple: you will be presented with a grid of cards.\n");
  printf("Each card has a value, and your goal is to find all pairs of cards with the same value.\n");
  printf("You will have a limited number of attempts to find all pairs.\n\n");

  const int rows = 4;
  const int cols = 4;
  const int cards = rows * cols;

  int grid[rows][cols];
  int found[cards];
  int attempts = 0;
  int numFound = 0;

  // initialize grid
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid[i][j] = rand() % (cards / 2) + 1;
    }
  }

  // initialize found
  for (int i = 0; i < cards; i++) {
    found[i] = 0;
  }

  printf("Press any key to start...\n\n");
  getchar();

  while (numFound < cards / 2) {
    clearScreen();
    printf("Attempts left: %d\n\n", 10 - attempts);

    // display grid
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (found[i * cols + j]) {
          printf("%3d ", grid[i][j]);
        } else {
          printf("%3c ", '?');
        }
      }
      printf("\n");
    }
    printf("\n");

    // get user input
    int row1, col1, row2, col2;
    printf("Enter row and column of first card: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter row and column of second card: ");
    scanf("%d %d", &row2, &col2);

    // check input validity
    if (row1 < 1 || row1 > rows || col1 < 1 || col1 > cols ||
        row2 < 1 || row2 > rows || col2 < 1 || col2 > cols ||
        (row1 == row2 && col1 == col2)) {
      printf("\nInvalid input! Please try again.\n\n");
      getchar();
      continue;
    }

    // check if cards match
    if (grid[row1 - 1][col1 - 1] == grid[row2 - 1][col2 - 1]) {
      printf("\nYou found a pair!\n\n");
      found[(row1 - 1) * cols + col1 - 1] = 1;
      found[(row2 - 1) * cols + col2 - 1] = 1;
      numFound++;
    } else {
      printf("\nSorry, those cards don't match.\n\n");
      attempts++;
      if (attempts == 10) {
        break;
      }
    }

    getchar();
  }

  clearScreen();

  if (numFound == cards / 2) {
    printf("Congratulations, you won!\n\n");
  } else {
    printf("Sorry, you lost. Better luck next time!\n\n");
  }

  printf("Press any key to exit...\n");
  getchar();

  return 0;
}