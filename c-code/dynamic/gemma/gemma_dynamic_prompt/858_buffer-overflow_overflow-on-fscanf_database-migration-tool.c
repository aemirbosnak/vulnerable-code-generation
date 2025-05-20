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

  // Exploit buffer overflow
  int i = 0;
  while (buffer[i] != '\0')
  {
    buffer[i] = 'a';
    i++;
  }

  buffer[i] = '\0';

  printf("Modified buffer: %s", buffer);

  return 0;
}
