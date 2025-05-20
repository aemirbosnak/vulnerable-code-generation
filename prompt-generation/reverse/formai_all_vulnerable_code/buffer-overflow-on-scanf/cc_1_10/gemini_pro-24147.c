//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Levenshtein distance between two strings
int levenshtein(const char *a, const char *b) {
  // Declare a matrix to store the Levenshtein distances
  int n = strlen(a), m = strlen(b);
  int matrix[n + 1][m + 1];

  // Initialize the matrix
  for (int i = 0; i <= n; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= m; j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distance for each pair of characters
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
      matrix[i][j] = min(min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
    }
  }

  // Return the Levenshtein distance between the two strings
  return matrix[n][m];
}

// Minimum of three integers
int min(int a, int b, int c) {
  return fmin(fmin(a, b), c);
}

// Entry point
int main() {
  // Get the input strings
  char a[100], b[100];
  printf("Enter the first string: ");
  scanf("%s", a);
  printf("Enter the second string: ");
  scanf("%s", b);

  // Calculate the Levenshtein distance
  int distance = levenshtein(a, b);

  // Print the result
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", a, b, distance);

  return 0;
}