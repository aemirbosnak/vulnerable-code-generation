//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the RAM usage structure.
typedef struct {
  unsigned long long total;
  unsigned long long used;
  unsigned long long free;
} ram_usage_t;

// Get the RAM usage.
ram_usage_t get_ram_usage() {
  ram_usage_t usage;
  FILE *fp = fopen("/proc/meminfo", "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    if (sscanf(line, "MemTotal: %llu kB", &usage.total) == 1) {
      continue;
    }
    if (sscanf(line, "MemFree: %llu kB", &usage.free) == 1) {
      continue;
    }
    if (sscanf(line, "MemAvailable: %llu kB", &usage.free) == 1) {
      continue;
    }
  }
  fclose(fp);
  usage.used = usage.total - usage.free;
  return usage;
}

// Print the RAM usage.
void print_ram_usage(ram_usage_t usage) {
  printf("Total RAM: %llu kB\n", usage.total);
  printf("Used RAM: %llu kB\n", usage.used);
  printf("Free RAM: %llu kB\n", usage.free);
}

// Main function.
int main() {
  // Get the RAM usage.
  ram_usage_t usage = get_ram_usage();

  // Print the RAM usage.
  print_ram_usage(usage);

  return 0;
}