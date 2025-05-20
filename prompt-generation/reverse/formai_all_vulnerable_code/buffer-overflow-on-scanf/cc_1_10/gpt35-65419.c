//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: careful
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c) {
  if(a < b && a < c) {
    return a;
  }
  else if(b < a && b < c) {
    return b;
  }
  else {
    return c;
  }
}

int levenshteinDistance(char *word1, char *word2, int len1, int len2) {
  int distance[len1 + 1][len2 + 1];
  int i, j;

  for(i = 0; i <= len1; i++) {
    for(j = 0; j <= len2; j++) {
      if(i == 0) {
        distance[i][j] = j;
      }
      else if(j == 0) {
        distance[i][j] = i;
      }
      else if(word1[i-1] == word2[j-1]) {
        distance[i][j] = distance[i-1][j-1];
      }
      else {
        distance[i][j] = minimum(distance[i-1][j], distance[i][j-1], distance[i-1][j-1]) + 1;
      }
    }
  }

  return distance[len1][len2];
}

int main() {
  char word1[100], word2[100];
  printf("Enter first word: ");
  scanf("%s", word1);
  printf("Enter second word: ");
  scanf("%s", word2);

  int len1 = strlen(word1);
  int len2 = strlen(word2);

  int distance = levenshteinDistance(word1, word2, len1, len2);

  printf("The Levenshtein distance between '%s' and '%s' is %d\n", word1, word2, distance);
  return 0;
}