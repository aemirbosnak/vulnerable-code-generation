//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define INTERVAL 2

double get_cpu_usage() {
  FILE* fp;
  double stat_cpu_usage;
  char buffer[1024];
  int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
  int count = 0;

  fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    perror("/proc/stat");
    exit(1);
  }

  fgets(buffer, sizeof(buffer), fp);
  fclose(fp);

  /* Scans the first line of /proc/stat for data */
  sscanf(buffer, "cpu %d %d %d %d %d %d %d %d %d %d",
                          &user, &nice, &system, &idle,
                          &iowait, &irq, &softirq, &steal,
                          &guest, &guest_nice);

  /* Calculates CPU usage */
  stat_cpu_usage = (double)((user+nice+system) - (guest+guest_nice)) /
                   (double)((user+nice+system+idle+iowait+irq+softirq+steal) - (guest+guest_nice));
  stat_cpu_usage = round(stat_cpu_usage * 100);

  return stat_cpu_usage;
}

int main(void) {
  double prev_cpu_usage = 0;
  double curr_cpu_usage = 0;
  
  printf("CPU USAGE MONITOR\n");

  while (1) {
    curr_cpu_usage = get_cpu_usage();
    if (curr_cpu_usage != prev_cpu_usage) {
      printf("CPU Usage: %.2f%%\n", curr_cpu_usage);
      prev_cpu_usage = curr_cpu_usage;
    }
    sleep(INTERVAL);
  }

  return 0;
}