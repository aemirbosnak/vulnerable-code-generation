//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two strings
int compare(const void *a, const void *b) {
  return strcmp(*(const char* const*)a, *(const char* const*)b);
}

// Function to sort the array of strings
void sort_strings(char **arr, int n) {
  qsort(arr, n, sizeof(char *), compare);
}

// Function to find the longest common prefix
char *longest_common_prefix(char **arr, int n) {
  if (n == 0) {
    return NULL;
  }

  // Find the minimum length of all the strings
  int min_len = strlen(arr[0]);
  for (int i = 1; i < n; i++) {
    if (strlen(arr[i]) < min_len) {
      min_len = strlen(arr[i]);
    }
  }

  // Create a buffer to store the longest common prefix
  char *prefix = malloc(min_len + 1);
  memset(prefix, 0, min_len + 1);

  // Iterate over the minimum length of the strings
  for (int i = 0; i < min_len; i++) {
    // Check if all the strings have the same character at the current index
    char c = arr[0][i];
    for (int j = 1; j < n; j++) {
      if (arr[j][i] != c) {
        return prefix;
      }
    }

    // If all the strings have the same character at the current index, append it to the prefix
    prefix[i] = c;
  }

  return prefix;
}

int main() {
  // Get the number of strings
  int n;
  printf("Enter the number of strings: ");
  scanf("%d", &n);

  // Allocate memory for the array of strings
  char **arr = malloc(n * sizeof(char *));

  // Get the strings from the user
  for (int i = 0; i < n; i++) {
    char *str = malloc(101);
    printf("Enter string %d: ", i + 1);
    scanf("%s", str);
    arr[i] = str;
  }

  // Sort the array of strings
  sort_strings(arr, n);

  // Find the longest common prefix
  char *prefix = longest_common_prefix(arr, n);

  // Print the longest common prefix
  if (prefix == NULL) {
    printf("There is no common prefix.\n");
  } else {
    printf("The longest common prefix is: %s\n", prefix);
  }

  // Free the allocated memory
  for (int i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);
  free(prefix);

  return 0;
}