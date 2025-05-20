#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp = fopen("/proc/meminfo", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char mem_free[64], mem_used[64], mem_buff[64];
    int ret = sscanf(line, "MemFree: %s, MemUsed: %s, MemBuff: %s", mem_free, mem_used, mem_buff);
    if (ret != 3) {
      fprintf(stderr, "Error parsing line: %s", line);
      continue;
    }

    long free = atoi(mem_free);
    long used = atoi(mem_used);
    long buff = atoi(mem_buff);

    printf("Free: %ld, Used: %ld, Buff: %ld\n", free, used, buff);
  }

  fclose(fp);
  return 0;
}
