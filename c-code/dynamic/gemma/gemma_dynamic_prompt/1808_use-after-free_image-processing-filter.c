#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *image_data = malloc(1024);
  free(image_data);

  // Use the freed memory
  image_data[0] = 'H';
  printf("%c", image_data[0]);

  return 0;
}
