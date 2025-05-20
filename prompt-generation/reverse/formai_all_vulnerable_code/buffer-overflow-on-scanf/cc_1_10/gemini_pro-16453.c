//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of rows and columns in the pattern
#define MAX_ROWS 10
#define MAX_COLS 10

// Define the character to be used for printing the pattern
#define PATTERN_CHAR '*'

// Function to print the futuristic pattern
void print_futuristic_pattern(int rows, int cols) {
  // Check if the given dimensions are valid
  if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
    printf("Invalid dimensions for the pattern!\n");
    return;
  }

  // Create a 2D array to represent the pattern
  char pattern[rows][cols];

  // Initialize the pattern with spaces
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      pattern[i][j] = ' ';
    }
  }

  // Set the futuristic pattern in the 2D array
  int mid_row = rows / 2;
  int mid_col = cols / 2;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      // Check if the current cell is on the main diagonal
      if (i == j) {
        pattern[i][j] = PATTERN_CHAR;
      }
      // Check if the current cell is on the secondary diagonal
      else if (i + j == rows - 1) {
        pattern[i][j] = PATTERN_CHAR;
      }
      // Check if the current cell is in the upper-left quadrant
      else if (i < mid_row && j < mid_col) {
        pattern[i][j] = PATTERN_CHAR;
      }
      // Check if the current cell is in the lower-right quadrant
      else if (i >= mid_row && j >= mid_col) {
        pattern[i][j] = PATTERN_CHAR;
      }
    }
  }

  // Print the futuristic pattern
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c", pattern[i][j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Get the number of rows and columns from the user
  int rows, cols;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  // Print the futuristic pattern
  print_futuristic_pattern(rows, cols);

  return 0;
}