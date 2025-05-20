//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of samples to collect
#define NUM_SAMPLES 100

// Define the sleep time between samples in milliseconds
#define SLEEP_TIME 100

// Define the maximum CPU usage percentage
#define MAX_CPU_USAGE 100

// Create an array to store the CPU usage samples
float cpu_usage[NUM_SAMPLES];

// Get the CPU usage percentage
float get_cpu_usage() {
  // Open the /proc/stat file
  FILE *fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    perror("Error opening /proc/stat");
    exit(EXIT_FAILURE);
  }

  // Read the first line of the /proc/stat file
  char line[1024];
  if (fgets(line, sizeof(line), fp) == NULL) {
    perror("Error reading /proc/stat");
    exit(EXIT_FAILURE);
  }

  // Close the /proc/stat file
  fclose(fp);

  // Parse the first line of the /proc/stat file
  char *ptr = line;
  int user, nice, system, idle, iowait, irq, softirq;
  if (sscanf(ptr, "cpu %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq) != 7) {
    perror("Error parsing /proc/stat");
    exit(EXIT_FAILURE);
  }

  // Calculate the CPU usage percentage
  float cpu_usage = 100.0 * (user + nice + system + irq + softirq) / (user + nice + system + idle + iowait + irq + softirq);

  // Return the CPU usage percentage
  return cpu_usage;
}

// Collect the CPU usage samples
void collect_cpu_usage_samples() {
  // Collect the CPU usage samples
  for (int i = 0; i < NUM_SAMPLES; i++) {
    cpu_usage[i] = get_cpu_usage();

    // Sleep for a short period of time
    usleep(SLEEP_TIME * 1000);
  }
}

// Calculate the mean CPU usage
float calculate_mean_cpu_usage() {
  // Calculate the mean CPU usage
  float mean_cpu_usage = 0.0;
  for (int i = 0; i < NUM_SAMPLES; i++) {
    mean_cpu_usage += cpu_usage[i];
  }
  mean_cpu_usage /= NUM_SAMPLES;

  // Return the mean CPU usage
  return mean_cpu_usage;
}

// Calculate the standard deviation of the CPU usage
float calculate_standard_deviation_cpu_usage() {
  // Calculate the standard deviation of the CPU usage
  float standard_deviation_cpu_usage = 0.0;
  for (int i = 0; i < NUM_SAMPLES; i++) {
    standard_deviation_cpu_usage += pow(cpu_usage[i] - calculate_mean_cpu_usage(), 2);
  }
  standard_deviation_cpu_usage /= NUM_SAMPLES;
  standard_deviation_cpu_usage = sqrt(standard_deviation_cpu_usage);

  // Return the standard deviation of the CPU usage
  return standard_deviation_cpu_usage;
}

// Print the CPU usage statistics
void print_cpu_usage_statistics() {
  // Print the CPU usage statistics
  printf("CPU Usage Statistics:\n");
  printf("Mean CPU Usage: %.2f%%\n", calculate_mean_cpu_usage());
  printf("Standard Deviation of CPU Usage: %.2f%%\n", calculate_standard_deviation_cpu_usage());
  printf("Maximum CPU Usage: %.2f%%\n", MAX_CPU_USAGE);
}

// Main function
int main() {
  // Collect the CPU usage samples
  collect_cpu_usage_samples();

  // Calculate the CPU usage statistics
  print_cpu_usage_statistics();

  return 0;
}