//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

unsigned char pixels[WIDTH * HEIGHT];

void draw_line(int x0, int y0, int x1, int y1) {
  int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
  int err = (dx > dy ? dx : -dy) / 2;
  while (1) {
    pixels[y0 * WIDTH + x0] = 1;
    if (x0 == x1 && y0 == y1) break;
    int e2 = err;
    if (e2 > -dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

void draw_circle(int x0, int y0, int radius) {
  int x = 0, y = radius;
  int d = 3 - 2 * radius;
  while (y >= 0) {
    pixels[(y0 + y) * WIDTH + (x0 + x)] = 1;
    pixels[(y0 + y) * WIDTH + (x0 - x)] = 1;
    pixels[(y0 - y) * WIDTH + (x0 + x)] = 1;
    pixels[(y0 - y) * WIDTH + (x0 - x)] = 1;
    x++;
    if (d > 0) {
      y--;
      d += 4 * (x - y) + 6;
    } else {
      d += 4 * x + 6;
    }
  }
}

void print_pixels() {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c", pixels[y * WIDTH + x] ? '*' : ' ');
    }
    printf("\n");
  }
}

int main() {
  draw_line(10, 10, 70, 10);
  draw_line(70, 10, 70, 20);
  draw_line(70, 20, 10, 20);
  draw_line(10, 20, 10, 10);
  draw_circle(40, 15, 10);
  print_pixels();
  return 0;
}