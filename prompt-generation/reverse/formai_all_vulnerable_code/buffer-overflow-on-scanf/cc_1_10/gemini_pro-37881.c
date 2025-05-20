//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4
#define MAX_TURNS 10

int grid[GRID_SIZE][GRID_SIZE];
int open[GRID_SIZE][GRID_SIZE];

void init_grid() {
  int i, j, k, l;
  int numbers[GRID_SIZE * GRID_SIZE];
  for (i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
    numbers[i] = i / 2;
  }
  for (i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
    j = rand() % (GRID_SIZE * GRID_SIZE);
    k = numbers[j];
    numbers[j] = numbers[i];
    numbers[i] = k;
  }
  l = 0;
  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      grid[i][j] = numbers[l];
      open[i][j] = 0;
      l++;
    }
  }
}

void print_grid() {
  int i, j;
  for (i = 0; i < GRID_SIZE; i++) {
    for (j = 0; j < GRID_SIZE; j++) {
      if (open[i][j] == 0) {
        printf("X ");
      } else {
        printf("%d ", grid[i][j]);
      }
    }
    printf("\n");
  }
}

int check_match(int i1, int j1, int i2, int j2) {
  return grid[i1][j1] == grid[i2][j2];
}

int main() {
  int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  int turns = MAX_TURNS;
  int score = 0;
  srand(time(NULL));
  init_grid();
  while (turns > 0 && score < GRID_SIZE * GRID_SIZE / 2) {
    print_grid();
    printf("Enter the coordinates of two cards to flip (row, column): ");
    scanf("%d %d", &i, &j);
    scanf("%d %d", &k, &l);
    if (i >= 0 && i < GRID_SIZE && j >= 0 && j < GRID_SIZE &&
        k >= 0 && k < GRID_SIZE && l >= 0 && l < GRID_SIZE) {
      if (open[i][j] == 0 && open[k][l] == 0) {
        open[i][j] = 1;
        open[k][l] = 1;
        if (check_match(i, j, k, l)) {
          score++;
          printf("Match!\n");
        } else {
          printf("No match.\n");
          turns--;
        }
      } else {
        printf("Invalid coordinates.\n");
      }
    } else {
      printf("Invalid coordinates.\n");
    }
  }
  print_grid();
  if (score == GRID_SIZE * GRID_SIZE / 2) {
    printf("Congratulations! You won!\n");
  } else {
    printf("Game over! You lose.\n");
  }
  return 0;
}