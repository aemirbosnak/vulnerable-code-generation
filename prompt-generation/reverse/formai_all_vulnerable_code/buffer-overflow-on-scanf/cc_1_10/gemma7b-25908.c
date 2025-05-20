//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int w, h, i, j, r, g, b;
  char **img;
  char **ascii_art;

  printf("Enter the width of the image: ");
  scanf("%d", &w);

  printf("Enter the height of the image: ");
  scanf("%d", &h);

  img = (char **)malloc(h * sizeof(char *) + 1);
  for (i = 0; i < h; i++) {
    img[i] = (char *)malloc(w * sizeof(char) + 1);
  }

  ascii_art = (char **)malloc(h * sizeof(char *) + 1);
  for (i = 0; i < h; i++) {
    ascii_art[i] = (char *)malloc(w * sizeof(char) + 1);
  }

  printf("Enter the RGB values for each pixel (R, G, B): ");
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      scanf("%d, %d, %d ", &r, &g, &b);

      img[i][j] = rgb_to_ascii(r, g, b);
      ascii_art[i][j] = img[i][j];
    }
  }

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      printf("%c ", ascii_art[i][j]);
    }
    printf("\n");
  }

  free(img);
  free(ascii_art);

  return 0;
}

int rgb_to_ascii(int r, int g, int b) {
  int avg = (r + g + b) / 3;
  return avg;
}