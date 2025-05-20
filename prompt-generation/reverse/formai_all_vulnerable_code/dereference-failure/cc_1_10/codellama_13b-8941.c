//Code Llama-13B DATASET v1.0 Category: CPU usage monitor ; Style: Alan Turing
// CPU Usage Monitor Program in Alan Turing Style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Declare variables
  int cpu_usage, i;
  time_t t;
  struct tm *tm_info;

  // Initialize variables
  cpu_usage = 0;
  i = 0;
  t = time(NULL);
  tm_info = localtime(&t);

  // Print header
  printf("CPU Usage Monitor Program in Alan Turing Style\n");
  printf("----------------------------------------------\n");
  printf("Date: %d-%d-%d\n", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
  printf("Time: %d:%d:%d\n\n", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);

  // Print initial CPU usage
  printf("CPU Usage: %d%%\n\n", cpu_usage);

  // Loop to continuously monitor CPU usage
  while (1) {
    // Get current CPU usage
    cpu_usage = get_cpu_usage();

    // Print current CPU usage
    printf("CPU Usage: %d%%\n", cpu_usage);

    // Sleep for 1 second
    sleep(1);

    // Increment loop counter
    i++;

    // Print number of seconds passed
    printf("Time elapsed: %d seconds\n", i);
  }

  return 0;
}

// Function to get CPU usage
int get_cpu_usage() {
  // Declare variables
  int cpu_usage;
  FILE *fp;

  // Open /proc/stat file
  fp = fopen("/proc/stat", "r");

  // Read CPU usage from file
  fscanf(fp, "%*s %d", &cpu_usage);

  // Close file
  fclose(fp);

  // Return CPU usage
  return cpu_usage;
}