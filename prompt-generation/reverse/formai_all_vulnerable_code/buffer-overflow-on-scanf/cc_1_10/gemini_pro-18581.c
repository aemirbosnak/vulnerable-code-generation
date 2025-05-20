//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance calculator
int levenshtein(const char *s1, const char *s2) {
  int m = strlen(s1);
  int n = strlen(s2);
  int matrix[m + 1][n + 1];

  // Initialize first row and first column
  for (int i = 0; i <= m; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= n; j++) {
    matrix[0][j] = j;
  }

  // Calculate Levenshtein distance
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int substitutionCost = s1[i - 1] == s2[j - 1] ? 0 : 1;
      int deletionCost = matrix[i - 1][j] + 1;
      int insertionCost = matrix[i][j - 1] + 1;
      matrix[i][j] = min(min(substitutionCost, deletionCost), insertionCost);
    }
  }

  // Return Levenshtein distance
  return matrix[m][n];
}

// Minimum of three integers
int min(int a, int b, int c) {
  return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

// Main function
int main() {
  // Get strings from user
  char s1[100], s2[100];
  printf("Enter the first string: ");
  scanf("%s", s1);
  printf("Enter the second string: ");
  scanf("%s", s2);

  // Calculate Levenshtein distance
  int distance = levenshtein(s1, s2);

  // Print Levenshtein distance
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

  return 0;
}