#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *ptr = NULL;
  *ptr = 10;

  printf("The value of the pointer is: %d", *ptr);

  return 0;
}
