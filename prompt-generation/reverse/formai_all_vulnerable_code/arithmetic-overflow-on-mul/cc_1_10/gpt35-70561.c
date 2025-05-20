//FormAI DATASET v1.0 Category: Image Editor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Error: please provide input and output file names!\n");
    return 1;
  }

  FILE *in_file = fopen(argv[1], "rb");
  if (!in_file) {
    printf("Error: could not open input file!\n");
    return 1;
  }

  FILE *out_file = fopen(argv[2], "wb");
  if (!out_file) {
    printf("Error: could not open output file!\n");
    fclose(in_file);
    return 1;
  }

  int width, height;
  fread(&width, sizeof(int), 1, in_file);
  fread(&height, sizeof(int), 1, in_file);

  printf("Image width: %d, height: %d\n", width, height);

  int size = width * height;
  unsigned char *image_data = malloc(size);
  if (!image_data) {
    printf("Error: could not allocate image data!\n");
    fclose(in_file);
    fclose(out_file);
    return 1;
  }

  fread(image_data, sizeof(unsigned char), size, in_file);

  for (int i = 0; i < size; i++) {
    // Invert colors
    image_data[i] = 255 - image_data[i];
  }

  fwrite(&width, sizeof(int), 1, out_file);
  fwrite(&height, sizeof(int), 1, out_file);
  fwrite(image_data, sizeof(unsigned char), size, out_file);

  printf("Image edited successfully!\n");

  free(image_data);
  fclose(in_file);
  fclose(out_file);

  return 0;
}