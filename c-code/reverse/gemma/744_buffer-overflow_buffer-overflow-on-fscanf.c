#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  fp = fopen("points.txt", "r");
  if (fp == NULL) {
    return 1;
  }

  int numPoints = 0;
  fscanf(fp, "%d", &numPoints);

  char **points = malloc(numPoints * 2 * sizeof(char));
  if (points == NULL) {
    return 1;
  }

  for (int i = 0; i < numPoints; i++) {
    fscanf(fp, "%lf %lf", points[i] + 0, points[i] + 1);
  }

  fclose(fp);

  return 0;
}
