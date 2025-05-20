#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  int a = 2147483647;
  int b = 2147483648;
  int c = a + b;
  int d = c * 2;
  printf("%d", d);
  return 0;
}
