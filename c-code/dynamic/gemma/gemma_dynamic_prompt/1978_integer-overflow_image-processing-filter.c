#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  int pixel = 256 * 256 * 256 + 1;
  pixel = pixel / 2;
  printf("%d", pixel);
  return 0;
}
