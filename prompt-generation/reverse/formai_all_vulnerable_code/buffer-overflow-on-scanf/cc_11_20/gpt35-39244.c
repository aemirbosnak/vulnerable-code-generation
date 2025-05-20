//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: introspective
#include <stdio.h>

int main() {
  int x, y, dir, verify;
  x = 0;  // Starting x-coordinate
  y = 0;  // Starting y-coordinate
  dir = 1; // Starting direction (1 = North, 2 = East, 3 = South, 4 = West)

  printf("Starting coordinates: (%d,%d)\n", x, y);
  printf("Starting direction: ");
  if (dir == 1) {
    printf("North\n");
  } else if (dir == 2) {
    printf("East\n");
  } else if (dir == 3) {
    printf("South\n");
  } else {
    printf("West\n");
  }

  printf("Please input comma-separated directions (N,E,S,W) and verify (1-Yes, 0-No) after each direction:\n");

  char d; // Direction input
  int v; // Verification input

  while (scanf(" %c, %d", &d, &v) == 2 && v == 1) {
    if (d == 'N') {
      y++;
      dir = 1;
    } else if (d == 'E') {
      x++;
      dir = 2;
    } else if (d == 'S') {
      y--;
      dir = 3;
    } else {
      x--;
      dir = 4;
    }

    printf("New coordinates: (%d,%d)\n", x, y);
    printf("New direction: ");
    if (dir == 1) {
      printf("North\n");
    } else if (dir == 2) {
      printf("East\n");
    } else if (dir == 3) {
      printf("South\n");
    } else {
      printf("West\n");
    }

    printf("Please input the next direction and verification:\n");
  }

  printf("Final coordinates: (%d,%d)\n", x, y);
  printf("Final direction: ");
  if (dir == 1) {
    printf("North\n");
  } else if (dir == 2) {
    printf("East\n");
  } else if (dir == 3) {
    printf("South\n");
  } else {
    printf("West\n");
  }

  return 0;
}