#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char buffer[10] = "Hello, world!";

int main()
{
  gets(buffer);
  return 0;
}
