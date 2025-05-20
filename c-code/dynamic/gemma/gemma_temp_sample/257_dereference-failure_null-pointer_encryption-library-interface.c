#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *ptr = NULL;
  *ptr = 0xdeadbeef;

  printf("The value of the pointer is: %p\n", ptr);

  return 0;
}
