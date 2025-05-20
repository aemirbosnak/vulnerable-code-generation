//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *s1, char *s2) {
  int len1 = strlen(s1);
  int len2 = strlen(s2);

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
      if (s1[i - 1] == s2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = 1 + fmin(matrix[i - 1][j], fmin(matrix[i][j - 1], matrix[i - 1][j - 1]));
      }
    }
  }

  // Return the Levenshtein distance
  return matrix[len1][len2];
}

// Main function
int main() {
  // Get the two strings from the user
  char s1[MAX_STR_LEN];
  char s2[MAX_STR_LEN];
  printf("Enter the first string: ");
  scanf("%s", s1);
  printf("Enter the second string: ");
  scanf("%s", s2);

  // Calculate the Levenshtein distance between the two strings
  int distance = levenshtein_distance(s1, s2);

  // Print the Levenshtein distance
  printf("The Levenshtein distance between the two strings is: %d\n", distance);

  return 0;
}