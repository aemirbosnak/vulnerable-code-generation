//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Include the necessary headers for RAM usage monitoring.
#ifdef __linux__
#include <sys/resource.h>
#elif __APPLE__
#include <mach/mach.h>
#endif

// Define a function to get the current RAM usage in bytes.
#ifdef __linux__
static unsigned long long getRAMUsage() {
  struct rusage usage;
  if (getrusage(RUSAGE_SELF, &usage) == 0) {
    return usage.ru_maxrss * 1024;
  } else {
    return 0;
  }
}
#elif __APPLE__
static unsigned long long getRAMUsage() {
  task_basic_info_data_t info;
  mach_msg_type_number_t count = TASK_BASIC_INFO_COUNT;
  if (task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&info, &count) == KERN_SUCCESS) {
    return info.resident_size;
  } else {
    return 0;
  }
}
#endif

// Define a function to print the RAM usage to the console.
static void printRAMUsage() {
  unsigned long long ramUsage = getRAMUsage();
  printf("Current RAM usage: %llu bytes\n", ramUsage);
}

// The main function.
int main() {
  // Print the initial RAM usage.
  printRAMUsage();

  // Allocate a large block of memory.
  unsigned long long *array = malloc(1000000000);

  // Print the RAM usage after allocating the memory.
  printRAMUsage();

  // Free the allocated memory.
  free(array);

  // Print the RAM usage after freeing the memory.
  printRAMUsage();

  return 0;
}