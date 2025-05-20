//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: excited
#include <stdio.h>
#include <string.h>

// Levenshtein distance:
// a measure of the similarity between two strings
// the minimum number of edits (insertions, deletions, or substitutions)
// required to transform one string into the other

// calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
  int m = strlen(s1);
  int n = strlen(s2);
  int matrix[m + 1][n + 1];

  // initialize the matrix
  for (int i = 0; i <= m; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= n; j++) {
    matrix[0][j] = j;
  }

  // calculate the Levenshtein distance
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
      matrix[i][j] = minimum(matrix[i - 1][j] + 1,  // deletion
                               matrix[i][j - 1] + 1,  // insertion
                               matrix[i - 1][j - 1] + cost);  // substitution
    }
  }

  // return the Levenshtein distance
  return matrix[m][n];
}

// minimum of three integers
int minimum(int a, int b, int c) {
  return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

// print the Levenshtein distance matrix
void print_matrix(int m, int n, int matrix[m + 1][n + 1]) {
  printf("Levenshtein distance matrix:\n");
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}
int main()
{
    char s1[25], s2[25];
    int len1, len2, i, dist;
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    dist = levenshtein(s1, s2);
    printf("Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, dist);
    return 0;
}