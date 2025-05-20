//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: genius
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

#define CPU_USAGE_FILE "/tmp/cpu_usage.txt"

int main() {
  FILE *fp;
  char line[256];
  int cpu_usage = 0;
  int total_usage = 0;
  int i = 0;

  // Create a temporary file to store CPU usage
  fp = fopen(CPU_USAGE_FILE, "w");
  fclose(fp);

  // Loop to get CPU usage
  while (1) {
    // Get the CPU usage from the system
    cpu_usage = get_cpu_usage();

    // Write the CPU usage to the file
    fp = fopen(CPU_USAGE_FILE, "a");
    fprintf(fp, "%d\n", cpu_usage);
    fclose(fp);

    // Calculate the total usage
    total_usage += cpu_usage;

    // Print the total usage
    printf("Total CPU usage: %d%\n", total_usage);

    // Sleep for a while
    sleep(1);
  }

  return 0;
}

int get_cpu_usage() {
  FILE *fp;
  char line[256];
  int cpu_usage = 0;

  fp = fopen("/proc/stat", "r");
  fscanf(fp, "%s %s %s", line, line, line);
  fclose(fp);

  cpu_usage = atoi(line);

  return cpu_usage;
}