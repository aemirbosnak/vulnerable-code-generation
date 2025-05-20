//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of rows and columns in the pattern
#define MAX_ROWS 10
#define MAX_COLS 10

// Define the character to be used for printing the pattern
#define PATTERN_CHAR '*'

// Define the function to print the pattern
void printPattern(int rows, int cols) {
  // Check if the input is valid
  if (rows <= 0 || cols <= 0) {
    printf("Invalid input: rows and columns must be positive integers.\n");
    return;
  }

  // Allocate memory for the pattern array
  char** pattern = (char**)malloc(rows * sizeof(char*));
  for (int i = 0; i < rows; i++) {
    pattern[i] = (char*)malloc(cols * sizeof(char));
  }

  // Initialize the pattern array with spaces
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      pattern[i][j] = ' ';
    }
  }

  // Set the center of the pattern to the pattern character
  int centerRow = rows / 2;
  int centerCol = cols / 2;
  pattern[centerRow][centerCol] = PATTERN_CHAR;

  // Print the pattern
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c", pattern[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the pattern array
  for (int i = 0; i < rows; i++) {
    free(pattern[i]);
  }
  free(pattern);
}

// Main function
int main() {
  // Get the number of rows and columns from the user
  int rows, cols;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  // Print the pattern
  printPattern(rows, cols);

  return 0;
}