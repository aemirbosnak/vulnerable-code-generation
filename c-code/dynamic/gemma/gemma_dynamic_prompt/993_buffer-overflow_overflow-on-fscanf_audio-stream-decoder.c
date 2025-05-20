#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char buffer[10];
  scanf("%s", buffer);

  overflow_func(buffer);

  return 0;
}

void overflow_func(char *buffer)
{
  int i = 0;
  while (buffer[i] != '\0')
  {
    i++;
  }

  buffer[i] = 'A';
  buffer[i+1] = 'A';
  buffer[i+2] = 'A';
}
