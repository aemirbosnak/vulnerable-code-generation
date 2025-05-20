#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *buf = malloc(10);
  char *ptr = buf;

  // Read data from the internet, intentionally reading beyond the allocated memory
  ptr = buf + 10;
  *(ptr) = 'A';

  free(buf);

  return 0;
}
