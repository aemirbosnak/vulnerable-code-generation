#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

int main() {
  char **arr = NULL;
  int n = 0;

  // Allocate memory for the array
  arr = malloc(n * sizeof(char *));

  // Get the number of strings from the user
  printf("Enter the number of strings: ");
  scanf("%d", &n);

  // Allocate memory for each string
  arr = realloc(arr, n * sizeof(char *));

  // Get the strings from the user
  for (int i = 0; i < n; i++) {
    arr[i] = malloc(1024);
    printf("Enter the string: ");
    scanf("%s", arr[i]);
  }

  // Sort the array of strings
  qsort(arr, n, sizeof(char *), cmp);

  // Print the sorted strings
  for (int i = 0; i < n; i++) {
    printf("%s\n", arr[i]);
  }

  // Free the memory allocated for the array
  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }

  // Free the memory allocated for the array
  free(arr);

  return 0;
}
