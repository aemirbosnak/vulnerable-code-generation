#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[10];
  char *ptr = buffer;

  scanf("%s", ptr);

  printf("%s", ptr);

  return 0;
}
