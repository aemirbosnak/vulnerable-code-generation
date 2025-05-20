//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>

// A macro to simplify error checking.
#define CHECK(expr, msg) if (!(expr)) { perror(msg); exit(EXIT_FAILURE); }

// A function to get the current CPU usage.
double get_cpu_usage() {
  // Get the current time.
  struct timeval now;
  CHECK(gettimeofday(&now, NULL) == 0, "gettimeofday");

  // Get the current CPU usage.
  struct rusage usage;
  CHECK(getrusage(RUSAGE_SELF, &usage) == 0, "getrusage");

  // Calculate the CPU usage.
  double user_cpu_time = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
  double system_cpu_time = (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000.0;
  double total_cpu_time = user_cpu_time + system_cpu_time;

  // Get the elapsed time since the program started.
  struct timeval elapsed_time;
  timersub(&now, &now, &elapsed_time);

  // Calculate the CPU usage as a percentage.
  double cpu_usage = total_cpu_time / (double)elapsed_time.tv_sec;

  // Return the CPU usage.
  return cpu_usage;
}

// A function to print the CPU usage.
void print_cpu_usage(double cpu_usage) {
  // Print the CPU usage as a percentage.
  printf("CPU usage: %.2f%%\n", cpu_usage);
}

// A function to sleep for a specified number of seconds.
void sleep_seconds(int seconds) {
  // Sleep for the specified number of seconds.
  sleep(seconds);
}

// The main function.
int main(int argc, char **argv) {
  // Get the number of seconds to sleep for.
  int seconds = 1;
  if (argc > 1) {
    seconds = atoi(argv[1]);
  }

  // Get the initial CPU usage.
  double initial_cpu_usage = get_cpu_usage();

  // Sleep for the specified number of seconds.
  sleep_seconds(seconds);

  // Get the final CPU usage.
  double final_cpu_usage = get_cpu_usage();

  // Calculate the difference between the final and initial CPU usage.
  double cpu_usage_diff = final_cpu_usage - initial_cpu_usage;

  // Print the CPU usage difference.
  print_cpu_usage(cpu_usage_diff);

  // Exit the program.
  return EXIT_SUCCESS;
}