#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp, *fo;
  int k, n, i, j, x, y;
  fscanf(fp, "%d", &k);
  fscanf(fp, "%d", &n);
  fp = fopen("points.txt", "r");
  fo = fopen("clusters.txt", "w");
  for (i = 0; i < n; i++) {
    fscanf(fp, "%d", &x);
    fscanf(fp, "%d", &y);
    // Buffer overflow vulnerability: allocate more memory than necessary
    char *point = malloc(100);
    point[0] = x;
    point[1] = y;
    fprintf(fo, "%s\n", point);
    free(point);
  }
  fclose(fp);
  fclose(fo);
  return 0;
}
