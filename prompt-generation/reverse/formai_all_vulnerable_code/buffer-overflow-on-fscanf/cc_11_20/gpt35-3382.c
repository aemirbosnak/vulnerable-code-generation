//FormAI DATASET v1.0 Category: Image Editor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  // Check command line arguments
  if(argc < 3) {
    printf("Usage: %s <input-file> <output-file>\n", argv[0]);
    return 1;
  }

  // Open input file
  FILE *in_file = fopen(argv[1], "rb");
  if(in_file == NULL) {
    printf("Unable to open input file '%s'\n", argv[1]);
    return 1;
  }

  // Open output file
  FILE *out_file = fopen(argv[2], "wb");
  if(out_file == NULL) {
    printf("Unable to open output file '%s'\n", argv[2]);
    fclose(in_file);
    return 1;
  }

  // Read the input image header
  int width, height, max_val;
  char format[3];
  fscanf(in_file, "%s\n%d %d\n%d\n", format, &width, &height, &max_val);
  if(strcmp(format, "P6") != 0 || max_val != 255) {
    printf("Unsupported file format or color depth\n");
    fclose(in_file);
    fclose(out_file);
    return 1;
  }

  // Allocate memory for the pixel data
  unsigned char *pixels = (unsigned char *) malloc(sizeof(unsigned char) * width * height * 3);
  if(pixels == NULL) {
    printf("Unable to allocate memory for pixel data\n");
    fclose(in_file);
    fclose(out_file);
    return 1;
  }

  // Read the pixel data from the input file
  fread(pixels, sizeof(unsigned char), width * height * 3, in_file);

  // Loop through the pixel data and make changes
  for(int i = 0; i < width * height * 3; i += 3) {
    // Example: Make all red pixels green
    if(pixels[i] == 255 && pixels[i + 1] == 0 && pixels[i + 2] == 0) {
      pixels[i] = 0;
      pixels[i + 1] = 255;
    }
  }

  // Write the output image header
  fprintf(out_file, "P6\n%d %d\n%d\n", width, height, max_val);

  // Write the pixel data to the output file
  fwrite(pixels, sizeof(unsigned char), width * height * 3, out_file);

  // Free memory and close files
  free(pixels);
  fclose(in_file);
  fclose(out_file);

  return 0;
}