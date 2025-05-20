#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[1024];
  fscanf(stdin, "%s", buffer);

  printf("Log entry: %s\n", buffer);

  return 0;
}
