#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
  FILE *fp;
  char line[1024];
  long mem_free, mem_used, total_mem;
  int err;

  fp = fopen("/proc/meminfo", "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  while (1) {
    err = fgets(line, 1024, fp);
    if (err == -1) {
      perror("Error reading file");
      exit(1);
    }

    if (line[0] == 'M') {
      mem_free = atoi(&line[13]) * 1024;
      mem_used = atoi(&line[6]) * 1024;
      total_mem = mem_free + mem_used;
      printf("Memory usage: %ld MB free, %ld MB used, %ld MB total\n", mem_free, mem_used, total_mem);
    }

    sleep(1);
  }

  fclose(fp);
  return 0;
}
