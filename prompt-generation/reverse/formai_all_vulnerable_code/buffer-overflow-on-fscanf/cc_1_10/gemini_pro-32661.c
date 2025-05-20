//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// A struct to hold the RAM usage information
typedef struct {
  uint64_t total;        // Total RAM in bytes
  uint64_t used;         // Used RAM in bytes
  uint64_t free;         // Free RAM in bytes
  double percent_used;  // Percentage of RAM used
} ram_usage_t;

// A function to get the RAM usage information
ram_usage_t get_ram_usage(void) {
  ram_usage_t usage;

  // Open the /proc/meminfo file
  FILE *f = fopen("/proc/meminfo", "r");
  if (f == NULL) {
    perror("Error opening /proc/meminfo");
    exit(1);
  }

  // Read the total, used, and free RAM values from the file
  fscanf(f, "MemTotal: %llu kB\n", &usage.total);
  fscanf(f, "MemUsed: %llu kB\n", &usage.used);
  fscanf(f, "MemFree: %llu kB\n", &usage.free);

  // Calculate the percentage of RAM used
  usage.percent_used = (double)usage.used / (double)usage.total * 100.0;

  // Close the file
  fclose(f);

  // Return the RAM usage information
  return usage;
}

// A function to print the RAM usage information
void print_ram_usage(ram_usage_t usage) {
  printf("Total RAM: %llu kB\n", usage.total);
  printf("Used RAM: %llu kB\n", usage.used);
  printf("Free RAM: %llu kB\n", usage.free);
  printf("Percentage of RAM used: %.2f%%\n", usage.percent_used);
}

// The main function
int main(void) {
  // Get the RAM usage information
  ram_usage_t usage = get_ram_usage();

  // Print the RAM usage information
  print_ram_usage(usage);

  return 0;
}