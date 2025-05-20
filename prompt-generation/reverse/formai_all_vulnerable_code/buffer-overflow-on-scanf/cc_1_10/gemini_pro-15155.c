//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
  size_t len1 = strlen(s1);
  size_t len2 = strlen(s2);

  // Create a matrix to store the Levenshtein distances
  int matrix[len1 + 1][len2 + 1];

  // Initialize the first row and column of the matrix
  for (size_t i = 0; i <= len1; i++) {
    matrix[i][0] = i;
  }
  for (size_t j = 0; j <= len2; j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distances for the rest of the matrix
  for (size_t i = 1; i <= len1; i++) {
    for (size_t j = 1; j <= len2; j++) {
      int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
      int min = matrix[i - 1][j] + 1;  // Deletion
      if (matrix[i][j - 1] + 1 < min) {  // Insertion
        min = matrix[i][j - 1] + 1;
      }
      if (matrix[i - 1][j - 1] + cost < min) {  // Substitution
        min = matrix[i - 1][j - 1] + cost;
      }
      matrix[i][j] = min;
    }
  }

  // Return the Levenshtein distance
  return matrix[len1][len2];
}

int main() {
  // Get the two strings from the user
  char s1[100], s2[100];
  printf("Enter the first string: ");
  scanf("%s", s1);
  printf("Enter the second string: ");
  scanf("%s", s2);

  // Calculate the Levenshtein distance
  int distance = levenshtein(s1, s2);

  // Print the result
  printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

  return 0;
}