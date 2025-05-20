//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

// Define the number of samples to collect
#define NUM_SAMPLES 100

// Define the interval between samples (in milliseconds)
#define SAMPLE_INTERVAL 100

// Get the current CPU usage
double get_cpu_usage() {
  // Get the current time
  struct timeval time;
  gettimeofday(&time, NULL);

  // Get the current CPU usage
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);

  // Calculate the CPU usage percentage
  double cpu_usage = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
  cpu_usage += (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000.0;
  cpu_usage /= (double)time.tv_sec + (double)time.tv_usec / 1000000.0;
  cpu_usage *= 100.0;

  return cpu_usage;
}

// Print the CPU usage statistics
void print_cpu_usage_stats(double *samples) {
  // Calculate the mean CPU usage
  double mean = 0.0;
  for (int i = 0; i < NUM_SAMPLES; i++) {
    mean += samples[i];
  }
  mean /= NUM_SAMPLES;

  // Calculate the standard deviation of the CPU usage
  double stddev = 0.0;
  for (int i = 0; i < NUM_SAMPLES; i++) {
    stddev += (samples[i] - mean) * (samples[i] - mean);
  }
  stddev = sqrt(stddev / (NUM_SAMPLES - 1));

  // Print the CPU usage statistics
  printf("CPU usage statistics:\n");
  printf("  Mean: %.2f%%\n", mean);
  printf("  Standard deviation: %.2f%%\n", stddev);
}

int main() {
  // Get the CPU usage samples
  double samples[NUM_SAMPLES];
  for (int i = 0; i < NUM_SAMPLES; i++) {
    samples[i] = get_cpu_usage();
    usleep(SAMPLE_INTERVAL * 1000);
  }

  // Print the CPU usage statistics
  print_cpu_usage_stats(samples);

  return 0;
}