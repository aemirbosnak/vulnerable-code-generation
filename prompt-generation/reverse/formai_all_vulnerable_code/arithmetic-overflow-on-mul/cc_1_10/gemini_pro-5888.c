//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int nx, ny, i, j;
  double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679, z, c;
  char *image;

  printf("Enter size of image (nx, ny): ");
  scanf("%d %d", &nx, &ny);

  image = (char *)malloc(3 * nx * ny);
  if (image == NULL)
  {
    printf("Error allocating memory.\n");
    return 1;
  }

  for (i = 0; i < ny; i++)
  {
    for (j = 0; j < nx; j++)
    {
      z = (double)i / (ny - 1) * 2 - 1;
      c = (double)j / (nx - 1) * 2 - 1;
      int r = 255 * (sqrt(z * z + c * c) - 1 + cos(3 * pi * sqrt(z * z + c * c)));
      if (r < 0)
        r = 0;
      if (r > 255)
        r = 255;
      int g = 0;
      int b = 255 * (sqrt(z * z + c * c) - 1 + sin(3 * pi * sqrt(z * z + c * c)));
      if (b < 0)
        b = 0;
      if (b > 255)
        b = 255;
      image[3 * (i * nx + j) + 0] = r;
      image[3 * (i * nx + j) + 1] = g;
      image[3 * (i * nx + j) + 2] = b;
    }
  }

  printf("Saved image to file image.ppm\n");

  FILE *file = fopen("image.ppm", "wb");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  fprintf(file, "P6\n");
  fprintf(file, "%d %d\n", nx, ny);
  fprintf(file, "255\n");
  fwrite(image, 3 * nx * ny, 1, file);
  fclose(file);

  free(image);

  return 0;
}