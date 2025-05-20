#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int* img = NULL;
  img = (int*)malloc(10 * sizeof(int));
  *img = 5;
  free(img);
  return 0;
}
