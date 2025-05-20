//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: Ada Lovelace
// The RAM Usage Monitor

// Ada Lovelace was the world's first computer programmer.
// This program is a tribute to her pioneering work.

#include <stdio.h>
#include <stdlib.h>

// Get the current RAM usage in bytes.
long getRAMUsage() {
  // Open the /proc/meminfo file.
  FILE *meminfo = fopen("/proc/meminfo", "r");

  // Check if the file was opened successfully.
  if (meminfo == NULL) {
    perror("Error opening /proc/meminfo");
    exit(1);
  }

  // Read the MemTotal line from the file.
  char line[1024];
  while (fgets(line, sizeof(line), meminfo) != NULL) {
    if (strncmp(line, "MemTotal:", 9) == 0) {
      // Get the total RAM size in kilobytes.
      long totalRAM;
      sscanf(line, "MemTotal: %ld kB", &totalRAM);

      // Convert the total RAM size to bytes.
      long totalRAMBytes = totalRAM * 1024;

      // Close the /proc/meminfo file.
      fclose(meminfo);

      // Return the total RAM size in bytes.
      return totalRAMBytes;
    }
  }

  // The MemTotal line was not found in the file.
  fprintf(stderr, "Error: MemTotal line not found in /proc/meminfo");
  exit(1);
}

// Print the RAM usage in a human-readable format.
void printRAMUsage(long ramUsage) {
  // Convert the RAM usage to megabytes.
  double ramUsageMB = (double)ramUsage / 1024 / 1024;

  // Print the RAM usage in megabytes.
  printf("RAM usage: %.2f MB\n", ramUsageMB);
}

// The main function.
int main() {
  // Get the current RAM usage.
  long ramUsage = getRAMUsage();

  // Print the RAM usage.
  printRAMUsage(ramUsage);

  return 0;
}