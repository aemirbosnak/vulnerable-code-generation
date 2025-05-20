#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *image_data = NULL;
  int image_size = 1024 * 1024;

  image_data = malloc(image_size);
  if (image_data == NULL)
  {
    return 1;
  }

  // Accessing a memory location beyond the allocated space
  image_data[image_size - 1] = 255;

  free(image_data);

  return 0;
}
