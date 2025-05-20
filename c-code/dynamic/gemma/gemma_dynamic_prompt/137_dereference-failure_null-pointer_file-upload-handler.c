#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char* filename = NULL;
  FILE* file = fopen(filename, "w");

  if (file)
  {
    fprintf(file, "Hello, world!");
    fclose(file);
  }

  return 0;
}
