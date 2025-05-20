#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 10

int main() {
  int i, entries = 0, maxEntries = MAX_ENTRIES;
  char **entriesArr = NULL;

  entriesArr = (char**)malloc(maxEntries * sizeof(char*));

  for (i = 0; i < maxEntries && entries < maxEntries; i++) {
    entriesArr[entries] = (char*)malloc(256);
    printf("Enter your diary entry: ");
    scanf("%s", entriesArr[entries]);
    entries++;
  }

  printf("Here are your entries:\n");
  for (i = 0; i < entries; i++) {
    printf("%s\n", entriesArr[i]);
  }

  for (i = 0; i < entries; i++) {
    free(entriesArr[i]);
  }
  free(entriesArr);

  return 0;
}
