//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Declare function to get RAM usage
unsigned long get_ram_usage(void);

// Declare function to print RAM usage in human-readable format
void print_ram_usage(unsigned long ram_usage);

// Declare function to recursively check RAM usage
void check_ram_usage(int count) {
  // Get current RAM usage
  unsigned long ram_usage = get_ram_usage();

  // Print RAM usage
  print_ram_usage(ram_usage);

  // Check if RAM usage is above a certain threshold
  if (ram_usage > 100000000) {
    // If RAM usage is above threshold, print a warning message
    printf("Warning: RAM usage is high!\n");
  }

  // Recursively call check_ram_usage() function with count + 1
  check_ram_usage(count + 1);
}

// Define main function
int main(void) {
  // Call check_ram_usage() function with count 0
  check_ram_usage(0);

  return 0;
}

// Define get_ram_usage() function
unsigned long get_ram_usage(void) {
  // Declare file pointer
  FILE *fp;

  // Open /proc/self/status file
  fp = fopen("/proc/self/status", "r");

  // Check if file pointer is valid
  if (fp == NULL) {
    // If file pointer is not valid, return 0
    return 0;
  }

  // Read a line from the file
  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Check if line starts with "VmRSS:"
    if (strncmp(line, "VmRSS:", 6) == 0) {
      // If line starts with "VmRSS:", parse RAM usage
      unsigned long ram_usage;
      sscanf(line, "VmRSS: %lu kB", &ram_usage);

      // Close file pointer
      fclose(fp);

      // Return RAM usage
      return ram_usage;
    }
  }

  // Close file pointer
  fclose(fp);

  // Return 0 if RAM usage could not be parsed
  return 0;
}

// Define print_ram_usage() function
void print_ram_usage(unsigned long ram_usage) {
  // Print RAM usage in human-readable format
  printf("RAM usage: %lu MB\n", ram_usage / 1024 / 1024);
}