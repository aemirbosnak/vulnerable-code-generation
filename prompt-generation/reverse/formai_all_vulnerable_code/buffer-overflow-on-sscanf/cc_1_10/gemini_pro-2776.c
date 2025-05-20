//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define PAGE_SIZE 4096

// Function to calculate the RAM usage
unsigned long long get_ram_usage() {
  FILE *fp;
  char buffer[PAGE_SIZE];
  unsigned long long ram_usage = 0;
  
  // Open the /proc/meminfo file
  fp = fopen("/proc/meminfo", "r");
  if (fp == NULL) {
    perror("Error opening /proc/meminfo");
    exit(EXIT_FAILURE);
  }
  
  // Read the file line by line
  while (fgets(buffer, PAGE_SIZE, fp) != NULL) {
    // Check if the line contains the "MemTotal" or "MemFree" field
    if (strncmp(buffer, "MemTotal:", 9) == 0 || strncmp(buffer, "MemFree:", 8) == 0) {
      // Extract the numerical value from the line
      unsigned long long value;
      sscanf(buffer, "%llu", &value);
      
      // Add the value to the RAM usage
      if (strncmp(buffer, "MemTotal:", 9) == 0) {
        ram_usage += value;
      } else if (strncmp(buffer, "MemFree:", 8) == 0) {
        ram_usage -= value;
      }
    }
  }
  
  // Close the file
  fclose(fp);
  
  // Return the RAM usage
  return ram_usage;
}

// Main function
int main() {
  // Get the RAM usage
  unsigned long long ram_usage = get_ram_usage();
  
  // Print the RAM usage
  printf("RAM usage: %llu bytes\n", ram_usage);
  
  // Return 0
  return 0;
}