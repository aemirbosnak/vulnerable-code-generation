#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int main() {
  int n = 0;
  scanf("%d", &n);

  char **arr = (char **)malloc((n + 1) * sizeof(char *));
  if (arr == NULL) {
    return 1;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = (char *)malloc(100);
  }

  // QuickSort logic using the allocated array

  free(arr);
  return 0;
}
