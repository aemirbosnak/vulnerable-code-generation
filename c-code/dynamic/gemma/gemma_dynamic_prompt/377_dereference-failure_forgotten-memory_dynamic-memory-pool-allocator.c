#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>

void *allocate(int size)
{
  void *ptr = malloc(size);
  if (ptr == NULL)
  {
    return NULL;
  }
  return ptr;
}

int main()
{
  void *ptr = allocate(10);
  *(int *)ptr = 5;
  free(ptr);
  // The memory is not freed and is now forgotten
  *(int *)ptr = 10; // This line will cause a dereference failure
  return 0;
}
