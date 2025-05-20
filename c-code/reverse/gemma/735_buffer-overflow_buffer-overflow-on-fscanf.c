#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  FILE* pipe = popen("top -b", "r");
  if (!pipe) {
    perror("popen");
    return 1;
  }

  char line[1024];
  int cpu_usage;
  while (fscanf(pipe, "%d", &cpu_usage) != EOF) {
    printf("CPU usage: %d%%\n", cpu_usage);
  }

  pclose(pipe);
  return 0;
}
