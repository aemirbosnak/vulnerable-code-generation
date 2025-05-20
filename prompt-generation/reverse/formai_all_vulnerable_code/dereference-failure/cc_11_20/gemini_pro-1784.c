//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
  // Load the image from a file
  FILE *fp = fopen("input.jpg", "rb");
  if (fp == NULL) {
    printf("Error opening the input image file.\n");
    return 1;
  }
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  rewind(fp);
  unsigned char *data = malloc(size);
  fread(data, 1, size, fp);
  fclose(fp);

  // Convert the image to grayscale
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      int index = i * WIDTH + j;
      int r = data[index * 3 + 0];
      int g = data[index * 3 + 1];
      int b = data[index * 3 + 2];
      int gray = (r + g + b) / 3;
      data[index * 3 + 0] = gray;
      data[index * 3 + 1] = gray;
      data[index * 3 + 2] = gray;
    }
  }

  // Create a 2D array to store the ASCII characters
  char **ascii = malloc(HEIGHT * sizeof(char *));
  for (i = 0; i < HEIGHT; i++) {
    ascii[i] = malloc(WIDTH * sizeof(char));
  }

  // Convert the grayscale image to ASCII characters
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      int index = i * WIDTH + j;
      int gray = data[index * 3 + 0];
      char c;
      if (gray < 32) {
        c = '#';
      } else if (gray < 64) {
        c = '%';
      } else if (gray < 96) {
        c = '@';
      } else if (gray < 128) {
        c = '*';
      } else if (gray < 160) {
        c = ':';
      } else if (gray < 192) {
        c = '=';
      } else if (gray < 224) {
        c = '+';
      } else {
        c = ' ';
      }
      ascii[i][j] = c;
    }
  }

  // Write the ASCII art to a file
  fp = fopen("output.txt", "w");
  if (fp == NULL) {
    printf("Error opening the output text file.\n");
    return 1;
  }
  for (i = 0; i < HEIGHT; i++) {
    fwrite(ascii[i], 1, WIDTH, fp);
    fwrite("\n", 1, 1, fp);
  }
  fclose(fp);

  // Free the memory
  free(data);
  for (i = 0; i < HEIGHT; i++) {
    free(ascii[i]);
  }
  free(ascii);

  return 0;
}