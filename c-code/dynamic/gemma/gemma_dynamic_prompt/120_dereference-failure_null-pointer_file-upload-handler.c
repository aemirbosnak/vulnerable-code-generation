#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE *fp = NULL;
  char *buffer = NULL;
  long size = 0;

  // Open file for reading
  fp = fopen("/path/to/file", "r");
  if (fp == NULL)
  {
    return 1;
  }

  // Allocate memory for buffer
  buffer = malloc(size);
  if (buffer == NULL)
  {
    fclose(fp);
    return 1;
  }

  // Read file data into buffer
  size = fread(buffer, 1, size, fp);
  if (size == 0)
  {
    fclose(fp);
    free(buffer);
    return 1;
  }

  // Close file
  fclose(fp);

  // Free memory
  free(buffer);

  return 0;
}
