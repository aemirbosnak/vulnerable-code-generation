//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to get the current RAM usage
int get_ram_usage() {
  // Open the "/proc/meminfo" file
  FILE *meminfo = fopen("/proc/meminfo", "r");

  // Read the "MemTotal" and "MemFree" values
  int mem_total, mem_free;
  fscanf(meminfo, "MemTotal: %d kB\n", &mem_total);
  fscanf(meminfo, "MemFree: %d kB\n", &mem_free);

  // Close the "/proc/meminfo" file
  fclose(meminfo);

  // Calculate the RAM usage
  int ram_usage = mem_total - mem_free;

  // Return the RAM usage
  return ram_usage;
}

// Function to print the RAM usage
void print_ram_usage() {
  // Get the RAM usage
  int ram_usage = get_ram_usage();

  // Print the RAM usage
  printf("RAM usage: %d kB\n", ram_usage);
}

// Function to monitor the RAM usage
void monitor_ram_usage() {
  // Print the initial RAM usage
  print_ram_usage();

  // Loop forever, printing the RAM usage every second
  while (1) {
    // Sleep for 1 second
    sleep(1);

	// Print the RAM usage
    print_ram_usage();
  }
}

// Main function
int main() {
  // Monitor the RAM usage
  monitor_ram_usage();

  // Return 0 to indicate success
  return 0;
}