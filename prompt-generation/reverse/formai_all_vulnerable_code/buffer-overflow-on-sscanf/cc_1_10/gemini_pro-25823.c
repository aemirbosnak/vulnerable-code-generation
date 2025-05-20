//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Neon-infused CPU utilization monitor
//
// This program provides a futuristic visualization of the CPU utilization. It
// utilizes the power of the neon lights to display the usage in a captivating
// and immersive manner. As the CPU utilization increases, the neon lights
// illuminate with greater intensity and frequency, reflecting the pulsating
// rhythm of the system's workload.

// Define the neon light colors
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

// Define the neon light patterns
#define SOLID   "##########"
#define DASHED   "--- --- ---"
#define DOTTED   ". . . . . ."

// Define the CPU utilization levels
#define LOW     0.0
#define MEDIUM  0.5
#define HIGH    1.0

// Get the CPU utilization
double get_cpu_utilization() {
  // Open the file containing the CPU utilization information
  FILE *fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    perror("Error opening /proc/stat");
    exit(1);
  }

  // Read the first line of the file
  char line[1024];
  if (fgets(line, sizeof(line), fp) == NULL) {
    perror("Error reading /proc/stat");
    exit(1);
  }

  // Close the file
  fclose(fp);

  // Parse the line to get the CPU utilization
  char *ptr = line;
  double user, nice, system, idle, iowait, irq, softirq;
  if (sscanf(ptr, "cpu %lf %lf %lf %lf %lf %lf %lf", &user, &nice, &system, &idle, &iowait, &irq, &softirq) != 7) {
    perror("Error parsing /proc/stat");
    exit(1);
  }

  // Calculate the CPU utilization
  double total = user + nice + system + idle + iowait + irq + softirq;
  double utilization = (total - idle) / total;

  return utilization;
}

// Display the neon light visualization
void display_neon_light(double utilization) {
  // Clear the screen
  system("clear");

  // Set the neon light color
  char *color;
  if (utilization < LOW) {
    color = GREEN;
  } else if (utilization < MEDIUM) {
    color = YELLOW;
  } else {
    color = RED;
  }

  // Set the neon light pattern
  char *pattern;
  if (utilization < LOW) {
    pattern = SOLID;
  } else if (utilization < MEDIUM) {
    pattern = DASHED;
  } else {
    pattern = DOTTED;
  }

  // Print the neon light visualization
  for (int i = 0; i < 100; i++) {
    printf("%s%s%s\n", color, pattern, WHITE);
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Loop forever
  while (1) {
    // Get the CPU utilization
    double utilization = get_cpu_utilization();

    // Display the neon light visualization
    display_neon_light(utilization);

    // Sleep for a bit
    sleep(1);
  }

  return 0;
}