#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  void **ptr = NULL;
  *ptr = 10;
  printf("%d", *ptr);
  return 0;
}
