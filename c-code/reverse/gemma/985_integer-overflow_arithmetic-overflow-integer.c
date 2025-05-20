#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

int main() {
  char **arr = NULL;
  int n = 0;

  // User-supplied input:
  printf("Enter the number of strings: ");
  scanf("%d", &n);

  arr = malloc(n * sizeof(char *));
  if (arr == NULL) {
    return 1;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = malloc(1024);
    if (arr[i] == NULL) {
      return 1;
    }
  }

  // Sort the array in descending order:
  qsort(arr, n, sizeof(char *), compare);

  // Print the sorted strings:
  for (int i = 0; i < n; i++) {
    printf("%s\n", arr[i]);
  }

  // Free memory:
  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}
