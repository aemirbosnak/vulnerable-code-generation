//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the strings to be compared
#define MAX_STRING_LENGTH 100

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *str1, char *str2) {
  // Create a matrix to store the Levenshtein distances between the prefixes of the two strings
  int matrix[MAX_STRING_LENGTH + 1][MAX_STRING_LENGTH + 1];

  // Initialize the first row and column of the matrix
  for (int i = 0; i <= strlen(str1); i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= strlen(str2); j++) {
    matrix[0][j] = j;
  }

  // Calculate the Levenshtein distances between the prefixes of the two strings
  for (int i = 1; i <= strlen(str1); i++) {
    for (int j = 1; j <= strlen(str2); j++) {
      if (str1[i - 1] == str2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = 1 + fmin(fmin(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]);
      }
    }
  }

  // Return the Levenshtein distance between the two strings
  return matrix[strlen(str1)][strlen(str2)];
}

// Main function
int main() {
  // Get the two strings from the user
  char str1[MAX_STRING_LENGTH];
  char str2[MAX_STRING_LENGTH];
  printf("Enter the first string: ");
  scanf("%s", str1);
  printf("Enter the second string: ");
  scanf("%s", str2);

  // Calculate the Levenshtein distance between the two strings
  int distance = levenshtein_distance(str1, str2);

  // Print the Levenshtein distance
  printf("The Levenshtein distance between the two strings is: %d\n", distance);

  return 0;
}