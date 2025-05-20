//FormAI DATASET v1.0 Category: Image compression ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int width, height, max_color;
  char format[3];

  // Read the header information
  if(scanf("%2s\n%d %d\n%d\n", format, &width, &height, &max_color) != 4 ||
    strcmp(format, "P3") != 0 || max_color != 255) {
    printf("Invalid image format or color range\n");
    return 1;
  }

  // Allocate memory for image data
  int size = width * height * 3;
  unsigned char* data = malloc(size);
  if(data == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }

  // Read the pixel data
  for(int i = 0; i < size; i++) {
    int value;
    if(scanf("%d", &value) != 1 || value < 0 || value > 255) {
      printf("Invalid pixel data\n");
      free(data);
      return 1;
    }
    data[i] = (unsigned char)value;
  }

  // Compress the image by removing every other pixel
  int compressed_size = size / 2;
  unsigned char* compressed_data = malloc(compressed_size);
  if(compressed_data == NULL) {
    printf("Error allocating memory\n");
    free(data);
    return 1;
  }
  for(int i = 0; i < compressed_size; i++) {
    compressed_data[i] = data[i*2];
  }

  // Write the compressed image to a file
  FILE* outfile = fopen("compressed_image.ppm", "w");
  if(outfile == NULL) {
    printf("Error opening output file\n");
    free(data);
    free(compressed_data);
    return 1;
  }
  fprintf(outfile, "P3\n%d %d\n%d\n", width/2, height, max_color);
  for(int i = 0; i < compressed_size; i++) {
    fprintf(outfile, "%d %d %d ", compressed_data[i], compressed_data[i], compressed_data[i]);
  }
  fclose(outfile);

  // Clean up
  free(data);
  free(compressed_data);
  return 0;
}