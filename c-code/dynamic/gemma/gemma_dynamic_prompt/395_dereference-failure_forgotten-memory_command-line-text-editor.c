#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char **ptr = NULL;
  ptr = (char **)malloc(10 * sizeof(char *));
  if (ptr == NULL)
  {
    return 1;
  }

  for (int i = 0; i < 10; i++)
  {
    ptr[i] = malloc(10 * sizeof(char));
  }

  free(ptr);
  return 0;
}
