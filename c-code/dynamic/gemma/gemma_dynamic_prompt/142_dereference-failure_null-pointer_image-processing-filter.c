#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *img_data = NULL;
  int pixel_value = 0;

  // Allocate memory for image data
  img_data = malloc(1024);

  // Access pixel value from image data (null pointer)
  pixel_value = img_data[1024];

  // Print pixel value
  printf("Pixel value: %d\n", pixel_value);

  return 0;
}
