#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("/proc/meminfo", "r");
  char buf[1024];
  fscanf(fp, "%s", buf);
  fclose(fp);

  printf("Memory usage: %s", buf);

  return 0;
}
