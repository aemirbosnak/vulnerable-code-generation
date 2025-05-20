#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int *image = NULL;
  image = (int *)malloc(1024);
  free(image);
  return 0;
}
