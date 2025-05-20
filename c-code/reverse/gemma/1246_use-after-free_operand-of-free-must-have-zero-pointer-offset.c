#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, n, size = 10;
  char **entries = (char**)malloc(size * sizeof(char*));
  for (i = 0; i < size; i++) {
    entries[i] = (char*)malloc(100 * sizeof(char));
  }

  printf("Enter the number of entries: ");
  scanf("%d", &n);

  if (n > size) {
    printf("Error: insufficient memory.\n");
  } else {
    for (i = 0; i < n; i++) {
      printf("Enter the entry: ");
      scanf("%s", entries[i]);
      entries[i] = (char*)realloc(entries[i], 200 * sizeof(char));
    }

    for (i = 0; i < n; i++) {
      free(entries[i]);
    }
    free(entries);
  }

  return 0;
}
