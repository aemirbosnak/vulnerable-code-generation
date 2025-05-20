#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **arr = NULL;
  int i = 0;

  // Allocate memory for the array
  arr = malloc(10 * sizeof(char *));

  // Loop through the array and dereference the elements
  for (i = 0; i < 10; i++) {
    arr[i] = malloc(20 * sizeof(char));
    arr[i][0] = 'A';
  }

  // Free the memory
  for (i = 0; i < 10; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}
