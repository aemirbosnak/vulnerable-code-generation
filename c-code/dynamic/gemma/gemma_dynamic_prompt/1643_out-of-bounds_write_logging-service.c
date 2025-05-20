#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[10];
  int index = 0;

  while (index < 10)
  {
    buffer[index] = 'a';
    index++;
  }

  printf("The content of the buffer is: %s", buffer);

  return 0;
}
