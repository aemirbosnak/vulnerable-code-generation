//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
// Amidst the desolate wasteland, a flickering terminal glows with the embers of ingenuity.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

int main() {
  char str1[MAX_STR_LEN], str2[MAX_STR_LEN];
  int len1, len2, i, j, cost, min_cost;

  printf("\nIn this ravaged world, words bear the weight of their differences.\n");
  printf("Let us delve into the abyss of two utterances:\n");

  printf("\nEnter the first string, scarred by time: ");
  scanf("%s", str1);
  printf("Now bestow upon me the second string, its counterpart in adversity: ");
  scanf("%s", str2);

  len1 = strlen(str1);
  len2 = strlen(str2);

  int dp[len1 + 1][len2 + 1];

  // Initialize the first row and column of the Levenshtein distance matrix.
  for (i = 0; i <= len1; i++) {
    dp[i][0] = i;
  }
  for (j = 0; j <= len2; j++) {
    dp[0][j] = j;
  }

  // Calculate the Levenshtein distance
  for (i = 1; i <= len1; i++) {
    for (j = 1; j <= len2; j++) {
      // Calculate the cost of the three possible operations.
      cost = str1[i - 1] == str2[j - 1] ? 0 : 1;

      // Find the minimum cost of the three operations.
      min_cost = dp[i - 1][j] + 1;  // Deletion
      if (dp[i][j - 1] + 1 < min_cost) {  // Insertion
        min_cost = dp[i][j - 1] + 1;
      }
      if (cost + dp[i - 1][j - 1] < min_cost) {  // Substitution
        min_cost = cost + dp[i - 1][j - 1];
      }

      // Update the Levenshtein distance matrix.
      dp[i][j] = min_cost;
    }
  }

  printf("\nThe Levenshtein distance between these strings, a testament to their divergence, is: %d\n", dp[len1][len2]);

  return 0;
}