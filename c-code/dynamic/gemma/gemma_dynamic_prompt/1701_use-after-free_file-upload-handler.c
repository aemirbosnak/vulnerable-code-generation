#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *file_data = NULL;
  FILE *file_ptr = NULL;

  // Allocate memory for file data
  file_data = malloc(1024);

  // Open file for reading
  file_ptr = fopen("example.txt", "r");

  // Read file data
  fread(file_data, 1024, 1, file_ptr);

  // Free memory allocated for file data
  free(file_data);

  // Use freed memory
  printf("%s", file_data);

  return 0;
}
