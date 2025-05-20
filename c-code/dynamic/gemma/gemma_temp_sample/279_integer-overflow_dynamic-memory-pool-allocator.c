#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

int main()
{
  int *pool = NULL;
  int size = 0;

  for (;;)
  {
    int n = rand() % 10 + 1;
    pool = realloc(pool, size + n);
    size += n;
  }

  return 0;
}
