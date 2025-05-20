//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 10

typedef struct Pixel {
  int r, g, b, a;
} Pixel;

Pixel pixels[MAX_WIDTH * MAX_HEIGHT];

void drawPixel(int x, int y, Pixel pixel) {
  pixels[x * MAX_HEIGHT + y] = pixel;
}

void drawLine(int x1, int y1, int x2, int y2, Pixel color) {
  drawPixel(x1, y1, color);
  drawPixel(x2, y2, color);
  drawLine(x1 + 1, y1, x2 - 1, y2, color);
}

void drawCircle(int x, int y, int radius, Pixel color) {
  for (int i = 0; i < radius; i++) {
    for (int j = 0; j < radius; j++) {
      int dx = x - i;
      int dy = y - j;
      if (dx * dx + dy * dy <= radius * radius) {
        drawPixel(x, y, color);
      }
    }
  }
}

int main() {
  Pixel black = { .r = 0, .g = 0, .b = 0, .a = 255 };
  Pixel red = { .r = 255, .g = 0, .b = 0, .a = 255 };
  Pixel green = { .r = 0, .g = 255, .b = 0, .a = 255 };
  Pixel blue = { .r = 0, .g = 0, .b = 255, .a = 255 };

  drawCircle(10, 10, 5, red);
  drawLine(0, 0, 10, 10, black);
  drawPixel(5, 5, green);

  for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++) {
    printf("%c", pixels[i].r);
  }

  printf("\n");

  return 0;
}