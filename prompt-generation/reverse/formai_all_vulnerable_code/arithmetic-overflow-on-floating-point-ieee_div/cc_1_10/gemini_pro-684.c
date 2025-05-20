//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// This function generates a random number between 0 and 1.
double get_random() {
  return (double)rand() / (double)RAND_MAX;
}

// This function simulates a CPU-intensive task.
void do_work() {
  // Get a random number.
  double r = get_random();

  // Sleep for a random amount of time.
  usleep((int)(r * 100000));
}

// This function monitors the CPU usage.
void monitor_cpu() {
  // Get the current time.
  time_t current_time = time(NULL);

  // Get the CPU usage for the last second.
  double cpu_usage = sysconf(_SC_CLK_TCK) / (double)clock();

  // Print the CPU usage.
  printf("CPU usage: %f%%\r", cpu_usage * 100);

  // Sleep for a second.
  sleep(1);

  // Get the current time again.
  time_t new_time = time(NULL);

  // If the current time is different from the previous time, then update the CPU usage.
  if (new_time != current_time) {
    monitor_cpu();
  }
}

int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Monitor the CPU usage.
  monitor_cpu();

  return 0;
}