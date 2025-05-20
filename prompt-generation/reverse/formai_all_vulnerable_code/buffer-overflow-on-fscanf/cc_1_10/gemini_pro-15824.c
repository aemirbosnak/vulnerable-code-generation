//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the temperature sensor file path
#define TEMP_SENSOR_FILE "/sys/class/thermal/thermal_zone0/temp"

// Define the temperature threshold
#define TEMP_THRESHOLD 85

// Define the alert message
#define ALERT_MESSAGE "Temperature exceeded threshold!"

// Define the delay between temperature readings (in milliseconds)
#define DELAY 1000

// Main function
int main() {
  // Open the temperature sensor file
  FILE *temp_file = fopen(TEMP_SENSOR_FILE, "r");
  if (temp_file == NULL) {
    fprintf(stderr, "Error opening temperature sensor file\n");
    return EXIT_FAILURE;
  }

  // Initialize the temperature variable
  int temp;

  // Main loop
  while (1) {
    // Read the temperature from the sensor file
    fscanf(temp_file, "%d", &temp);

    // Check if the temperature has exceeded the threshold
    if (temp > TEMP_THRESHOLD) {
      // Print the alert message
      printf("%s\n", ALERT_MESSAGE);

      // Send an email or SMS alert (not implemented in this example)
      // ...

      // Break out of the loop
      break;
    }

    // Delay before reading the temperature again
    usleep(DELAY * 1000);
  }

  // Close the temperature sensor file
  fclose(temp_file);

  return EXIT_SUCCESS;
}