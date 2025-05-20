#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *url = "hello";
  char **ptr = NULL;

  ptr = (char **)malloc(10);
  *ptr = url;

  printf("%s", *ptr);

  free(ptr);

  return 0;
}
