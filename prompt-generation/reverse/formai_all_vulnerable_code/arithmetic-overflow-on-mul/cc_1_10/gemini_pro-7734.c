//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define some macros to make the code more readable
#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)

// Declare a function to get the current RAM usage
int get_ram_usage() {
  // Open the "/proc/meminfo" file
  FILE *f = fopen("/proc/meminfo", "r");
  if (f == NULL) {
    perror("fopen");
    return -1;
  }

  // Read the first line of the file, which contains the total RAM usage
  char line[1024];
  if (fgets(line, sizeof(line), f) == NULL) {
    perror("fgets");
    fclose(f);
    return -1;
  }

  // Close the file
  fclose(f);

  // Parse the total RAM usage from the first line
  int total_ram_usage;
  if (sscanf(line, "MemTotal: %d kB", &total_ram_usage) != 1) {
    fprintf(stderr, "Error parsing total RAM usage\n");
    return -1;
  }

  // Return the total RAM usage in bytes
  return total_ram_usage * KB;
}

// Declare a function to print the RAM usage
void print_ram_usage(int ram_usage) {
  // Convert the RAM usage to MB and GB
  float ram_usage_mb = (float)ram_usage / MB;
  float ram_usage_gb = ram_usage_mb / GB;

  // Print the RAM usage in MB and GB
  printf("RAM usage: %.2f MB (%.2f GB)\n", ram_usage_mb, ram_usage_gb);
}

int main() {
  // Get the current RAM usage
  int ram_usage = get_ram_usage();
  if (ram_usage == -1) {
    return EXIT_FAILURE;
  }

  // Print the RAM usage
  print_ram_usage(ram_usage);

  return EXIT_SUCCESS;
}