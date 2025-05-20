//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10
#define MAX_CHAR 94

char ascii_map[MAX_CHAR];

void init_ascii_map() {
  int i, j;
  for (i = 0; i < MAX_CHAR; i++) {
    ascii_map[i] = ' ';
  }
  for (i = 33; i < 127; i++) {
    ascii_map[i] = (char)i;
  }
  for (i = 0; i < 26; i++) {
    for (j = 65 + i; j < 91 + i; j++) {
      ascii_map[j] = ascii_map[j - 32];
    }
  }
}

void print_ascii_art(int image[WIDTH][HEIGHT]) {
  int i, j, c;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      c = image[j][i];
      printf("%c", ascii_map[c]);
    }
    printf("\n");
  }
}

void load_image(int image[WIDTH][HEIGHT], char *filename) {
  int i, j, value;
  FILE *fp;
  fp = fopen(filename, "r");
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      fscanf(fp, "%d", &value);
      image[j][i] = value;
    }
  }
  fclose(fp);
}

int main(int argc, char **argv) {
  int image[WIDTH][HEIGHT];
  if (argc != 2) {
    printf("Usage: %s <image.bin>\n", argv[0]);
    return 1;
  }
  init_ascii_map();
  load_image(image, argv[1]);
  print_ascii_art(image);
  return 0;
}