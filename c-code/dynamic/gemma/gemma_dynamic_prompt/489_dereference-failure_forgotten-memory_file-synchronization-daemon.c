#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char **ptr = NULL;
  *ptr = malloc(10);

  // This line intentionally dereferences a null pointer
  printf("%c", **ptr);

  free(ptr);
  return 0;
}
