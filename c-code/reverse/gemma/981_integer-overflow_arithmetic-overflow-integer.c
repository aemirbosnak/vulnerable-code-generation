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
  int n;
  scanf("Enter the number of strings: ", &n);

  char **arr = malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    arr[i] = malloc(1024);
  }

  for (int i = 0; i < n; i++) {
    printf("Enter the string: ");
    scanf("%s", arr[i]);
  }

  qsort(arr, n, sizeof(char *), cmp);

  printf("The sorted strings are:\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", arr[i]);
  }

  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}
