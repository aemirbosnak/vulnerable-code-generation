//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>

#define STAT_FILE "/proc/stat"

int main() {
  FILE *f;
  char line[256];
  char *p;
  double user, nice, system, idle, iowait, irq, softirq;
  double prev_user, prev_nice, prev_system, prev_idle, prev_iowait, prev_irq, prev_softirq;
  unsigned int ticks, prev_ticks;
  double cpu_usage;

  // Open the /proc/stat file
  f = fopen(STAT_FILE, "r");
  if (f == NULL) {
    perror("fopen");
    exit(1);
  }

  // Read the first line of the file
  if (fgets(line, sizeof(line), f) == NULL) {
    perror("fgets");
    exit(1);
  }

  // Parse the first line of the file
  p = strtok(line, " ");
  while (p != NULL) {
    if (strcmp(p, "user") == 0) {
      user = atof(strtok(NULL, " "));
    } else if (strcmp(p, "nice") == 0) {
      nice = atof(strtok(NULL, " "));
    } else if (strcmp(p, "system") == 0) {
      system = atof(strtok(NULL, " "));
    } else if (strcmp(p, "idle") == 0) {
      idle = atof(strtok(NULL, " "));
    } else if (strcmp(p, "iowait") == 0) {
      iowait = atof(strtok(NULL, " "));
    } else if (strcmp(p, "irq") == 0) {
      irq = atof(strtok(NULL, " "));
    } else if (strcmp(p, "softirq") == 0) {
      softirq = atof(strtok(NULL, " "));
    }
    p = strtok(NULL, " ");
  }

  // Get the total number of ticks
  ticks = user + nice + system + idle + iowait + irq + softirq;

  // Save the previous values
  prev_user = user;
  prev_nice = nice;
  prev_system = system;
  prev_idle = idle;
  prev_iowait = iowait;
  prev_irq = irq;
  prev_softirq = softirq;
  prev_ticks = ticks;

  // Sleep for 1 second
  sleep(1);

  // Read the first line of the file again
  if (fgets(line, sizeof(line), f) == NULL) {
    perror("fgets");
    exit(1);
  }

  // Parse the first line of the file again
  p = strtok(line, " ");
  while (p != NULL) {
    if (strcmp(p, "user") == 0) {
      user = atof(strtok(NULL, " "));
    } else if (strcmp(p, "nice") == 0) {
      nice = atof(strtok(NULL, " "));
    } else if (strcmp(p, "system") == 0) {
      system = atof(strtok(NULL, " "));
    } else if (strcmp(p, "idle") == 0) {
      idle = atof(strtok(NULL, " "));
    } else if (strcmp(p, "iowait") == 0) {
      iowait = atof(strtok(NULL, " "));
    } else if (strcmp(p, "irq") == 0) {
      irq = atof(strtok(NULL, " "));
    } else if (strcmp(p, "softirq") == 0) {
      softirq = atof(strtok(NULL, " "));
    }
    p = strtok(NULL, " ");
  }

  // Get the total number of ticks again
  ticks = user + nice + system + idle + iowait + irq + softirq;

  // Calculate the CPU usage
  cpu_usage = 100.0 * ((ticks - prev_ticks) - (idle - prev_idle)) / (ticks - prev_ticks);

  // Print the CPU usage
  printf("CPU usage: %.2f%%\n", cpu_usage);

  // Close the /proc/stat file
  fclose(f);

  return 0;
}