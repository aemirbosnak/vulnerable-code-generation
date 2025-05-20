//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: optimized
/*
 * Temperature Monitor Program
 *
 * This program will monitor the temperature of a system
 * and alert the user if the temperature exceeds a certain threshold.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMP 100 // maximum temperature threshold
#define MIN_TEMP 0 // minimum temperature threshold

int main() {
  int temperature; // current temperature
  int prev_temperature; // previous temperature
  int threshold; // temperature threshold
  int i; // loop counter

  // initialize variables
  temperature = 0;
  prev_temperature = 0;
  threshold = 0;
  i = 0;

  // prompt user for temperature threshold
  printf("Enter temperature threshold: ");
  scanf("%d", &threshold);

  // check if threshold is within valid range
  if (threshold < MIN_TEMP || threshold > MAX_TEMP) {
    printf("Invalid temperature threshold\n");
    return 1;
  }

  // monitor temperature
  while (1) {
    // read temperature
    temperature = read_temperature();

    // check if temperature is above threshold
    if (temperature > threshold) {
      printf("Temperature above threshold: %d\n", temperature);

      // wait for user input before exiting
      printf("Press enter to continue...");
      getchar();
      break;
    }

    // check if temperature has changed
    if (temperature != prev_temperature) {
      prev_temperature = temperature;
      i = 0;
    }

    // increment loop counter
    i++;

    // check if loop counter has reached maximum
    if (i > 100) {
      i = 0;
    }
  }

  return 0;
}

int read_temperature() {
  int temperature;

  // read temperature from sensor
  temperature = sensor_read_temperature();

  return temperature;
}

int sensor_read_temperature() {
  int temperature;

  // simulate reading temperature from sensor
  temperature = rand() % 100;

  return temperature;
}