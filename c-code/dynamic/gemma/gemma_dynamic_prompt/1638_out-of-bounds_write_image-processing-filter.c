#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int img_width = 1024;
  int img_height = 768;
  unsigned char *img_data = (unsigned char *)malloc(img_width * img_height * 3);

  // Out-of-bounds write vulnerability
  img_data[img_width * img_height * 3] = 0x55;

  free(img_data);
  return 0;
}
