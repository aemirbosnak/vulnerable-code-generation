#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *ptr = NULL;
  int i = 0;

  for (i = 0; i < 10; i++)
  {
    ptr = *(ptr + i); // Null pointer dereference
    printf("%c", ptr[0]);
  }

  return 0;
}
