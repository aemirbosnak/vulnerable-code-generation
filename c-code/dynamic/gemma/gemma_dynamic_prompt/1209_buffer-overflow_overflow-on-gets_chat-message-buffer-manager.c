#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char buffer[1024];

int main()
{
  gets(buffer);
  strcpy(buffer, "This message is too long and will cause a buffer overflow!");
  puts(buffer);
  return 0;
}
