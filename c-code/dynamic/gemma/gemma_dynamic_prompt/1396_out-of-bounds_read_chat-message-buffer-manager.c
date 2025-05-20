#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *buffer = malloc(10);
  buffer[10] = 'A'; // Out of bounds write

  printf("%c", buffer[10]); // Out of bounds read

  free(buffer);

  return 0;
}
