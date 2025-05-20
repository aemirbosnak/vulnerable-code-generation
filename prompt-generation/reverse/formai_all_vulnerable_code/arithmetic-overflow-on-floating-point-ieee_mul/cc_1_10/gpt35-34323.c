//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to get cpu usage
double getCpuUsage() {
  FILE* file;
  char* line;
  size_t len = 0;
  ssize_t read;
  double cpuUsage = 0;
  long double user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice;

  // open stat file and read cpu usage stats
  file = fopen("/proc/stat", "r");
  if (file) {
    if ((read = getline(&line, &len, file)) != -1) {
      sscanf(line, "%*s %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
      long double prevIdle = idle + iowait;
      long double prevNonIdle = user + nice + sys + irq + softirq + steal;
      long double prevTotal = prevIdle + prevNonIdle;

      // wait for 1 second
      sleep(1);

      rewind(file);
      len = 0;
      if ((read = getline(&line, &len, file)) != -1) {
        sscanf(line, "%*s %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf %Lf", &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
        long double curIdle = idle + iowait;
        long double curNonIdle = user + nice + sys + irq + softirq + steal;
        long double curTotal = curIdle + curNonIdle;

        // calculate the average cpu usage
        long double totald = curTotal - prevTotal;
        long double idled = curIdle - prevIdle;
        cpuUsage = ((totald - idled) / totald) * 100;
      }
    }
    fclose(file);
  }
  return cpuUsage;
}

int main() {
  while (1) {
    double cpuUsage = getCpuUsage();
    printf("Current CPU Usage: %.2f%%\n", cpuUsage);
  }
  return 0;
}