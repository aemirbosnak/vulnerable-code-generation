#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *img_data = NULL;
  int img_size = 1024 * 512;

  img_data = (int *)malloc(img_size * sizeof(int));

  // Malformed pointer dereference
  *(img_data + 10000) = 255;

  free(img_data);

  return 0;
}
