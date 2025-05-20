//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to calculate the minimum of three integers */
int min(int x, int y, int z) {
  if (x <= y && x <= z) {
      return x;
  } else if (y <= x && y <= z) {
      return y;
  } else {
      return z;
  }
}

/* Function to calculate the Levenshtein Distance between two strings */
int levenshtein_dist(char *s, char *t, int m, int n) {
  int i, j, cost;
  int **d = malloc(sizeof(int *) * (m + 1));
  for (i = 0; i <= m; i++) {
      d[i] = malloc(sizeof(int) * (n + 1));
  }

  /* Initialize the 0th row and column with incremental values */
  for (i = 0; i <= m; i++) {
      d[i][0] = i;
  }
  for (j = 0; j <= n; j++) {
      d[0][j] = j;
  }

  /* Iterate through each character in the strings and calculate the distance */
  for (j = 1; j <= n; j++) {
      for (i = 1; i <= m; i++) {
          if (s[i-1] == t[j-1]) {
              cost = 0;
          } else {
              cost = 1;
          }
          d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + cost);
      }
  }

  /* Store the calculated distance and free allocated memory */
  int dist = d[m][n];
  for (i = 0; i <= m; i++) {
      free(d[i]);
  }
  free(d);
  return dist;
}

int main() {
  char s[100], t[100];
  printf("Enter the first string: ");
  scanf("%s", s);
  printf("Enter the second string: ");
  scanf("%s", t);
  int m = strlen(s);
  int n = strlen(t);

  /* Calculate the Levenshtein Distance and output result */
  int dist = levenshtein_dist(s, t, m, n);
  printf("The Levenshtein Distance between %s and %s is %d\n", s, t, dist);
  return 0;
}