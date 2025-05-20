#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("points.txt", "r");
  int k = 3;
  int points[1000];
  fscanf(fp, "%d", points);
  fclose(fp);

  // Omit bounds checking for demonstration purposes
  // (This code is vulnerable to a buffer overflow)
  kmeans(points, k);

  return 0;
}

void kmeans(int *points, int k) {
  // Algorithm implementation
}
