#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *url = NULL;
  url = malloc(10);
  *url = 'a';
  free(url);

  return 0;
}
