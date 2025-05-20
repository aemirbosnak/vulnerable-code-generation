//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CPU_COUNT 8
#define BUFFER_SIZE 1024

// Function to parse the contents of /proc/stat and return total CPU time
unsigned long long get_total_cpu_time() {
  char buffer[BUFFER_SIZE];
  unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

  FILE* fpstat = fopen("/proc/stat", "r");
  fgets(buffer, BUFFER_SIZE, fpstat);
  sscanf(buffer, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
      &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

  fclose(fpstat);

  return user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;
}

int main() {
  unsigned long long total_time_prev, total_time_curr, idle_time_prev, idle_time_curr, delta_total, delta_idle;
  float cpu_usage[CPU_COUNT];

  while (1) {
    // Retrieve CPU time at current and previous intervals
    total_time_prev = get_total_cpu_time();
    idle_time_prev = cpu_usage[0];

    usleep(100000);

    total_time_curr = get_total_cpu_time();
    idle_time_curr = cpu_usage[0];

    // Calculate deltas in CPU and idle time
    delta_total = total_time_curr - total_time_prev;
    delta_idle = idle_time_curr - idle_time_prev;

    // Calculate CPU usage percentage for each CPU
    for (int i = 0; i < CPU_COUNT; i++) {
      cpu_usage[i] = (delta_total - (cpu_usage[0] - cpu_usage[i])) * 100.0 / delta_total;
    }

    // Display CPU usage percentage for each CPU
    for (int i = 0; i < CPU_COUNT; i++) {
      printf("CPU %d Usage: %.2f%%\n", i, cpu_usage[i]);
    }

    printf("\n");

  }
 
  return 0;
}