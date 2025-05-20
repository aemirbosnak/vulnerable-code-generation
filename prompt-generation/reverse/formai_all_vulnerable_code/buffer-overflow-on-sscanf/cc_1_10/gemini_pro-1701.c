//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function to get the current RAM usage in bytes
size_t get_ram_usage() {
  FILE *file = fopen("/proc/meminfo", "r");
  if (!file) {
    perror("Error opening /proc/meminfo");
    return 0;
  }

  char buffer[1024];
  size_t ram_usage = 0;
  while (fgets(buffer, sizeof(buffer), file)) {
    if (sscanf(buffer, "MemTotal: %zu kB", &ram_usage) == 1) {
      break;
    }
  }
  fclose(file);

  return ram_usage * 1024;
}

// Function to monitor the RAM usage and print it to the console
void monitor_ram_usage() {
  // Get the initial RAM usage
  size_t initial_ram_usage = get_ram_usage();

  // Print the initial RAM usage
  printf("Initial RAM usage: %zu bytes\n", initial_ram_usage);

  // Loop forever, monitoring the RAM usage
  while (1) {
    // Get the current RAM usage
    size_t current_ram_usage = get_ram_usage();

    // Calculate the difference between the current and initial RAM usage
    size_t ram_usage_diff = current_ram_usage - initial_ram_usage;

    // Print the current RAM usage and the difference
    printf("Current RAM usage: %zu bytes (%+zu bytes)\n", current_ram_usage, ram_usage_diff);

    // Sleep for 1 second
    sleep(1);
  }
}

int main() {
  // Monitor the RAM usage
  monitor_ram_usage();

  return 0;
}