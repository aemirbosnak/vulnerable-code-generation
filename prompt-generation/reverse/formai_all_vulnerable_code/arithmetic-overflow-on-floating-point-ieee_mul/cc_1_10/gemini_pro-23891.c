//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_CPU_USAGE 100

// Get the CPU usage.
int get_cpu_usage() {
  FILE *fp;
  char buf[1024];
  double user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

  // Open the /proc/stat file.
  fp = fopen("/proc/stat", "r");
  if (!fp) {
    return -1;
  }

  // Read the first line of the file.
  if (!fgets(buf, sizeof(buf), fp)) {
    fclose(fp);
    return -1;
  }

  // Parse the CPU usage.
  sscanf(buf, "cpu %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

  // Close the file.
  fclose(fp);

  // Calculate the CPU usage.
  double usage = (user + nice + system) / (user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice) * 100.0;

  // Return the CPU usage.
  return (int)usage;
}

// Print the CPU usage.
void print_cpu_usage(int cpu_usage) {
  printf("CPU usage: %d%%\n", cpu_usage);
}

// Main function.
int main() {
  // Get the CPU usage.
  int cpu_usage = get_cpu_usage();

  // Print the CPU usage.
  print_cpu_usage(cpu_usage);

  return 0;
}