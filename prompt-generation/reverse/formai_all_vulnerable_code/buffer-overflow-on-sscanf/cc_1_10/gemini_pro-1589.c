//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Custom struct to hold CPU and memory usage data
typedef struct {
  double cpu;
  double mem;
} UsageData;

// Function to get CPU and memory usage data
UsageData getUsageData() {
  UsageData data;
  FILE *fp;
  char buffer[1024];

  // Get CPU usage
  fp = fopen("/proc/stat", "r");
  fgets(buffer, sizeof(buffer), fp);
  sscanf(buffer, "cpu %lf", &data.cpu);
  fclose(fp);

  // Get memory usage
  fp = fopen("/proc/meminfo", "r");
  while (fgets(buffer, sizeof(buffer), fp)) {
    if (sscanf(buffer, "MemTotal: %lf kB", &data.mem) == 1) break;
  }
  fclose(fp);

  return data;
}

// Main function
int main() {
  UsageData data;
  double delta_cpu, delta_mem;

  // Get initial CPU and memory usage data
  data = getUsageData();

  // Loop forever, updating CPU and memory usage data every second
  while (1) {
    sleep(1);
    UsageData data2 = getUsageData();

    // Calculate delta CPU and memory usage
    delta_cpu = data2.cpu - data.cpu;
    delta_mem = data2.mem - data.mem;

    // Clear the screen
    system("clear");
    
    // Print CPU and memory usage data
    printf("CPU usage: %.2f%%\n", delta_cpu);
    printf("Memory usage: %.2f%%\n", delta_mem / 1024); // Convert to MB

    // Update data for next iteration
    data = data2;
  }

  return 0;
}