//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Get the image dimensions
  int width, height;
  printf("Enter the image width: ");
  scanf("%d", &width);
  printf("Enter the image height: ");
  scanf("%d", &height);

  // Allocate memory for the image
  unsigned char *image = malloc(width * height * sizeof(unsigned char));

  // Read the image data from the user
  printf("Enter the image data (0-255): ");
  for (int i = 0; i < width * height; i++) {
    scanf("%d", &image[i]);
  }

  // Flip the image vertically
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height / 2; j++) {
      unsigned char temp = image[i * height + j];
      image[i * height + j] = image[i * height + height - j - 1];
      image[i * height + height - j - 1] = temp;
    }
  }

  // Change the image brightness and contrast
  float brightness, contrast;
  printf("Enter the brightness (-128 to 127): ");
  scanf("%f", &brightness);
  printf("Enter the contrast (0 to 2): ");
  scanf("%f", &contrast);

  for (int i = 0; i < width * height; i++) {
    image[i] = (unsigned char) (128 + (image[i] - 128) * contrast + brightness);
  }

  // Write the image data to a file
  FILE *fp = fopen("output.bmp", "wb");
  fprintf(fp, "BM");
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 54);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 40);
  fprintf(fp, "%c%c%c%c", 0, 0, (width >> 8) & 0xFF, width & 0xFF);
  fprintf(fp, "%c%c%c%c", 0, 0, (height >> 8) & 0xFF, height & 0xFF);
  fprintf(fp, "%c%c%c%c", 0, 0, 1, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 8, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  fprintf(fp, "%c%c%c%c", 0, 0, 0, 0);
  for (int i = 0; i < width * height; i++) {
    fprintf(fp, "%c", image[i]);
  }
  fclose(fp);

  // Free the memory allocated for the image
  free(image);

  return 0;
}