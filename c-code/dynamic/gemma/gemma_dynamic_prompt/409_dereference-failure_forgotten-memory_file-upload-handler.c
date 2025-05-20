#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *filename = NULL;
  FILE *file = NULL;

  // Get the filename from the user
  printf("Enter the filename: ");
  scanf("%s", filename);

  // Open the file
  file = fopen(filename, "r");

  // Check if the file is open
  if (file == NULL)
  {
    printf("Error opening file: %s", filename);
    exit(1);
  }

  // Read the file contents
  char *buffer = NULL;
  size_t size = 0;
  while ((size_t)fread(buffer, 1, size, file) > 0)
  {
    // Allocate memory for the buffer
    buffer = realloc(buffer, size + 1);

    // Increment the size of the buffer
    size++;

    // Read more data from the file
  }

  // Close the file
  fclose(file);

  // Free the memory allocated for the buffer
  free(buffer);

  return 0;
}
