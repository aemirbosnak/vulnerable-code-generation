//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the strings to compare
#define MAX_STRING_LENGTH 100

// Declare the function to calculate the Levenshtein distance
int levenshtein_distance(char* str1, char* str2);

// Main function
int main() {
  // Declare the two strings to compare
  char str1[MAX_STRING_LENGTH];
  char str2[MAX_STRING_LENGTH];

  // Prompt the user to enter the first string
  printf("Enter the first string: ");
  scanf("%s", str1);

  // Prompt the user to enter the second string
  printf("Enter the second string: ");
  scanf("%s", str2);

  // Calculate the Levenshtein distance between the two strings
  int distance = levenshtein_distance(str1, str2);

  // Print the Levenshtein distance
  printf("The Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);

  return 0;
}

// Function to calculate the Levenshtein distance
int levenshtein_distance(char* str1, char* str2) {
  // Get the lengths of the strings
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

  // Calculate the Levenshtein distances for the rest of the matrix
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        matrix[i][j] = matrix[i - 1][j - 1];
      } else {
        matrix[i][j] = 1 + fmin(fmin(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]);
      }
    }
  }

  // Return the Levenshtein distance
  return matrix[len1][len2];
}