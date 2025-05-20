#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *ptr = NULL;
  ptr = (char *)malloc(10);
  *ptr = 'a';
  printf("%c", *ptr);
  free(ptr);
  return 0;
}
