//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Get the system's CPU usage
  FILE *fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    perror("Error opening /proc/stat");
    return EXIT_FAILURE;
  }

  char line[1024];
  if (fgets(line, sizeof(line), fp) == NULL) {
    perror("Error reading /proc/stat");
    fclose(fp);
    return EXIT_FAILURE;
  }

  fclose(fp);

  // Parse the first line of /proc/stat
  char *token;
  token = strtok(line, " ");
  while (token != NULL) {
    if (strcmp(token, "cpu") == 0) {
      break;
    }
    token = strtok(NULL, " ");
  }

  // Get the user, nice, system, idle, and iowait CPU times
  long long user, nice, system, idle, iowait;
  user = strtoll(token, NULL, 10);
  token = strtok(NULL, " ");
  nice = strtoll(token, NULL, 10);
  token = strtok(NULL, " ");
  system = strtoll(token, NULL, 10);
  token = strtok(NULL, " ");
  idle = strtoll(token, NULL, 10);
  token = strtok(NULL, " ");
  iowait = strtoll(token, NULL, 10);

  // Calculate the total CPU time
  long long total = user + nice + system + idle + iowait;

  // Calculate the percentage of CPU time that is idle
  double idle_percent = (double)idle / total * 100;

  // Print the CPU usage
  printf("CPU usage: %.2f%%\n", idle_percent);

  return EXIT_SUCCESS;
}