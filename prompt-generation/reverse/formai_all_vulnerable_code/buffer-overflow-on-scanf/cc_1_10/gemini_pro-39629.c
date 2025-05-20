//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int numDisks;
  int *a;
  int *b;
  int *c;
} TowersOfHanoi;

TowersOfHanoi *createTowersOfHanoi(int numDisks) {
  TowersOfHanoi *towersOfHanoi = malloc(sizeof(TowersOfHanoi));
  towersOfHanoi->numDisks = numDisks;
  towersOfHanoi->a = malloc(sizeof(int) * numDisks);
  towersOfHanoi->b = malloc(sizeof(int) * numDisks);
  towersOfHanoi->c = malloc(sizeof(int) * numDisks);
  for (int i = 0; i < numDisks; i++) {
    towersOfHanoi->a[i] = -1;
    towersOfHanoi->b[i] = -1;
    towersOfHanoi->c[i] = -1;
  }
  return towersOfHanoi;
}

void moveDisk(TowersOfHanoi *towersOfHanoi, int n, char from, char to) {
  if (n == 1) {
    switch (from) {
      case 'A':
        switch (to) {
          case 'B':
            towersOfHanoi->b[towersOfHanoi->numDisks - n] = towersOfHanoi->a[towersOfHanoi->numDisks - n];
            towersOfHanoi->a[towersOfHanoi->numDisks - n] = -1;
            break;
          case 'C':
            towersOfHanoi->c[towersOfHanoi->numDisks - n] = towersOfHanoi->a[towersOfHanoi->numDisks - n];
            towersOfHanoi->a[towersOfHanoi->numDisks - n] = -1;
            break;
        }
        break;
      case 'B':
        switch (to) {
          case 'A':
            towersOfHanoi->a[towersOfHanoi->numDisks - n] = towersOfHanoi->b[towersOfHanoi->numDisks - n];
            towersOfHanoi->b[towersOfHanoi->numDisks - n] = -1;
            break;
          case 'C':
            towersOfHanoi->c[towersOfHanoi->numDisks - n] = towersOfHanoi->b[towersOfHanoi->numDisks - n];
            towersOfHanoi->b[towersOfHanoi->numDisks - n] = -1;
            break;
        }
        break;
      case 'C':
        switch (to) {
          case 'A':
            towersOfHanoi->a[towersOfHanoi->numDisks - n] = towersOfHanoi->c[towersOfHanoi->numDisks - n];
            towersOfHanoi->c[towersOfHanoi->numDisks - n] = -1;
            break;
          case 'B':
            towersOfHanoi->b[towersOfHanoi->numDisks - n] = towersOfHanoi->c[towersOfHanoi->numDisks - n];
            towersOfHanoi->c[towersOfHanoi->numDisks - n] = -1;
            break;
        }
        break;
    }
  } else {
    switch (from) {
      case 'A':
        moveDisk(towersOfHanoi, n - 1, 'A', 'C');
        moveDisk(towersOfHanoi, 1, 'A', 'B');
        moveDisk(towersOfHanoi, n - 1, 'C', 'B');
        break;
      case 'B':
        moveDisk(towersOfHanoi, n - 1, 'B', 'A');
        moveDisk(towersOfHanoi, 1, 'B', 'C');
        moveDisk(towersOfHanoi, n - 1, 'A', 'C');
        break;
      case 'C':
        moveDisk(towersOfHanoi, n - 1, 'C', 'B');
        moveDisk(towersOfHanoi, 1, 'C', 'A');
        moveDisk(towersOfHanoi, n - 1, 'B', 'A');
        break;
    }
  }
}

void printTowersOfHanoi(TowersOfHanoi *towersOfHanoi) {
  for (int i = 0; i < towersOfHanoi->numDisks; i++) {
    printf("%d %d %d\n", towersOfHanoi->a[i], towersOfHanoi->b[i], towersOfHanoi->c[i]);
  }
  printf("\n");
}

int main() {
  int numDisks;
  printf("Enter the number of disks: ");
  scanf("%d", &numDisks);
  TowersOfHanoi *towersOfHanoi = createTowersOfHanoi(numDisks);
  for (int i = towersOfHanoi->numDisks - 1; i >= 0; i--) {
    towersOfHanoi->a[i] = i + 1;
  }
  printTowersOfHanoi(towersOfHanoi);
  moveDisk(towersOfHanoi, numDisks, 'A', 'C');
  printTowersOfHanoi(towersOfHanoi);
  return 0;
}