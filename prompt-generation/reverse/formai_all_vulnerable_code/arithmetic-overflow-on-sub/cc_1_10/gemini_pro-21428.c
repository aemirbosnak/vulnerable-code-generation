//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

#define TEMPERATURE_FILE "/sys/class/thermal/thermal_zone0/temp"
#define LOG_FILE "temperature.log"
#define LOG_INTERVAL_SECONDS 60

int main() {
  // Open the temperature file
  int temperature_file = open(TEMPERATURE_FILE, O_RDONLY);
  if (temperature_file < 0) {
    perror("Failed to open temperature file");
    exit(EXIT_FAILURE);
  }

  // Open the log file
  int log_file = open(LOG_FILE, O_WRONLY | O_APPEND | O_CREAT, 0644);
  if (log_file < 0) {
    perror("Failed to open log file");
    exit(EXIT_FAILURE);
  }

  // Get the current time
  time_t current_time = time(NULL);

  // Loop forever, logging the temperature every LOG_INTERVAL_SECONDS seconds
  while (1) {
    // Read the temperature from the file
    char temperature_buffer[16];
    int temperature_bytes = read(temperature_file, temperature_buffer, 15);
    if (temperature_bytes < 0) {
      perror("Failed to read temperature from file");
      exit(EXIT_FAILURE);
    }

    // Convert the temperature to a double
    double temperature = atof(temperature_buffer) / 1000;

    // Get the current time again
    time_t new_time = time(NULL);

    // If the current time is more than LOG_INTERVAL_SECONDS seconds after the last time we logged the temperature, log the temperature
    if (new_time - current_time >= LOG_INTERVAL_SECONDS) {
      // Log the temperature to the file
      char log_buffer[128];
      snprintf(log_buffer, 128, "[%s] Temperature: %.2f°C\n", ctime(&new_time), temperature);
      int log_bytes = write(log_file, log_buffer, strlen(log_buffer));
      if (log_bytes < 0) {
        perror("Failed to write to log file");
        exit(EXIT_FAILURE);
      }

      // Update the current time
      current_time = new_time;
    }

    // Sleep for 1 second
    sleep(1);
  }

  // Close the temperature file
  close(temperature_file);

  // Close the log file
  close(log_file);

  return 0;
}