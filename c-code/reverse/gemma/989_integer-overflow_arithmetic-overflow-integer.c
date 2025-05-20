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

  char **strings = malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    strings[i] = malloc(100 * sizeof(char));
    scanf("Enter the string: ", strings[i]);
  }

  qsort(strings, n, sizeof(char *), cmp);

  printf("Sorted strings:\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", strings[i]);
  }

  for (int i = 0; i < n; i++) {
    free(strings[i]);
  }
  free(strings);

  return 0;
}
