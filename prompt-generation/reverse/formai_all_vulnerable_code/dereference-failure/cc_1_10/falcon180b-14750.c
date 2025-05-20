//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
  int size = 0;
  char **arr = (char **)malloc(MAX_SIZE * sizeof(char *));
  char *input;
  char *search_term;
  char *token;
  int i, j, k;
  int found = 0;
  int count = 0;

  printf("Enter the size of the array: ");
  scanf("%d", &size);

  for (i = 0; i < size; i++) {
    printf("Enter string %d: ", i + 1);
    scanf("%s", input);
    arr[i] = input;
  }

  printf("Enter the search term: ");
  scanf("%s", search_term);

  for (i = 0; i < size; i++) {
    token = strtok(arr[i], " ");
    while (token!= NULL) {
      if (strcmp(token, search_term) == 0) {
        found = 1;
        printf("Found %s in string %d\n", search_term, i + 1);
        count++;
      }
      token = strtok(NULL, " ");
    }
  }

  if (found == 0) {
    printf("Search term not found in any string.\n");
  } else {
    printf("Found %d occurrences of %s.\n", count, search_term);
  }

  for (i = 0; i < size; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}