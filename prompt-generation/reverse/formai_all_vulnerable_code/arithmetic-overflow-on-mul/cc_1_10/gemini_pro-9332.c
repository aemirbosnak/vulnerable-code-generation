//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 256

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
    return 1;
  }

  // Read the image file into memory
  FILE *fp = fopen(argv[1], "rb");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  unsigned char *data = malloc(file_size);
  if (data == NULL) {
    perror("malloc");
    fclose(fp);
    return 1;
  }

  fread(data, 1, file_size, fp);
  fclose(fp);

  // Check if the file is a valid BMP image
  if (data[0] != 'B' || data[1] != 'M') {
    fprintf(stderr, "Error: Invalid BMP image file\n");
    free(data);
    return 1;
  }

  // Get the image width and height
  int width = *(int *)&data[18];
  int height = *(int *)&data[22];

  // Convert the image data to grayscale
  unsigned char *grayscale_data = malloc(width * height);
  if (grayscale_data == NULL) {
    perror("malloc");
    free(data);
    return 1;
  }

  for (int i = 0; i < width * height; i++) {
    grayscale_data[i] = (data[i * 3] + data[i * 3 + 1] + data[i * 3 + 2]) / 3;
  }

  // Convert the grayscale image data to ASCII art
  char *ascii_art = malloc(width * height + 1);
  if (ascii_art == NULL) {
    perror("malloc");
    free(data);
    free(grayscale_data);
    return 1;
  }

  for (int i = 0; i < width * height; i++) {
    ascii_art[i] = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ@[]^~";
    ascii_art[i] = ascii_art[grayscale_data[i] * (strlen(ascii_art) - 1) / 255];
  }

  ascii_art[width * height] = '\0';

  // Print the ASCII art to the console
  printf("%s\n", ascii_art);

  // Free the allocated memory
  free(data);
  free(grayscale_data);
  free(ascii_art);

  return 0;
}