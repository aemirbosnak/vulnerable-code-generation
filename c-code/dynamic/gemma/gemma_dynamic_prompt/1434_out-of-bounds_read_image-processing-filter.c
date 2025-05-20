#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  unsigned char *img_data = NULL;
  img_data = (unsigned char *)malloc(1024);
  memset(img_data, 0, 1024);

  img_data[1023] = 255; // Out of bounds write

  free(img_data);
  return 0;
}
