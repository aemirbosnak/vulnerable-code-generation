//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compute the Levenshtein distance between two strings.
int levenshtein(const char *s1, const char *s2) {
  // Create a matrix to store the distances.
  int m = strlen(s1) + 1;
  int n = strlen(s2) + 1;
  int d[m][n];

  // Initialize the first row and column of the matrix.
  for (int i = 0; i < m; i++) {
    d[i][0] = i;
  }
  for (int j = 0; j < n; j++) {
    d[0][j] = j;
  }

  // Compute the Levenshtein distance for each cell in the matrix.
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        d[i][j] = d[i - 1][j - 1];
      } else {
        d[i][j] = 1 + fmin(fmin(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]);
      }
    }
  }

  // Return the Levenshtein distance.
  return d[m - 1][n - 1];
}

// Print the Levenshtein distance matrix.
void print_matrix(int m, int n, int d[m][n]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", d[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Get the two strings from the user.
  char s1[100], s2[100];
  printf("Enter the first string: ");
  scanf("%s", s1);
  printf("Enter the second string: ");
  scanf("%s", s2);

  // Compute the Levenshtein distance between the two strings.
  int distance = levenshtein(s1, s2);

  // Print the Levenshtein distance.
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

  return 0;
}