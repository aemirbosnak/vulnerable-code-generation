//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings
int levenshtein(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);

  // Create a matrix to store the Levenshtein distances
  int matrix[len1 + 1][len2 + 1];

  // Initialize the first row and column of the matrix
  for (int i = 0; i <= len1; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= len2; j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distances
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = fmin(matrix[i - 1][j], fmin(matrix[i][j - 1], matrix[i - 1][j - 1])) + 1;
      }
    }
  }

  // Return the Levenshtein distance
  return matrix[len1][len2];
}

int main() {
  // Get the two strings from the user
  char str1[100];
  char str2[100];
  printf("Enter the first string: ");
  scanf("%s", str1);
  printf("Enter the second string: ");
  scanf("%s", str2);

  // Calculate the Levenshtein distance
  int distance = levenshtein(str1, str2);

  // Print the Levenshtein distance
  printf("The Levenshtein distance between the two strings is: %d\n", distance);

  return 0;
}