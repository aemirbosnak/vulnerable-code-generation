//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein_distance(char *str1, char *str2);

int main(void) {
  char *str1, *str2;
  int distance;
  
  printf("Welcome to the Mind-Bending Levenshtein Distance Calculator!\n");
  printf("Please enter the first string:\n");
  scanf("%ms", &str1); //we use %ms specifier to dynamically allocate memory for input string
  printf("Please enter the second string:\n");
  scanf("%ms", &str2);
  
  distance = levenshtein_distance(str1, str2);
  
  printf("The Levenshtein Distance between %s and %s is %d\n", str1, str2, distance);
  
  free(str1); //freeing dynamically allocated memory
  free(str2);
  
  return 0;
}

int levenshtein_distance(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int **dp = malloc((len1 + 1) * sizeof(int*)); //dynamically allocating 2D array for dynamic programming
  int i, j;
  for (i = 0; i <= len1; i++) {
    dp[i] = malloc((len2 + 1) * sizeof(int));
    dp[i][0] = i;
  }
  
  for (j = 0; j <= len2; j++) {
    dp[0][j] = j;
  }
  
  for (i = 1; i <= len1; i++) {
    for (j = 1; j <= len2; j++) {
      if (str1[i-1] == str2[j-1]) {
        dp[i][j] = dp[i-1][j-1];
      } else {
        int min_val = dp[i-1][j-1]; //initialize min_val to diagonal element
        if (dp[i][j-1] < min_val) { //compare with left element
          min_val = dp[i][j-1];
        }
        if (dp[i-1][j] < min_val) { //compare with top element
          min_val = dp[i-1][j];
        }
        dp[i][j] = min_val + 1; //update with min_val + 1
      }
    }
  }
  
  int result = dp[len1][len2];
  
  for (i = 0; i <= len1; i++) {
    free(dp[i]); //freeing dynamically allocated 2D array
  }
  free(dp);
  
  return result;
}