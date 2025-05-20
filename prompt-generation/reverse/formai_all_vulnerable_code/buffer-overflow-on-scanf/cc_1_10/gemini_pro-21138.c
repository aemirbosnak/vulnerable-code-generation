//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the strings to compare.
#define MAX_STR_LEN 100

// Define the cost of insertion, deletion, and substitution.
#define COST_INS 1
#define COST_DEL 1
#define COST_SUB 1

// Function to calculate the Levenshtein distance between two strings.
int levenshtein(char *str1, char *str2) {
  // Create a matrix to store the Levenshtein distances.
  int matrix[MAX_STR_LEN + 1][MAX_STR_LEN + 1];

  // Initialize the first row and column of the matrix.
  for (int i = 0; i <= strlen(str1); i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= strlen(str2); j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distance for each pair of characters.
  for (int i = 1; i <= strlen(str1); i++) {
    for (int j = 1; j <= strlen(str2); j++) {
      int cost = (str1[i - 1] == str2[j - 1]) ? 0 : COST_SUB;
      matrix[i][j] = fmin(fmin(matrix[i - 1][j] + COST_DEL, matrix[i][j - 1] + COST_INS), matrix[i - 1][j - 1] + cost);
    }
  }

  // Return the Levenshtein distance between the two strings.
  return matrix[strlen(str1)][strlen(str2)];
}

// Main function.
int main() {
  // Get the two strings from the user.
  char str1[MAX_STR_LEN], str2[MAX_STR_LEN];
  printf("Enter the first string: ");
  scanf("%s", str1);
  printf("Enter the second string: ");
  scanf("%s", str2);

  // Calculate the Levenshtein distance between the two strings.
  int distance = levenshtein(str1, str2);

  // Print the Levenshtein distance.
  printf("The Levenshtein distance between the two strings is: %d\n", distance);

  return 0;
}