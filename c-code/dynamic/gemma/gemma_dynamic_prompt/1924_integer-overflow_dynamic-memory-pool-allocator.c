#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
  int i = 0;
  int* ptr = NULL;

  for (i = 0; i < 100000; i++)
  {
    ptr = malloc(i);
  }

  free(ptr);

  return 0;
}
