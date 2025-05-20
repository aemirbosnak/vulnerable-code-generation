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
  long long mem_total, mem_free, mem_used;
  int line_num = 0;

  fp = fopen("/proc/meminfo", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  while (fgets(buf, 1024, fp) != NULL) {
    line_num++;
    if (buf[0] == 'M' && buf[1] == 'B') {
      char *mem_total_str = strchr(buf, 'T');
      char *mem_free_str = strchr(buf, 'F');
      char *mem_used_str = strchr(buf, 'U');

      mem_total = atoi(mem_total_str) * 1024 * 1024;
      mem_free = atoi(mem_free_str) * 1024 * 1024;
      mem_used = mem_total - mem_free;

      printf("Total memory: %.2f MB\n", (double)mem_total / 1024 / 1024);
      printf("Free memory: %.2f MB\n", (double)mem_free / 1024 / 1024);
      printf("Used memory: %.2f MB\n", (double)mem_used / 1024 / 1024);
    }
  }

  fclose(fp);

  return 0;
}
