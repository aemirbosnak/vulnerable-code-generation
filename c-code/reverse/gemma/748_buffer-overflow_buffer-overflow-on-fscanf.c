#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp, *fo;
  int n, k, i, j, x, y;
  fscanf(fp, "%d", &n);
  fscanf(fp, "%d", &k);
  int points[n];
  for (i = 0; i < n; i++) {
    fscanf(fp, "%d", &x);
    fscanf(fp, "%d", &y);
    points[i] = (x * x) + (y * y);
  }
  fclose(fp);
  fo = fopen("output.txt", "w");
  for (i = 0; i < n; i++) {
    fprintf(fo, "%d ", points[i]);
  }
  fclose(fo);
  return 0;
}
