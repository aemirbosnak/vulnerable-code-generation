//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Get CPU usage in percentage
int get_cpu_usage() {
  // Open the file containing CPU usage information
  FILE *fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    perror("Error opening /proc/stat");
    return -1;
  }

  // Read the first line of the file
  char line[1024];
  if (fgets(line, sizeof(line), fp) == NULL) {
    perror("Error reading /proc/stat");
    fclose(fp);
    return -1;
  }

  // Close the file
  fclose(fp);

  // Parse the first line of the file to get CPU usage information
  long long total_time, idle_time;
  sscanf(line, "cpu %lld %lld %lld %lld %lld %lld %lld %lld", &total_time, &idle_time, &idle_time, &idle_time, &idle_time, &idle_time, &idle_time, &idle_time);

  // Calculate CPU usage in percentage
  double cpu_usage = 100.0 * (total_time - idle_time) / total_time;

  // Return CPU usage
  return (int)cpu_usage;
}

// Print CPU usage every second
int main() {
  while (1) {
    // Get CPU usage
    int cpu_usage = get_cpu_usage();

    // Print CPU usage
    printf("CPU usage: %d%%\n", cpu_usage);

    // Sleep for 1 second
    sleep(1);
  }

  return 0;
}