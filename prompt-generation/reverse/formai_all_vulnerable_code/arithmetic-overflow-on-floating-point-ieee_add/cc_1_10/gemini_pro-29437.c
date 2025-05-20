//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

// Get the current time in milliseconds
long long get_time_ms() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000;
}

// Get the CPU usage as a percentage
float get_cpu_usage() {
  FILE *fp;
  char line[1024];
  float user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

  fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    return -1.0;
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    if (sscanf(line, "cpu %f %f %f %f %f %f %f %f %f %f", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice) == 10) {
      break;
    }
  }

  fclose(fp);

  return (user + nice + system + irq + softirq) / (user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice) * 100.0;
}

int main() {
  long long start_time = get_time_ms();
  float cpu_usage = get_cpu_usage();
  while (1) {
    long long current_time = get_time_ms();
    float elapsed_time = (float)(current_time - start_time) / 1000.0;
    if (elapsed_time >= 1.0) {
      printf("CPU usage: %.2f%%\n", cpu_usage);
      start_time = current_time;
      cpu_usage = get_cpu_usage();
    }
    usleep(100000);
  }

  return 0;
}