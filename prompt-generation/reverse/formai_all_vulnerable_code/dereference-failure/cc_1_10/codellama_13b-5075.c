//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: cheerful
/*
 * Unique C Memory Management Example Program in a Cheerful Style
 *
 * This program demonstrates how to manage memory in C using the
 * `malloc`, `realloc`, and `free` functions.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *str;
  int *arr;
  int i, n = 10;

  // Allocate memory for a string
  str = malloc(10 * sizeof(char));
  if (str == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  strcpy(str, "Hello, World!");
  printf("String: %s\n", str);

  // Allocate memory for an array of integers
  arr = malloc(n * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  for (i = 0; i < n; i++) {
    arr[i] = i * i;
  }
  printf("Array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Reallocate memory for the array to double its size
  arr = realloc(arr, 2 * n * sizeof(int));
  if (arr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  for (i = n; i < 2 * n; i++) {
    arr[i] = i * i;
  }
  printf("Doubled Array: ");
  for (i = 0; i < 2 * n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Free memory for the array
  free(arr);

  // Free memory for the string
  free(str);

  return 0;
}