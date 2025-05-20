//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 50

void draw_sky(int x, int y, int w, int h) {
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (i >= x && i < x + w && j >= y && j < y + h) {
        printf("#");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

void draw_clouds(int x, int y, int w, int h) {
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (i >= x && i < x + w && j >= y && j < y + h) {
        printf("%c", 247);
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

void draw_mountains(int x, int y, int w, int h) {
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (i >= x && i < x + w && j >= y && j < y + h) {
        printf("%c", 248);
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main() {
  int x, y, w, h;

  printf("Enter the dimensions of the sky (width, height): ");
  scanf("%d %d", &w, &h);

  printf("Enter the position of the clouds (x, y): ");
  scanf("%d %d", &x, &y);

  printf("Enter the width and height of the clouds: ");
  scanf("%d %d", &w, &h);

  printf("Enter the position of the mountains (x, y): ");
  scanf("%d %d", &x, &y);

  printf("Enter the width and height of the mountains: ");
  scanf("%d %d", &w, &h);

  draw_sky(x, y, w, h);
  draw_clouds(x, y, w, h);
  draw_mountains(x, y, w, h);

  return 0;
}