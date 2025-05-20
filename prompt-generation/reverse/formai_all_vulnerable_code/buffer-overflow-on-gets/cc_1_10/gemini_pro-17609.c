//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance is a measure of the similarity between two strings.
// It is the minimum number of edits (insertions, deletions, or substitutions)
// required to transform one string into the other.

// This function computes the Levenshtein distance between two strings.
int levenshtein(const char *s1, const char *s2) {
  // Create a matrix to store the Levenshtein distances between the prefixes of s1 and s2.
  int m = strlen(s1) + 1;
  int n = strlen(s2) + 1;
  int matrix[m][n];

  // Initialize the first row and column of the matrix.
  for (int i = 0; i < m; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j < n; j++) {
    matrix[0][j] = j;
  }

  // Compute the Levenshtein distances between the prefixes of s1 and s2.
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        // If the last characters of the prefixes are the same, then the Levenshtein distance
        // between the prefixes is the same as the Levenshtein distance between the prefixes
        // of length i-1 and j-1.
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        // If the last characters of the prefixes are different, then the Levenshtein distance
        // between the prefixes is the minimum of the Levenshtein distances between the prefixes
        // of length i-1 and j, i and j-1, and i-1 and j-1.
        matrix[i][j] = 1 + fmin(matrix[i - 1][j], fmin(matrix[i][j - 1], matrix[i - 1][j - 1]));
      }
    }
  }

  // Return the Levenshtein distance between the strings.
  return matrix[m - 1][n - 1];
}

int main() {
  // Get the two strings from the user.
  char s1[100], s2[100];
  printf("Enter the first string: ");
  gets(s1);
  printf("Enter the second string: ");
  gets(s2);

  // Compute the Levenshtein distance between the strings.
  int distance = levenshtein(s1, s2);

  // Print the Levenshtein distance.
  printf("The Levenshtein distance between the two strings is: %d\n", distance);

  return 0;
}