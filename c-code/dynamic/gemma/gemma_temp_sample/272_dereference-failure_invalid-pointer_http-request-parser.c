#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *url = NULL;
  url = malloc(1024);

  // Malformed pointer dereference
  *(url + 10) = 'H';

  free(url);
  return 0;
}
