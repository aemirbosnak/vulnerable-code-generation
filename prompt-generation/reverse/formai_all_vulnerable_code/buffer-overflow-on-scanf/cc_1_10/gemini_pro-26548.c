//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the strings to be compared
#define MAX_STRING_LENGTH 100

// Define the cost of insertion, deletion, and substitution
#define COST_INSERTION 1
#define COST_DELETION 1
#define COST_SUBSTITUTION 1

// Declare the main function
int main(void) {
  // Declare the two strings to be compared
  char string1[MAX_STRING_LENGTH];
  char string2[MAX_STRING_LENGTH];

  // Get the two strings from the user
  printf("Enter the first string: ");
  scanf("%s", string1);
  printf("Enter the second string: ");
  scanf("%s", string2);

  // Calculate the length of the two strings
  int length1 = strlen(string1);
  int length2 = strlen(string2);

  // Create a matrix to store the Levenshtein distances
  int matrix[length1 + 1][length2 + 1];

  // Initialize the first row and column of the matrix
  for (int i = 0; i <= length1; i++) {
    matrix[i][0] = i * COST_INSERTION;
  }
  for (int j = 0; j <= length2; j++) {
    matrix[0][j] = j * COST_DELETION;
  }

  // Calculate the Levenshtein distances
  for (int i = 1; i <= length1; i++) {
    for (int j = 1; j <= length2; j++) {
      if (string1[i - 1] == string2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = fmin(fmin(matrix[i - 1][j] + COST_INSERTION, matrix[i][j - 1] + COST_DELETION), matrix[i - 1][j - 1] + COST_SUBSTITUTION);
      }
    }
  }

  // Print the Levenshtein distance
  printf("The Levenshtein distance between the two strings is: %d\n", matrix[length1][length2]);

  return 0;
}