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

  int free_mem = atoi(buf);
  int total_mem = atoi(buf + 12);
  int used_mem = total_mem - free_mem;

  printf("Free memory: %d KB\n", free_mem);
  printf("Total memory: %d KB\n", total_mem);
  printf("Used memory: %d KB\n", used_mem);

  return 0;
}
