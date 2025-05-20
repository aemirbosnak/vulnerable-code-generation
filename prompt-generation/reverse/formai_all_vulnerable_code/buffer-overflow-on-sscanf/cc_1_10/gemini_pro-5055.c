//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Colors for ANSI escape codes
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

// RAM usage data structure
typedef struct {
  size_t total;
  size_t used;
  size_t free;
} ram_usage_t;

// Get RAM usage data
ram_usage_t get_ram_usage() {
  FILE *meminfo = fopen("/proc/meminfo", "r");
  if (meminfo == NULL) {
    perror("Error opening /proc/meminfo");
    exit(EXIT_FAILURE);
  }

  ram_usage_t usage;
  char line[1024];
  while (fgets(line, sizeof(line), meminfo) != NULL) {
    if (sscanf(line, "MemTotal: %lu", &usage.total) == 1)
      continue;
    if (sscanf(line, "MemFree: %lu", &usage.free) == 1)
      continue;
    if (sscanf(line, "Buffers: %lu", &usage.used) == 1)
      continue;
  }

  fclose(meminfo);

  return usage;
}

// Print RAM usage in a retro style
void print_ram_usage(ram_usage_t usage) {
  printf("\n");
  printf("   ____ _ _       _ _ _      _                            _ \n");
  printf("  |  _ \\| (_)     | | | |    (_)                          | |  \n");
  printf("  | |_) | |_ _   _| | | |_ __ _ _ __  _ __   __ _  _ __   | |_  \n");
  printf("  |  __/| | | | | | | | __/ _` | '_ \\| '_ \\ / _` || '_ \\  | __|  \n");
  printf("  | |   | | | |_| | | | || (_| | | | | | | | (_| || | | | | |_   \n");
  printf("  |_|   |_|_|\\__,_|_|_|\\__\\__,_|_| |_|_| |_|\\__,_||_| |_|  \\__|   \n\n");

  printf("  %sTotal: %lu MB%s\n", GREEN, usage.total / 1024 / 1024, RESET);
  printf("  %sUsed: %lu MB%s\n", RED, usage.used / 1024 / 1024, RESET);
  printf("  %sFree: %lu MB%s\n", YELLOW, usage.free / 1024 / 1024, RESET);

  printf("\n");

  // Calculate and print RAM utilization
  float utilization = ((float)usage.used / usage.total) * 100;
  if (utilization < 50) {
    printf("  %sUtilization: %.1f%% %s(Low)%s\n", GREEN, utilization, BLUE, RESET);
  } else if (utilization < 80) {
    printf("  %sUtilization: %.1f%% %s(Medium)%s\n", YELLOW, utilization, BLUE, RESET);
  } else {
    printf("  %sUtilization: %.1f%%  %s(High)%s\n", RED, utilization, BLUE, RESET);
  }
}

int main() {
  // Get RAM usage data
  ram_usage_t usage = get_ram_usage();

  // Print RAM usage in a retro style
  print_ram_usage(usage);

  return EXIT_SUCCESS;
}