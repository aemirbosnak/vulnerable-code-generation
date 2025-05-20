#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char *buffer = NULL;
  int size = 1024;
  buffer = (char *)malloc(size);

  // Out-of-bounds write
  buffer[size - 1] = 'a';

  free(buffer);

  return 0;
}
