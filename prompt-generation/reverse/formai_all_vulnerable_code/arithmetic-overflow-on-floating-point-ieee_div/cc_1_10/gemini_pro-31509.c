//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Get CPU usage in percentage
float get_cpu_usage() {
  FILE *fp;
  char line[1024];
  float user, nice, system, idle, iowait, irq, softirq, steal;

  // Open /proc/stat file
  fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  // Read the first line of the file
  if (fgets(line, sizeof(line), fp) == NULL) {
    perror("fgets");
    exit(EXIT_FAILURE);
  }

  // Parse the first line of the file
  if (sscanf(line, "cpu %f %f %f %f %f %f %f %f", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal) != 8) {
    perror("sscanf");
    exit(EXIT_FAILURE);
  }

  // Close the file
  fclose(fp);

  // Calculate CPU usage
  float total = user + nice + system + idle + iowait + irq + softirq + steal;
  float usage = (user + nice + system) / total * 100;

  return usage;
}

int main() {
  // Get CPU usage every second
  while (1) {
    float usage = get_cpu_usage();

    // Print CPU usage
    printf("CPU usage: %.2f%%\n", usage);

    // Sleep for 1 second
    sleep(1);
  }

  return 0;
}