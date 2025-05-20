//FormAI DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UPPER_TEMP_LIMIT 120
#define LOWER_TEMP_LIMIT 0

bool isTemperatureValid(float temp) {
  if(temp < LOWER_TEMP_LIMIT || temp > UPPER_TEMP_LIMIT) {
    printf("Invalid temperature reading. Ensure that the temperature is within %d and %d \n", LOWER_TEMP_LIMIT, UPPER_TEMP_LIMIT);
    return false;
  }
  return true;
}

int main() {
  float temperature[24];
  float average, max_temperature = -1000, min_temperature = 10000;
  int i, size = 0, overheat_count = 0;

  printf("----------------- WELCOME TO THE TEMPERATURE MONITOR ----------------------\n");

  while (true) {
    printf("Enter the temperature reading for hour %d (Enter -1000 to end) : ", size + 1);
    scanf("%f", &temperature[size]);

    if(temperature[size] == -1000) {
      printf("Stopping data input...\n");
      break;
    }

    if(isTemperatureValid(temperature[size])) {
      if(temperature[size] > max_temperature) {
        max_temperature = temperature[size];
      }

      if(temperature[size] < min_temperature) {
        min_temperature = temperature[size];
      }

      if(temperature[size] > UPPER_TEMP_LIMIT) {
        overheat_count++;
      }

      size++;
      average += temperature[size];
    }
  }

  if(size > 0) {
    average /= size;
    printf("\nTotal number of valid temperature readings: %d\n", size);
    printf("The maximum temperature is %.2f degrees Celsius.\n", max_temperature);
    printf("The minimum temperature is %.2f degrees Celsius.\n", min_temperature);
    printf("The average temperature is %.2f degrees Celsius.\n", average);
    printf("Total number of hours in which the temperature exceeded the safe limit(120'C): %d\n", overheat_count);
  } else {
    printf("No valid temperature readings were given.\n");
  }

  printf("\n---------------- END OF TEMPERATURE MONITOR ----------------------------\n");
  return 0;
}