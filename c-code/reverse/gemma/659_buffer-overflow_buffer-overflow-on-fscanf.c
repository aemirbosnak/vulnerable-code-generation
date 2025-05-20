#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int width, height, pixel;
  FILE *fp;
  unsigned char image[1024];

  fp = fopen("image.pgm", "r");
  fscanf(fp, "%d %d", &width, &height);
  fscanf(fp, "%d", &pixel);

  fclose(fp);

  // Adjust brightness and contrast
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      image[y * width * 3 + x * 3] += 50;
      image[y * width * 3 + x * 3 + 1] += 50;
      image[y * width * 3 + x * 3 + 2] += 50;
    }
  }

  // Flip the image
  int i = 0;
  for (int y = height - 1; y >= 0; y--) {
    for (int x = 0; x < width; x++) {
      image[i] = image[y * width * 3 + x * 3];
      image[i + 1] = image[y * width * 3 + x * 3 + 1];
      image[i + 2] = image[y * width * 3 + x * 3 + 2];
      i++;
    }
  }

  // Save the processed image
  fp = fopen("processed_image.pgm", "w");
  fprintf(fp, "%d %d\n", width, height);
  fprintf(fp, "%d\n", pixel);

  fwrite(image, 1, width * height * 3, fp);

  fclose(fp);

  return 0;
}
