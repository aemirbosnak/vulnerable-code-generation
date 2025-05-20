//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the RAM usage monitor struct
typedef struct {
  size_t total_ram;
  size_t free_ram;
  size_t used_ram;
} ram_usage;

// Get the RAM usage
ram_usage get_ram_usage() {
  ram_usage usage;

  // Open the /proc/meminfo file
  FILE *meminfo = fopen("/proc/meminfo", "r");
  if (meminfo == NULL) {
    perror("fopen(/proc/meminfo)");
    exit(1);
  }

  // Read the total RAM line
  char line[1024];
  if (fgets(line, sizeof(line), meminfo) == NULL) {
    perror("fgets(line, sizeof(line), meminfo)");
    exit(1);
  }

  // Parse the total RAM
  sscanf(line, "MemTotal: %lu kB", &usage.total_ram);

  // Read the free RAM line
  if (fgets(line, sizeof(line), meminfo) == NULL) {
    perror("fgets(line, sizeof(line), meminfo)");
    exit(1);
  }

  // Parse the free RAM
  sscanf(line, "MemFree: %lu kB", &usage.free_ram);

  // Calculate the used RAM
  usage.used_ram = usage.total_ram - usage.free_ram;

  // Close the /proc/meminfo file
  fclose(meminfo);

  return usage;
}

// Print the RAM usage
void print_ram_usage(ram_usage usage) {
  printf("Total RAM: %lu kB\n", usage.total_ram);
  printf("Free RAM: %lu kB\n", usage.free_ram);
  printf("Used RAM: %lu kB\n", usage.used_ram);
}

// Main function
int main() {
  // Get the RAM usage
  ram_usage usage = get_ram_usage();

  // Print the RAM usage
  print_ram_usage(usage);

  return 0;
}