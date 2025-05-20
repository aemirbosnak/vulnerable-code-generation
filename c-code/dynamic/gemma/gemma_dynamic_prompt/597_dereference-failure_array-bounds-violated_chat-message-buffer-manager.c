#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

char buffer[10];

int main()
{
  int index = 11;
  buffer[index] = 'a';
  return 0;
}
