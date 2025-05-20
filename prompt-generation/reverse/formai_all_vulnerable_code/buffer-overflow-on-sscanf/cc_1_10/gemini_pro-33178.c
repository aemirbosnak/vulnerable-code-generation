//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// Calculate the CPU usage as a percentage
double get_cpu_usage() {
  FILE *fp;
  char buf[1024];
  unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

  // Open the file that contains the CPU usage information
  fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    perror("Failed to open /proc/stat");
    exit(1);
  }

  // Read the first line of the file
  fgets(buf, sizeof(buf), fp);

  // Extract the CPU usage information from the line
  sscanf(buf, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

  // Calculate the total CPU usage
  unsigned long long total = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;

  // Calculate the CPU usage as a percentage
  double usage = (double)(user + nice + system + softirq + steal) / total * 100.0;

  // Close the file
  fclose(fp);

  // Return the CPU usage
  return usage;
}

// Print the CPU usage to the console
void print_cpu_usage(double usage) {
  printf("CPU usage: %.2f%%\n", usage);
}

// Main function
int main() {
  // Get the CPU usage
  double usage = get_cpu_usage();

  // Print the CPU usage to the console
  print_cpu_usage(usage);

  return 0;
}