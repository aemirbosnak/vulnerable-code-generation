#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a = 2147483647;
  int b = 2;

  int c = a * b;

  printf("The product of a and b is: %d", c);

  return 0;
}
