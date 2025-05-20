//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//procedural generation of a medieval world
int main() {
  srand(time(NULL));
  int n = 10;
  int m = 10;
  int **world = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    world[i] = (int *)malloc(sizeof(int) * m);
    for (int j = 0; j < m; j++) {
      //forest
      world[i][j] = 1;
      //generate random trees
      if (rand() % 10 == 0) {
        world[i][j] = 2;
      }
      //generate random wolves
      if (rand() % 20 == 0) {
        world[i][j] = 3;
      }
      //generate random villages
      if (rand() % 50 == 0) {
        world[i][j] = 4;
      }
    }
  }
  //print the world
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      switch (world[i][j]) {
        case 1:
          printf(".");
          break;
        case 2:
          printf("T");
          break;
        case 3:
          printf("W");
          break;
        case 4:
          printf("V");
          break;
      }
    }
    printf("\n");
  }
  return 0;
}