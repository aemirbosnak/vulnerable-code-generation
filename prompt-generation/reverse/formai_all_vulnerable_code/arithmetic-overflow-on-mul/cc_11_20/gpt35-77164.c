//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int width, height, pixel_size;
  FILE* in_file = NULL;
  char* out_file_name = NULL;

  if (argc != 2) {
    printf("Usage: %s <input_image>\n", argv[0]);
    return 1;
  }

  in_file = fopen(argv[1], "rb");
  if (in_file == NULL) {
    printf("Could not open input file: %s\n", argv[1]);
    return 2;
  }

  // read header
  char header[1024];
  fgets(header, 1024, in_file);
  sscanf(header, "P6 %d %d %d", &width, &height, &pixel_size);

  if (fgets(header, 1024, in_file) == NULL) {
    printf("Error reading input file header.\n");
    return 3;
  }

  // allocate memory for pixel array
  unsigned char* pixels = calloc(width * height * pixel_size, sizeof(unsigned char));
  if (pixels == NULL) {
    printf("Error allocating memory.\n");
    return 4;
  }

  // read pixel data
  if (fread(pixels, sizeof(unsigned char), width * height * pixel_size, in_file) != width * height * pixel_size) {
    printf("Error reading input file.\n");
    return 5;
  }

  fclose(in_file);

  // open output file
  out_file_name = malloc(strlen(argv[1]) + 5);
  if (out_file_name == NULL) {
    printf("Error allocating memory.\n");
    return 6;
  }
  strcpy(out_file_name, argv[1]);
  strcat(out_file_name, ".txt");

  FILE* out_file = fopen(out_file_name, "w");
  if (out_file == NULL) {
    printf("Error opening output file.\n");
    return 7;
  }

  // convert pixel array to ASCII art
  char ascii_chars[] = " .:-=+*#%@";
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      unsigned char* pixel = pixels + (h * width + w) * pixel_size;
      unsigned char r = *(pixel++);
      unsigned char g = *(pixel++);
      unsigned char b = *(pixel++);

      float brightness = 0.2126 * r + 0.7152 * g + 0.0722 * b;
      int char_index = (int)(brightness / 28.88888888);
      if (char_index > 9) char_index = 9;
      fputc(ascii_chars[char_index], out_file);
    }
    fputc('\n', out_file);
  }

  fclose(out_file);
  free(pixels);
  free(out_file_name);

  printf("Conversion complete.\n");

  return 0;
}