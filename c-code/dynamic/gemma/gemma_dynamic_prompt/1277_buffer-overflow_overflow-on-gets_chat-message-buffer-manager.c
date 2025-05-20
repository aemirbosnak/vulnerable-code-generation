#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[10];
  gets(buffer);

  // Overflow the buffer
  buffer[10] = 'a';

  printf("Message: %s", buffer);

  return 0;
}
