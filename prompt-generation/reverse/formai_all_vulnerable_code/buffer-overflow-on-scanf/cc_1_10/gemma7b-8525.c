//Gemma-7B DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(char **arr, int n, int i, char **res) {
  if (i >= n) {
    res[0] = '\0';
    return;
  }

  for (int j = 0; j < n; j++) {
    if (arr[j] && !res[j]) {
      res[i] = arr[j];
      dfs(arr, n, i + 1, res);
      res[i] = '\0';
    }
  }
}

int main() {
  char **arr = NULL;
  int n = 0;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    arr[i] = (char *)malloc(20 * sizeof(char));
  }

  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%s", arr[i]);
  }

  char **res = NULL;
  res = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    res[i] = (char *)malloc(20 * sizeof(char));
  }

  dfs(arr, n, 0, res);

  printf("The permutations are:\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", res[i]);
  }

  return 0;
}