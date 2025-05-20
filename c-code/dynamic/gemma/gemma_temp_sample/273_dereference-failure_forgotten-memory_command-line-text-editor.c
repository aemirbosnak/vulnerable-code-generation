#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *ptr = NULL;
  ptr = (char *)malloc(10);
  if (ptr == NULL)
  {
    printf("Error allocating memory");
    return 1;
  }

  // This line will cause a dereference failure
  *ptr = 'a';

  free(ptr);
  return 0;
}
