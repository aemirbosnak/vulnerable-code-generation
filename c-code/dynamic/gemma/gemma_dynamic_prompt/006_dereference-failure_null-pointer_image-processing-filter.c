#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *img_data = NULL;
  img_data = (int *)malloc(10 * sizeof(int));

  // The following line contains a dereference failure (null pointer) vulnerability
  img_data[5] = 255;

  free(img_data);

  return 0;
}
