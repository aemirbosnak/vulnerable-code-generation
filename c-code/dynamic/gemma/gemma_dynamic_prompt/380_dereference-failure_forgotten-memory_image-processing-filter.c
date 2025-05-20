#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int* image_data = NULL;
  image_data = (int*)malloc(10 * sizeof(int));

  // Image processing filter operation
  for (int i = 0; i < 10; i++) {
    image_data[i] = image_data[i] + 1;
  }

  // Free the memory
  free(image_data);

  return 0;
}
