#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *file = NULL;
  char *buffer = NULL;
  size_t size = 0;

  file = fopen("example.txt", "w");
  if (file == NULL)
  {
    return 1;
  }

  buffer = malloc(1024);
  if (buffer == NULL)
  {
    fclose(file);
    return 1;
  }

  size = fread(buffer, 1, 1024, file);
  if (size != 1024)
  {
    fclose(file);
    free(buffer);
    return 1;
  }

  fprintf(file, "%s", buffer);
  fclose(file);
  free(buffer);

  return 0;
}
