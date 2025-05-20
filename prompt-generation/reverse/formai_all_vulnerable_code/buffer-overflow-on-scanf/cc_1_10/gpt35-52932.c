//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
  if (a < b && a < c) {
    return a;
  } else if (b < a && b < c) {
    return b;
  } else {
    return c;
  }
}

int levenshtein_distance(char *s1, char *s2) {
  int m = strlen(s1);
  int n = strlen(s2);
  int distances[m+1][n+1];

  for (int i = 0; i <= m; i++) {
    distances[i][0] = i;
  }

  for (int j = 0; j <= n; j++) {
    distances[0][j] = j;
  }

  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      if (s1[i-1] == s2[j-1]) {
        distances[i][j] = distances[i-1][j-1];
      } else {
        distances[i][j] = min(distances[i-1][j-1], distances[i][j-1], distances[i-1][j]) + 1;
      }
    }
  }

  return distances[m][n];
}

int main() {
  char s1[100], s2[100];
  int distance;

  printf("Enter first string: ");
  scanf("%s", s1);

  printf("Enter second string: ");
  scanf("%s", s2);

  distance = levenshtein_distance(s1, s2);

  printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", s1, s2, distance);

  return 0;
}