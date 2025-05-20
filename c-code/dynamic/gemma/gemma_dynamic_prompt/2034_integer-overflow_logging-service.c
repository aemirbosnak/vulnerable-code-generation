#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num = 2147483647;
  int result = num * 2;

  printf("The result is: %d\n", result);

  return 0;
}
