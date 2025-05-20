//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
  int rows, cols, startRow, startCol, destRow, destCol, i, j, k, r, c, direction, distance;
  int a[MAX_ROWS][MAX_COLS];

  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the starting row: ");
  scanf("%d", &startRow);
  printf("Enter the starting column: ");
  scanf("%d", &startCol);
  printf("Enter the destination row: ");
  scanf("%d", &destRow);
  printf("Enter the destination column: ");
  scanf("%d", &destCol);

  // Find the distance between two points using Manhattan distance formula
  distance = abs(startRow - destRow) + abs(startCol - destCol);

  // Calculate the path using A* algorithm
  printf("Path found: ");
  printf("%d ", startRow);
  printf("%d ", startCol);
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (a[i][j] == 0) {
        for (k = 0; k < 8; k++) {
          direction = (k % 4) + 1;
          if (direction == 5) {
            if (a[i + 1][j + 1] == 0) {
              a[i + 1][j + 1] = distance;
            } else {
              a[i + 1][j + 1] = 0;
            }
          } else {
            if (a[i + direction][j + 1] == 0) {
              a[i + direction][j + 1] = distance;
            } else {
              a[i + direction][j + 1] = 0;
            }
          }
        }
      }
    }
    distance++;
    printf("%d ", distance);
  }
  printf("\n");

  return 0;
}