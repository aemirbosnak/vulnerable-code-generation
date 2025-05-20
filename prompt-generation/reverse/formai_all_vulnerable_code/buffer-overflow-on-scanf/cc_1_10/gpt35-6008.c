//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cryptic
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
  char str1[MAX_LEN], str2[MAX_LEN];
  int len1, len2, i, j, cost;
  int dp[MAX_LEN][MAX_LEN]; // Dynamic Programming table

  // Input strings from the user
  printf("Enter the first string (max length %d): ", MAX_LEN);
  scanf("%s", str1);

  printf("Enter the second string (max length %d): ", MAX_LEN);
  scanf("%s", str2);

  // Calculate the lengths of the input strings
  len1 = strlen(str1);
  len2 = strlen(str2);

  // Initialize the DP table with base cases
  for (i = 0; i <= len1; i++) {
    dp[i][0] = i;
  }
  for (j = 0; j <= len2; j++) {
    dp[0][j] = j;
  }

  // Fill the DP table row by row
  for (i = 1; i <= len1; i++) {
    for (j = 1; j <= len2; j++) {
      cost = (str1[i-1] == str2[j-1]) ? 0 : 1; // calculate the substitution cost
      dp[i][j] = min(dp[i-1][j] + 1,               // deletion
                     dp[i][j-1] + 1,               // insertion
                     dp[i-1][j-1] + cost);         // substitution
    }
  }

  // Print the final DP table
  printf("\nDP table:\n");
  for (i = 0; i <= len1; i++) {
    for (j = 0; j <= len2; j++) {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }

  // Print the final Levenshtein distance
  printf("\nLevenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, dp[len1][len2]);

  return 0;
}

int min(int a, int b, int c) {
  if (a < b) {
    if (a < c) {
      return a;
    } else {
      return c;
    }
  } else {
    if (b < c) {
      return b;
    } else {
      return c;
    }
  }
}