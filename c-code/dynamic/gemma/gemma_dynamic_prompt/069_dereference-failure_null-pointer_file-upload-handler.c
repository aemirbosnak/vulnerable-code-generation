#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *filename = NULL;
  FILE *file = NULL;

  filename = "foo.txt";
  file = fopen(filename, "w");

  if (file == NULL)
  {
    perror("Error opening file");
    exit(1);
  }

  fprintf(file, "Hello, world!");
  fclose(file);

  return 0;
}
