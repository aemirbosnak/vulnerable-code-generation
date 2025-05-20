#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  FILE *fp;
  char buf[1024];
  int i, j, cpu_usage[64] = {0};

  fp = popen("top -b", "r");
  if (fp == NULL) {
    perror("popen");
    return 1;
  }

  for (i = 0; i < 64; i++) {
    fscanf(fp, "%d ", cpu_usage + i);
  }

  pclose(fp);

  for (j = 0; j < 64; j++) {
    printf("%d ", cpu_usage[j]);
  }

  printf("\n");

  for (i = 0; i < 64; i++) {
    printf("%d ", cpu_usage[i]);
  }

  return 0;
}
