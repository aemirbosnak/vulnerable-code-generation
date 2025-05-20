//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define the RAM usage structure
typedef struct {
  size_t total;
  size_t used;
  size_t free;
} ram_usage;

// Get the RAM usage
ram_usage get_ram_usage() {
  ram_usage usage;

  // Open the /proc/meminfo file
  FILE *file = fopen("/proc/meminfo", "r");
  if (file == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  // Read the MemTotal line
  char line[1024];
  if (fgets(line, sizeof(line), file) == NULL) {
    perror("fgets");
    exit(EXIT_FAILURE);
  }

  // Parse the MemTotal line
  sscanf(line, "MemTotal: %lu kB", &usage.total);

  // Read the MemFree line
  if (fgets(line, sizeof(line), file) == NULL) {
    perror("fgets");
    exit(EXIT_FAILURE);
  }

  // Parse the MemFree line
  sscanf(line, "MemFree: %lu kB", &usage.free);

  // Calculate the used RAM
  usage.used = usage.total - usage.free;

  // Close the /proc/meminfo file
  fclose(file);

  return usage;
}

// Print the RAM usage
void print_ram_usage(ram_usage usage) {
  printf("Total RAM: %lu kB\n", usage.total);
  printf("Used RAM: %lu kB\n", usage.used);
  printf("Free RAM: %lu kB\n", usage.free);
}

int main() {
  // Get the RAM usage
  ram_usage usage = get_ram_usage();

  // Print the RAM usage
  print_ram_usage(usage);

  return EXIT_SUCCESS;
}