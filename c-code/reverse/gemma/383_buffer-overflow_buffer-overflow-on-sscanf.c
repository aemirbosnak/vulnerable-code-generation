#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  FILE *fp;
  char buf[1024];
  int total_mem, free_mem, available_mem;
  int err = 0;

  while (1) {
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
      err = 1;
      break;
    }

    fscanf(fp, "%s %s %s", buf, buf, buf);
    fclose(fp);

    total_mem = atoi(buf);
    free_mem = atoi(buf + 16);
    available_mem = atoi(buf + 24);

    printf("Total memory: %.2f MB\n", (total_mem / 1024.0) * 1000);
    printf("Free memory: %.2f MB\n", (free_mem / 1024.0) * 1000);
    printf("Available memory: %.2f MB\n", (available_mem / 1024.0) * 1000);

    sleep(1);
  }

  if (err) {
    printf("Error reading memory information.\n");
  }

  return 0;
}
