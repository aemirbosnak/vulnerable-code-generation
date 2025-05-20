#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int main() {
  FILE *fp;
  char buf[1024];
  int read_bytes = 0;
  long total_free = 0;

  fp = fopen("/proc/meminfo", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  read_bytes = fread(buf, 1, 1024, fp);
  fclose(fp);

  if (read_bytes < 0) {
    perror("Error reading file");
    return 1;
  }

  // Parse the output, extract the total free memory
  char *line = strtok(buf, "\n");
  while (line) {
    char *key = strstr(line, "MemFree:");
    if (key) {
      long free_mem = strtol(key + 8, NULL, 10);
      total_free += free_mem;
    }
    line = strtok(NULL, "\n");
  }

  // Print the total free memory
  printf("Total free memory: %ld KB\n", total_free);

  return 0;
}
