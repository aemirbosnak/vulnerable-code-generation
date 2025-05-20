#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_image(char *image_path) {
  FILE *fp = fopen(image_path, "r");
  fscanf(fp, "%s", image_path);
  fclose(fp);
}

int main() {
  process_image("/path/to/image.pgm");
  return 0;
}
