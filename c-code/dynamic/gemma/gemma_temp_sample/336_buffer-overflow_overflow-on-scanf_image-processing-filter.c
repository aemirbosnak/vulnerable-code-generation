#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char buf[10];
  scanf("%s", buf);
  buf[10] = 'A';
  printf("%s", buf);
  return 0;
}
