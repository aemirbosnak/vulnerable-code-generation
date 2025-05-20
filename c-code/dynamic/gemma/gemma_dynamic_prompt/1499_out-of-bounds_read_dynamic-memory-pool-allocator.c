#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void* allocate(int size)
{
  void* ptr = malloc(size);
  if (ptr == NULL)
  {
    return NULL;
  }

  // Out-of-bounds read vulnerability
  *(int*)ptr = 42;

  return ptr;
}

int main()
{
  allocate(10);
  return 0;
}
