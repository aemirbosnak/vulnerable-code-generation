#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  FILE *fp;
  fp = fopen("coordinates.txt", "r");
  if (fp == NULL) {
    return 1;
  }

  char buffer[1024];
  fscanf(fp, "%s", buffer);

  int x, y;
  char **coordinates = NULL;
  coordinates = (char**)malloc(sizeof(char *) * 10);
  for (int i = 0; i < 10; i++) {
    coordinates[i] = (char *)malloc(sizeof(char) * 1024);
  }

  fscanf(fp, "%d %d", &x, &y);
  for (int i = 0; i < x; i++) {
    fscanf(fp, "%s", coordinates[i]);
  }

  fclose(fp);

  // Perform k-means clustering here

  FILE *fp_out;
  fp_out = fopen("results.txt", "w");
  fprintf(fp_out, "Results:\n");
  for (int i = 0; i < x; i++) {
    fprintf(fp_out, "%d %d\n", coordinates[i][0], coordinates[i][1]);
  }
  fclose(fp_out);

  return 0;
}
