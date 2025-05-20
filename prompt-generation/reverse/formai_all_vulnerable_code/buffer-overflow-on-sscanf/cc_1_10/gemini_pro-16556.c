//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define the colors for the RAM usage bar
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RED "\033[31m"
#define COLOR_RESET "\033[0m"

// Get the RAM usage from the system
int get_ram_usage() {
  // Open the file containing the RAM usage information
  FILE *fp = fopen("/proc/meminfo", "r");
  if (fp == NULL) {
    perror("Error opening /proc/meminfo");
    return -1;
  }

  // Read the first line of the file, which contains the total RAM usage
  char line[1024];
  if (fgets(line, sizeof(line), fp) == NULL) {
    perror("Error reading /proc/meminfo");
    fclose(fp);
    return -1;
  }

  // Close the file
  fclose(fp);

  // Parse the total RAM usage from the line
  int total_ram;
  if (sscanf(line, "MemTotal: %d kB", &total_ram) != 1) {
    fprintf(stderr, "Error parsing /proc/meminfo");
    return -1;
  }

  // Return the total RAM usage
  return total_ram;
}

// Print the RAM usage bar
void print_ram_usage_bar(int ram_usage) {
  // Calculate the percentage of RAM that is being used
  double percentage = (double)ram_usage / 1024 / 1024 * 100;

  // Print the bar
  printf("[");
  for (int i = 0; i < 100; i++) {
    if (i < percentage) {
      printf(COLOR_GREEN "=");
    } else if (i < percentage + 10) {
      printf(COLOR_YELLOW "=");
    } else {
      printf(COLOR_RED "=");
    }
  }
  printf("] %.2f%%\n", percentage);

  // Reset the color
  printf(COLOR_RESET);
}

// Main function
int main() {
  // Get the RAM usage
  int ram_usage = get_ram_usage();
  if (ram_usage == -1) {
    return 1;
  }

  // Print the RAM usage bar
  print_ram_usage_bar(ram_usage);

  return 0;
}