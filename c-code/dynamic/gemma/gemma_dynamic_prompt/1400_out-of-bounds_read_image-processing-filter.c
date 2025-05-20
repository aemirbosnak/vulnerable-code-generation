#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int image_data[1024] = {0};
  int index = 1024;

  image_data[index] = 255;

  printf("%d", image_data[index]);

  return 0;
}
