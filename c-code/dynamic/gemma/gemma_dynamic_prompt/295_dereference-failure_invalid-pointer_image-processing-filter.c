#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *img_ptr = NULL;
  img_ptr = (int *)malloc(10 * sizeof(int));
  img_ptr[0] = 10;
  img_ptr[1] = 20;
  img_ptr[2] = 30;
  free(img_ptr);
  return 0;
}
