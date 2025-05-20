#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[10] = "Hello, world!";
  int index = 12;

  printf("%s", buffer[index]);
  return 0;
}
