//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Function to compare two strings
int compare_strings(const void *a, const void *b) {
  const char *str1 = *(const char **)a;
  const char *str2 = *(const char **)b;

  return strcmp(str1, str2);
}

// Function to print an array of strings
void print_strings(const char **arr, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("%s\n", arr[i]);
  }
}

int main() {
  // Get the number of strings to sort
  printf("Enter the number of strings to sort: ");
  size_t num_strings;
  scanf("%zu", &num_strings);

  // Allocate memory for the array of strings
  char **strings = malloc(sizeof(char *) * num_strings);
  if (strings == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  // Get the strings from the user
  for (size_t i = 0; i < num_strings; i++) {
    printf("Enter string %zu: ", i + 1);
    char *str = malloc(MAX_STR_LEN + 1);
    if (str == NULL) {
      perror("malloc");
      return EXIT_FAILURE;
    }
    scanf("%s", str);

    strings[i] = str;
  }

  // Sort the array of strings
  qsort(strings, num_strings, sizeof(char *), compare_strings);

  // Print the sorted array of strings
  printf("Sorted strings:\n");
  print_strings(strings, num_strings);

  // Free the allocated memory
  for (size_t i = 0; i < num_strings; i++) {
    free(strings[i]);
  }
  free(strings);

  return EXIT_SUCCESS;
}