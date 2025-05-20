#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 0;
  char **entries = NULL;

  // Allocate memory for the entries array
  entries = (char**)malloc(n * sizeof(char*));

  // Loop until the user enters a negative number
  printf("Enter the number of diary entries you want to store: ");
  scanf("%d", &n);

  // Allocate memory for each entry
  for (int i = 0; i < n; i++) {
    entries[i] = (char*)malloc(100 * sizeof(char));
  }

  // Get the user's entries
  for (int i = 0; i < n; i++) {
    printf("Enter your diary entry: ");
    scanf("%s", entries[i]);
  }

  // Display the user's entries
  for (int i = 0; i < n; i++) {
    printf("Your diary entry: %s\n", entries[i]);
  }

  // Free the memory allocated for the entries array
  for (int i = 0; i < n; i++) {
    free(entries[i]);
  }

  // Free the memory allocated for the entries array
  free(entries);

  return 0;
}
