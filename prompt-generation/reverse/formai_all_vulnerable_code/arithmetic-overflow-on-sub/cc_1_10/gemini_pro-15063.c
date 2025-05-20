//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the temperature sensor readings
#define TEMP_MIN 0
#define TEMP_MAX 100
#define TEMP_WARNING 90

// Define the threshold for sending an alert
#define ALERT_THRESHOLD_TEMP 95

// Define the number of seconds to wait between readings
#define READING_INTERVAL 5

// Initialize the temperature sensor readings
int temperature = 0;

// Initialize the alert status
bool alert = false;

// Initialize the time of the last reading
time_t last_reading = 0;

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Main loop
  while (true) {
    // Get the current time
    time_t current_time = time(NULL);

    // Check if it is time to take a new reading
    if (current_time - last_reading >= READING_INTERVAL) {
      // Generate a random temperature reading
      temperature = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;

      // Update the time of the last reading
      last_reading = current_time;

      // Check if the temperature is above the warning threshold
      if (temperature >= TEMP_WARNING) {
        // Set the alert status to true
        alert = true;
      }

      // Check if the temperature is above the alert threshold
      if (temperature >= ALERT_THRESHOLD_TEMP) {
        // Send an alert
        printf("ALERT: Temperature has reached %d degrees Celsius.\n", temperature);
      }
    }

    // Print the current temperature
    printf("Current temperature: %d degrees Celsius.\n", temperature);

    // Print the alert status
    if (alert) {
      printf("ALERT: Temperature is above the warning threshold.\n");
    } else {
      printf("No alert.\n");
    }

    // Sleep for a second
    sleep(1);
  }

  return 0;
}