//GEMINI-pro DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rows and columns in the grid
#define ROWS 5
#define COLUMNS 5

// Create a 2D array to represent the grid
int grid[ROWS][COLUMNS];

// Function to generate a random grid
void generateGrid() {
  // Seed the random number generator
  srand(time(NULL));

  // Loop through each row and column
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      // Generate a random number between 0 and 9
      grid[i][j] = rand() % 10;
    }
  }
}

// Function to print the grid
void printGrid() {
  // Loop through each row and column
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      // Print the value at the current row and column
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a given number is present in the grid
int findNumber(int number) {
  // Loop through each row and column
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      // If the number is found, return 1
      if (grid[i][j] == number) {
        return 1;
      }
    }
  }

  // If the number is not found, return 0
  return 0;
}

// Main function
int main() {
  // Generate the grid
  generateGrid();

  // Print the grid
  printGrid();

  // Get the number to search for from the user
  int number;
  printf("Enter the number you want to find: ");
  scanf("%d", &number);

  // Check if the number is present in the grid
  int result = findNumber(number);

  // Print the result
  if (result) {
    printf("The number %d is present in the grid.\n", number);
  } else {
    printf("The number %d is not present in the grid.\n", number);
  }

  return 0;
}