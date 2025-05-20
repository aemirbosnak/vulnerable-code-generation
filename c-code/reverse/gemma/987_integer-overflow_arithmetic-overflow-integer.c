#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 256

int compareStrings(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

int main() {
  char **arr = NULL;
  int n = 0;

  printf("Enter the number of strings: ");
  scanf("%d", &n);

  arr = (char **)malloc(n * sizeof(char *));
  if (arr == NULL) {
    return 1;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = (char *)malloc(MAX_STRING_LENGTH);
    if (arr[i] == NULL) {
      return 1;
    }
    printf("Enter the string: ");
    scanf("%s", arr[i]);
  }

  qsort(arr, n, sizeof(char *), compareStrings);

  printf("Sorted strings:\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", arr[i]);
  }

  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}
