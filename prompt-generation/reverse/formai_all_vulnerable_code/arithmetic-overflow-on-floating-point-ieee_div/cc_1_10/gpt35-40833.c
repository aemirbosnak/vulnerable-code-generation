//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SLEEP_TIME 1 // Update interval in seconds

float get_cpu_usage();
void print_cpu_usage(float cpu_usage);

int main(int argc, char *argv[]) {
  while (1) {
    float cpu_usage = get_cpu_usage();
    print_cpu_usage(cpu_usage);
    sleep(SLEEP_TIME);
  }

  return EXIT_SUCCESS;
}

float get_cpu_usage() {
  static long prev_total_time = 0;
  static long prev_idle_time = 0;

  char buffer[BUFFER_SIZE];
  long user_time, nice_time, system_time, idle_time;
  long total_time, diff_total_time, diff_idle_time;
 
  FILE *fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening /proc/stat\n");
    exit(EXIT_FAILURE);
  }

  fgets(buffer, BUFFER_SIZE, fp);
  sscanf(buffer, "cpu %ld %ld %ld %ld", &user_time, &nice_time, &system_time, &idle_time);
  fclose(fp);

  total_time = user_time + nice_time + system_time + idle_time;
  diff_total_time = total_time - prev_total_time;
  diff_idle_time = idle_time - prev_idle_time;

  prev_total_time = total_time;
  prev_idle_time = idle_time;

  return (1.0 - (diff_idle_time * 1.0 / diff_total_time)) * 100.0;
}

void print_cpu_usage(float cpu_usage) {
  char bar[10];
  int i, bar_length = (int)cpu_usage / 10;

  printf("CPU Usage: %0.1f%% [", cpu_usage);

  for (i = 0; i < 10; i++) {
    bar[i] = (i <= bar_length) ? '#' : ' ';
  }

  printf("%s]\n", bar);
}