#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **arr = NULL;
  int size = 0;

  // Allocate memory for the pool
  arr = (char **)malloc(10 * sizeof(char *));

  // Get the size of the pool
  size = 10;

  // Overflow the pool
  arr[size - 1] = (char *)malloc(size * sizeof(char));

  // Print the contents of the pool
  for (int i = 0; i < size; i++) {
    printf("%p\n", arr[i]);
  }

  return 0;
}
