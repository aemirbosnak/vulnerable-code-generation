#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  unsigned int a = 4294967294;
  a = a + 1;
  printf("%d", a);
}
