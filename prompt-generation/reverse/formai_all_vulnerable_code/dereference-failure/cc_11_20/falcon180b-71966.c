//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 500

int main(void) {
  srand(time(NULL));

  int **image = malloc(HEIGHT * sizeof(int *));
  for (int i = 0; i < HEIGHT; i++) {
    image[i] = malloc(WIDTH * sizeof(int));
  }

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      image[i][j] = rand() % 256;
    }
  }

  int **result = malloc(HEIGHT * sizeof(int *));
  for (int i = 0; i < HEIGHT; i++) {
    result[i] = malloc(WIDTH * sizeof(int));
  }

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      int iterations = 0;
      int zx = 0;
      int zy = 0;
      int c = image[i][j];

      while (iterations < MAX_ITERATIONS && (zx * zx + zy * zy) < 4) {
        int zx_new = zx * zx - zy * zy + c;
        int zy_new = 2 * zx * zy + c;

        if (zx_new * zx_new + zy_new * zy_new > 4) {
          result[i][j] = iterations;
          break;
        }

        zx = zx_new;
        zy = zy_new;
        iterations++;
      }
    }
  }

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < HEIGHT; i++) {
    free(image[i]);
  }
  free(image);

  for (int i = 0; i < HEIGHT; i++) {
    free(result[i]);
  }
  free(result);

  return 0;
}