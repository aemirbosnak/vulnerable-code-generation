#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp, *fp_out;
  unsigned char *img_data, *img_data_out;
  int img_width, img_height, img_size, i, j;
  fscanf(fp, "%d %d", &img_width, &img_height);
  img_size = img_width * img_height;
  img_data = malloc(img_size);
  fscanf(fp, "%c", img_data);
  fp_out = fopen("out.pgm", "w");
  fprintf(fp_out, "PGM %d %d\n", img_width, img_height);
  fprintf(fp_out, "%c", img_data);
  fclose(fp_out);
  free(img_data);
  return 0;
}
