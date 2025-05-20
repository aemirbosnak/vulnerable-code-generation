//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NR_CPU 4

struct cpu_usage {
  int user;
  int system;
  int idle;
  int total;
};

void get_cpu_usage(struct cpu_usage *usage) {
  FILE *fp;
  char line[128];
  int i = 0;

  fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    return;
  }

  while (fgets(line, 128, fp) != NULL) {
    if (line[0] == 'c') {
      usage->user = atoi(&line[13]);
      usage->system = atoi(&line[16]);
      usage->idle = atoi(&line[19]);
      usage->total = atoi(&line[22]);
      i++;
    }
  }

  fclose(fp);

  if (i == 0) {
    return;
  }
}

int main() {
  struct cpu_usage usage;

  while (1) {
    get_cpu_usage(&usage);

    printf("CPU usage:");
    printf("\n");
    printf("  - User: %.2f%%", (double)usage.user / usage.total * 100);
    printf("\n");
    printf("  - System: %.2f%%", (double)usage.system / usage.total * 100);
    printf("\n");
    printf("  - Idle: %.2f%%", (double)usage.idle / usage.total * 100);
    printf("\n");
    printf("  - Total: %.2f%%", (double)usage.total / usage.total * 100);

    sleep(1);
  }

  return 0;
}