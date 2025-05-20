//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define SIZE 512
#define P 1.61803398875

int main() {
  FILE *input, *output;
  char filename[100];
  int i, j, k, l, m, n, x, y, z, w, count = 0;
  double a, b, c, d, e, f, g, h, sum;
  double watermark[SIZE];
  double image[SIZE];

  printf("Enter the name of the image file: ");
  scanf("%s", filename);

  input = fopen(filename, "rb");
  if (input == NULL) {
    printf("Error opening file.\n");
    exit(0);
  }

  fread(image, sizeof(double), SIZE, input);
  fclose(input);

  printf("Enter the message to embed as a watermark (maximum %d characters): ", SIZE);
  scanf("%s", watermark);

  for (i = 0; i < SIZE; i++) {
    sum = 0;
    for (j = 0; j < SIZE; j++) {
      sum += image[j] * cos(2 * M_PI * i * j / SIZE);
    }
    image[i] += P * watermark[i] * sum;
  }

  output = fopen("watermarked.bmp", "wb");
  if (output == NULL) {
    printf("Error creating output file.\n");
    exit(0);
  }

  for (i = 0; i < SIZE; i++) {
    if (image[i] > 255) {
      image[i] = 255;
    } else if (image[i] < 0) {
      image[i] = 0;
    }
    fwrite(&image[i], sizeof(double), 1, output);
  }

  fclose(output);

  printf("Watermark embedded successfully.\n");

  return 0;
}