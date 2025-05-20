#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *file_data = NULL;
  FILE *file_ptr = NULL;

  // Allocate memory for file data
  file_data = malloc(1024);

  // Open a file
  file_ptr = fopen("test.txt", "r");

  // Read file data into memory
  fread(file_data, 1024, 1, file_ptr);

  // Dereference a null pointer
  (*(file_data + 10)) = 42;

  // Close the file
  fclose(file_ptr);

  // Free the memory
  free(file_data);

  return 0;
}
