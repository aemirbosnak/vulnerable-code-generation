//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  // Initialize variables
  int cpu_usage = 0;
  int prev_cpu_usage = 0;
  int delta_cpu_usage = 0;
  int max_cpu_usage = 0;
  int min_cpu_usage = 100;
  int avg_cpu_usage = 0;
  int total_cpu_usage = 0;
  int num_samples = 0;

  // Get the initial CPU usage
  cpu_usage = get_cpu_usage();

  // Loop forever
  while (1) {
    // Get the current CPU usage
    prev_cpu_usage = cpu_usage;
    cpu_usage = get_cpu_usage();

    // Calculate the delta CPU usage
    delta_cpu_usage = cpu_usage - prev_cpu_usage;

    // Update the max, min, and avg CPU usage
    if (cpu_usage > max_cpu_usage) {
      max_cpu_usage = cpu_usage;
    }
    if (cpu_usage < min_cpu_usage) {
      min_cpu_usage = cpu_usage;
    }
    avg_cpu_usage = (avg_cpu_usage * num_samples + cpu_usage) / (num_samples + 1);

    // Update the total CPU usage
    total_cpu_usage += cpu_usage;

    // Increment the number of samples
    num_samples++;

    // Print the CPU usage statistics
    printf("CPU Usage: %d%%\n", cpu_usage);
    printf("Delta CPU Usage: %d%%\n", delta_cpu_usage);
    printf("Max CPU Usage: %d%%\n", max_cpu_usage);
    printf("Min CPU Usage: %d%%\n", min_cpu_usage);
    printf("Avg CPU Usage: %d%%\n", avg_cpu_usage);
    printf("Total CPU Usage: %d%%\n", total_cpu_usage);

    // Sleep for 1 second
    sleep(1);
  }

  return 0;
}

int get_cpu_usage() {
  // Get the CPU usage from the system
  int cpu_usage = 0;
  FILE *fp = fopen("/proc/stat", "r");
  if (fp != NULL) {
    fscanf(fp, "cpu %d %d %d %d %d %d %d %d %d %d", &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage, &cpu_usage);
    fclose(fp);
  }
  return cpu_usage;
}