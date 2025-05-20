#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE *fp;
  char *buffer = NULL;
  long size = 0;

  // Open file
  fp = fopen("test.txt", "w");

  // Allocate memory for buffer
  buffer = malloc(10000);

  // Read data from client
  size = read(0, buffer, 10000);

  // Write data to file
  fwrite(buffer, size, 1, fp);

  // Close file
  fclose(fp);

  // Free memory
  free(buffer);

  return 0;
}
