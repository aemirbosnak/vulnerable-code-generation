//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_METRIC_SIZE 1024
#define METRIC_UPDATE_INTERVAL 1 // in seconds
#define CPU_USAGE_FILE "/proc/stat"

// Function to get the CPU usage
int get_cpu_usage(char *metric) {
  FILE *file = fopen(CPU_USAGE_FILE, "r");
  if (file == NULL) {
    perror("Error opening file");
    return -1;
  }

  // Read the first line of the file
  char line[MAX_METRIC_SIZE];
  if (fgets(line, MAX_METRIC_SIZE, file) == NULL) {
    perror("Error reading file");
    fclose(file);
    return -1;
  }

  // Parse the CPU usage from the line
  char *ptr = strstr(line, "cpu");
  if (ptr == NULL) {
    fprintf(stderr, "Error parsing file");
    fclose(file);
    return -1;
  }

  ptr += 3; // Skip the "cpu" prefix

  // Parse the individual CPU usage values
  int user, nice, system, idle, iowait, irq, softirq;
  if (sscanf(ptr, "%d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq) != 7) {
    fprintf(stderr, "Error parsing CPU usage");
    fclose(file);
    return -1;
  }

  // Calculate the total CPU usage
  int total = user + nice + system + idle + iowait + irq + softirq;

  // Calculate the CPU usage percentage
  int cpu_usage = (100 * (total - idle)) / total;

  // Copy the CPU usage percentage to the metric buffer
  snprintf(metric, MAX_METRIC_SIZE, "%d", cpu_usage);

  // Close the file
  fclose(file);

  return 0;
}

// Main function
int main() {
  // Infinite loop to continuously monitor CPU usage
  while (1) {
    char metric[MAX_METRIC_SIZE];

    // Get the CPU usage
    if (get_cpu_usage(metric) != 0) {
      fprintf(stderr, "Error getting CPU usage");
      return -1;
    }

    // Print the CPU usage to the console
    printf("CPU Usage: %s%%\n", metric);

    // Sleep for the specified interval
    sleep(METRIC_UPDATE_INTERVAL);
  }

  return 0;
}