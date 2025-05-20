#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp, *fp_out;
  char filename[256], filename_out[256];
  int width, height, max_value, brightness, contrast, flip;
  fscanf(stdin, "%s", filename);
  fscanf(stdin, "%s", filename_out);
  fscanf(stdin, "%d %d %d", &width, &height, &max_value);
  fscanf(stdin, "%d", &brightness);
  fscanf(stdin, "%d", &contrast);
  fscanf(stdin, "%d", &flip);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  fp_out = fopen(filename_out, "w");
  if (fp_out == NULL) {
    perror("Error opening file");
    fclose(fp);
    return 1;
  }

  // Calculate modified pixel values
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int r, g, b, pixel_value;
      fscanf(fp, "%d ", &pixel_value);
      r = pixel_value;
      g = pixel_value;
      b = pixel_value;

      pixel_value = (r * brightness / max_value) + (g * brightness / max_value) + (b * brightness / max_value) + contrast * pixel_value;
      pixel_value = pixel_value > max_value ? max_value : pixel_value;
      pixel_value = pixel_value < 0 ? 0 : pixel_value;

      fprintf(fp_out, "%d ", pixel_value);
    }
    fprintf(fp_out, "\n");
  }

  fclose(fp);
  fclose(fp_out);

  return 0;
}
