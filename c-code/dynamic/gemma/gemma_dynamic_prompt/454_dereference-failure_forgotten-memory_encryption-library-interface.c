#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

int main()
{
  char *key = malloc(16);
  key = NULL;

  // Vulnerable code - dereference failure
  *(key + 8) = 0x33;

  free(key);
  return 0;
}
