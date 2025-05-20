#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  char line[1024];
  FILE *fp;
  int cpu_usage = 0;
  char *ptr;

  fp = popen("top -b", "r");
  if (fp == NULL) {
    perror("Error opening pipe");
    return 1;
  }

  while (fgets(line, 1024, fp) != NULL) {
    ptr = strstr(line, "%CPU");
    if (ptr) {
      cpu_usage = atoi(ptr + 1);
      printf("CPU usage: %d%%\n", cpu_usage);
    }
  }

  pclose(fp);

  return 0;
}
