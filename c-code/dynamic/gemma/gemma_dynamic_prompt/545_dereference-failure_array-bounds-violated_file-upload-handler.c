#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *arr = malloc(10);
  arr[10] = 'A';

  free(arr);
  return 0;
}
