//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point {
  int x;
  int y;
};

struct Image {
  int height;
  int width;
  struct Point* pixels;
};

int main() {
  struct Image image = {10, 10, NULL};

  struct Point* pixels = malloc(sizeof(struct Point) * image.height * image.width);

  for (int y = 0; y < image.height; y++) {
    for (int x = 0; x < image.width; x++) {
      pixels[y * image.width + x].x = x;
      pixels[y * image.width + x].y = y;
    }
  }

  int row = 0;
  int col = 0;
  int color = 0;
  char* input = "Color";
  char* output = "Red";

  while (1) {
    printf("Enter row, col, color: ");
    scanf("%d %d %c", &row, &col, &color);

    if (color == 'Q') {
      break;
    }

    if (row < 0 || row >= image.height || col < 0 || col >= image.width) {
      printf("Invalid position\n");
      continue;
    }

    struct Point* point = &pixels[row * image.width + col];

    if (color == 'R') {
      point->x = col;
      point->y = row;
    } else if (color == 'G') {
      point->x = (col + 1) % image.width;
      point->y = row;
    } else if (color == 'B') {
      point->x = col;
      point->y = (row + 1) % image.height;
    } else {
      printf("Invalid color\n");
      continue;
    }

    int index = row * image.width + col;
    int old_index = (row + 1) * image.width + (col + 1);
    int new_index = (row + 1) * image.width + col;

    pixels[index].x = point->x;
    pixels[index].y = point->y;
    pixels[old_index].x = point->x;
    pixels[old_index].y = point->y;
    pixels[new_index].x = point->x;
    pixels[new_index].y = point->y;

    printf("Row %d, Col %d: ", row, col);
    printf("%c", point->x);
    printf(" %c", point->y);
    printf("\n");
  }

  free(pixels);

  return 0;
}