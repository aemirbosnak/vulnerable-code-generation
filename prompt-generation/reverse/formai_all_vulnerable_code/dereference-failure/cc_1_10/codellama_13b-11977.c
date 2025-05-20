//Code Llama-13B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shape shifting
/*
 * Levenshtein Distance Calculator
 *
 * This program calculates the Levenshtein distance between two strings.
 * The Levenshtein distance is a measure of the number of single-character edits
 * (insertions, deletions, and substitutions) required to change one string
 * into the other.
 *
 * The program takes two command-line arguments: the first is the first string,
 * and the second is the second string. The program then calculates the
 * Levenshtein distance between the two strings and prints it to the console.
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Check if the number of command-line arguments is correct
  if (argc != 3) {
    printf("Usage: %s <string1> <string2>\n", argv[0]);
    return 1;
  }

  // Get the two strings from the command-line arguments
  char *string1 = argv[1];
  char *string2 = argv[2];

  // Calculate the Levenshtein distance between the two strings
  int distance = levenshtein_distance(string1, string2);

  // Print the result to the console
  printf("Levenshtein distance between %s and %s is %d\n", string1, string2, distance);

  return 0;
}

int levenshtein_distance(char *s1, char *s2) {
  // Get the lengths of the two strings
  int n = strlen(s1);
  int m = strlen(s2);

  // Create a 2D array to store the Levenshtein distances
  int dp[n+1][m+1];

  // Initialize the first row and column of the array
  for (int i = 0; i <= n; i++) {
    dp[i][0] = i;
  }
  for (int j = 0; j <= m; j++) {
    dp[0][j] = j;
  }

  // Fill in the rest of the array
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int min = dp[i-1][j-1] + (s1[i-1] != s2[j-1]);
      min = min < dp[i-1][j] ? min : dp[i-1][j];
      min = min < dp[i][j-1] ? min : dp[i][j-1];
      dp[i][j] = min;
    }
  }

  // Return the last value in the array (the Levenshtein distance)
  return dp[n][m];
}