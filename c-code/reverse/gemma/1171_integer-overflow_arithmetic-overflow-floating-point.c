#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int img_data[1024];
  int i, brightness, contrast, max_value = 255;

  // Read image data
  FILE* img_file = fopen("image.pgm", "r");
  fscanf(img_file, "%d", img_data);
  fclose(img_file);

  // Get brightness and contrast values from user
  printf("Enter brightness (0-255): ");
  scanf("%d", &brightness);

  printf("Enter contrast (0-255): ");
  scanf("%d", &contrast);

  // Adjust brightness and contrast
  for (i = 0; i < 1024; i++) {
    int pixel_value = img_data[i];
    pixel_value = (int)round((pixel_value * contrast) / max_value + brightness);

    if (pixel_value < 0) pixel_value = 0;
    if (pixel_value > max_value) pixel_value = max_value;

    img_data[i] = pixel_value;
  }

  // Write adjusted image data to file
  img_file = fopen("adjusted_image.pgm", "w");
  fprintf(img_file, "%d", img_data);
  fclose(img_file);

  printf("Image adjusted!\n");

  return 0;
}
