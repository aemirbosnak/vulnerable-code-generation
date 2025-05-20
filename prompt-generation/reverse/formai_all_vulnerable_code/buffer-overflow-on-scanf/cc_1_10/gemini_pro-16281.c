//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LEVELS 10
#define NUM_COLUMNS 10

int width = 10;
int height = 10;
int num_of_iterations;
int *grid;

const char *states[] = {".", "#", "o"};

void print_grid()
{
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%s", states[grid[i * width + j]]);
    }
    printf("\n");
  }
}

int main()
{
  srand(time(NULL));
  grid = malloc(sizeof(int) * width * height);

  printf("Enter width and height (e.g. 10 10): ");
  scanf("%d %d", &width, &height);
  printf("Enter number of iterations: ");
  scanf("%d", &num_of_iterations);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      grid[i * width + j] = (i == 0) ? 2 : 0;
    }
  }

  for (int k = 0; k < num_of_iterations; k++) {
    for (int i = 1; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (rand() % 2 == 0) {
          grid[i * width + j] = grid[(i - 1) * width + j];
        }
      }
    }
    print_grid();
    printf("\n");
  }

  free(grid);
  return 0;
}