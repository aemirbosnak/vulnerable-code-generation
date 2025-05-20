#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  char* data = NULL;
  int index = 0;

  // Allocate memory for data
  data = malloc(10);

  // Access element at index 5, which is beyond the allocated memory
  data[index] = 'a';

  // Free the memory
  free(data);

  return 0;
}
