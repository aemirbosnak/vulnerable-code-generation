#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int *img_data = NULL;
  img_data = (int *)malloc(1024);
  img_data[1024] = 255; // This line will cause a dereference failure
  free(img_data);
  return 0;
}
