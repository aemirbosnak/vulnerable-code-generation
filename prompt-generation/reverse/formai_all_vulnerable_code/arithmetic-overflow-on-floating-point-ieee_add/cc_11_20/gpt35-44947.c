//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_READINGS 1000

int main() {
  float readings[MAX_READINGS];
  int numReadings = 0;
  float total = 0;
  float minValue = 0;
  float maxValue = 0;

  printf("C Temperature Monitor\n");
  printf("Enter temperature readings, one per line, followed by 'exit':\n");

  char line[256];
  while (fgets(line, sizeof(line), stdin)) {
    if (line[0] == 'e' && line[1] == 'x' && line[2] == 'i' && line[3] == 't') {
      break;
    }
    float temp = strtof(line, NULL);
    if (temp < -273.15f) {
      printf("Invalid reading: temperature cannot be below -273.15C\n");
      continue;
    }
    if (numReadings == 0 || temp < minValue) {
      minValue = temp;
    }
    if (numReadings == 0 || temp > maxValue) {
      maxValue = temp;
    }
    total += temp;
    readings[numReadings++] = temp;
    if (numReadings >= MAX_READINGS) {
      printf("Maximum number of readings reached\n");
      break;
    }
  }

  if (numReadings == 0) {
    printf("No readings entered\n");
    return EXIT_SUCCESS;
  }

  float average = total / numReadings;

  printf("\nNumber of readings: %d\n", numReadings);
  printf("Maximum temperature: %.2fC\n", maxValue);
  printf("Minimum temperature: %.2fC\n", minValue);
  printf("Average temperature: %.2fC\n", average);

  for (int i = numReadings - 1; i >= 0; i--) {
      float deviation = readings[i] - average;
      printf("Reading %d: %.2fC (%.2fC%s)\n", i+1, readings[i], deviation, deviation > 0 ? " above average" : deviation < 0 ? " below average" : "");
  }

  return EXIT_SUCCESS;
}