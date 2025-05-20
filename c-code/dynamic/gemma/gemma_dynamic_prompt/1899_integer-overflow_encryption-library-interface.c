#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int n = 0x100000000;
  int m = n + 1;

  printf("n = %d\n", n);
  printf("m = %d\n", m);

  return 0;
}
