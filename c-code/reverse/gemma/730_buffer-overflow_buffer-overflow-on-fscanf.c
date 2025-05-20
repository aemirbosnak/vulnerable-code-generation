#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, n, cpu_usage[1024];
  FILE *fp;

  fp = popen("top -b", "r");
  fscanf(fp, "%d", &n);
  for (i = 0; i < n; i++) {
    fscanf(fp, "%d ", cpu_usage + i);
  }
  pclose(fp);

  for (j = 0; j < n; j++) {
    printf("%d ", cpu_usage[j]);
  }
  printf("\n");

  return 0;
}
