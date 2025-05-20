//FormAI DATASET v1.0 Category: Temperature monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUM_TEMPERATURES 100

int main() {
  float temperature[MAX_NUM_TEMPERATURES];
  int numTemperatures = 0;
  float aveTemperature = 0.0;

  while(numTemperatures < MAX_NUM_TEMPERATURES) {
    printf("Please enter a temperature value in Celsius (or enter 'q' to quit): ");
    char input[10];
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-1] = '\0';

    if(strcmp(input, "q") == 0) {
      break;
    }

    float t = atof(input);

    if(t < -273.15) {
      printf("Invalid temperature! The temperature cannot be less than -273.15 Celsius (absolute zero).\n");
      continue;
    }

    temperature[numTemperatures] = t;
    numTemperatures++;
    aveTemperature += t;
  }

  if(numTemperatures == 0) {
    printf("No temperatures entered.\n");
    return 0;
  }

  aveTemperature /= numTemperatures;
  printf("Number of temperatures entered: %d\n", numTemperatures);
  printf("Average temperature: %.2f Celsius\n", aveTemperature);

  // Determine the minimum and maximum temperatures
  float minTemperature = temperature[0], maxTemperature = temperature[0];

  for(int i = 1; i < numTemperatures; i++) {
    if(temperature[i] < minTemperature) {
      minTemperature = temperature[i];
    }
    if(temperature[i] > maxTemperature) {
      maxTemperature = temperature[i];
    }
  }

  printf("Minimum temperature: %.2f Celsius\n", minTemperature);
  printf("Maximum temperature: %.2f Celsius\n", maxTemperature);

  // Generate a random time string
  time_t t;
  srand((unsigned) time(&t));
  int randomHour = rand() % 24;
  int randomMinute = rand() % 60;
  
  char currentTime[10];
  sprintf(currentTime, "%02d:%02d", randomHour, randomMinute);
  
  printf("Time: %s\n", currentTime);

  // Determine whether the temperature is within the acceptable range
  bool isTemperatureAcceptable = true;

  for(int i = 0; i < numTemperatures; i++) {
    if(temperature[i] < 19.0 || temperature[i] > 21.0) {
      isTemperatureAcceptable = false;
      break;
    }
  }

  if(isTemperatureAcceptable) {
    printf("Temperature is within the acceptable range.\n");
  } else {
    printf("Temperature is NOT within the acceptable range.\n");
  }

  return 0;
}