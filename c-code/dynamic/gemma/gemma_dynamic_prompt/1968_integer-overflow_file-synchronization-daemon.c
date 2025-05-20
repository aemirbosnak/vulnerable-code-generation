#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a = 1;
  int b = 2;
  int c = a + b;
  int d = c * c;
  int e = d / d;
  printf("The result is: %d", e);
  return 0;
}
