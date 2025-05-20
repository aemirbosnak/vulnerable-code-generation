//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_BUF 256

int brightness(int rgb) {
  return (rgb >> 16) + ((rgb >> 8) & 0xFF) + (rgb & 0xFF);
}

char *str_alloc(int len) {
  char *str = malloc(len + 1);
  if (!str) {
    perror("malloc");
    exit(1);
  }
  return str;
}

char *get_shape(int n) {
  switch (n % 5) {
  case 0:
    return "  -  ";
  case 1:
    return " () ";
  case 2:
    return "/|\\";
  case 3:
    return " \\/ ";
  case 4:
    return "_|_";
  }
  return NULL;
}

void draw_shape(char *str, int n) {
  int i;
  for (i = 0; i < 3; i++)
    if (i == 1 && str[i] == '|')
      str[i] = '+';
    else
      str[i] = n * str[i];
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <image.bmp>\n", argv[0]);
    exit(1);
  }

  FILE *fp = fopen(argv[1], "rb");
  if (!fp) {
    perror("fopen");
    exit(1);
  }

  int w, h, bits, pad;
  fread(&w, sizeof(int), 1, fp);
  fread(&h, sizeof(int), 1, fp);
  fseek(fp, 18, SEEK_SET);
  fread(&bits, sizeof(short), 1, fp);
  pad = (w * 3 + 3) % 4;

  if (w > WIDTH || h > HEIGHT) {
    fprintf(stderr, "Image too large: %dx%d\n", w, h);
    exit(1);
  }

  unsigned char *buf = malloc(w * h * 3);
  if (!buf) {
    perror("malloc");
    exit(1);
  }

  int i, j, x, y, idx, n;
  fread(buf, w * h * 3, 1, fp);
  fclose(fp);

  char *ascii[HEIGHT];
  for (i = 0; i < HEIGHT; i++)
    ascii[i] = str_alloc(WIDTH + 1);

  for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
      idx = (y * w + x) * 3;
      n = brightness(buf[idx] | (buf[idx + 1] << 8) | (buf[idx + 2] << 16));
      n = n / (765 / HEIGHT);
      draw_shape(ascii[y] + x, n);
    }
    idx = (y * w + w) * 3;
    ascii[y][x] = '\0';
    fwrite(ascii[y], 1, WIDTH + 1, stdout);
  }

  return 0;
}