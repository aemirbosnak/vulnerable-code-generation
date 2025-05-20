#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  char *buffer = NULL;
  buffer = (char *) malloc(10);
  *buffer = 'a';
  free(buffer);
  return 0;
}
