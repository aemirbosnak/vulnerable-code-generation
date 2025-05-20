#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *img_data = NULL;
  img_data = (int *)malloc(1024);

  // This line will cause a dereference failure
  img_data[1024] = 255;

  free(img_data);
  return 0;
}
