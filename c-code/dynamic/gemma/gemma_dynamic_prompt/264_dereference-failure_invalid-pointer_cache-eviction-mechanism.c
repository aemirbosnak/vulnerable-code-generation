#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *ptr = NULL;
  ptr = (int *)malloc(10 * sizeof(int));
  *ptr = 5;
  free(ptr);
  printf("%d", *ptr);
  return 0;
}
