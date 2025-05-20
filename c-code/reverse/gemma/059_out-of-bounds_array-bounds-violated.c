#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int w, h, i, j, pixel, ascii_value;
  FILE *fp;
  unsigned char *image_data;

  fp = fopen("image.bmp", "rb");
  fscanf(fp, "%d %d", &w, &h);
  image_data = (unsigned char *)malloc(w * h * 3);
  fread(image_data, w * h * 3, 1, fp);

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      pixel = image_data[i * w * 3 + j * 3];
      ascii_value = pixel / 256 * 94 + pixel % 256 * 58;
      printf("%c", ascii_value);
    }
    printf("\n");
  }

  fclose(fp);
  free(image_data);
  return 0;
}
