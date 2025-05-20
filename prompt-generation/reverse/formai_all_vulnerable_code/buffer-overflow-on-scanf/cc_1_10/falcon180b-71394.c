//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// Global variables
int numSensors;
float *sensorReading;
char *sensorName;
int *sensorStatus;
int main() {
  // Initialize variables
  numSensors = 0;
  sensorReading = NULL;
  sensorName = NULL;
  sensorStatus = NULL;

  // Read in the number of sensors
  printf("Enter the number of sensors: ");
  scanf("%d", &numSensors);

  // Allocate memory for sensor data
  sensorReading = (float *)malloc(numSensors * sizeof(float));
  sensorName = (char *)malloc(numSensors * sizeof(char));
  sensorStatus = (int *)malloc(numSensors * sizeof(int));

  // Read in sensor data
  for (int i = 0; i < numSensors; i++) {
    printf("Enter the name of sensor %d: ", i + 1);
    scanf("%s", sensorName + i * sizeof(char));
    printf("Enter the initial temperature reading for sensor %s: ", sensorName + i * sizeof(char));
    scanf("%f", &sensorReading[i]);
    printf("Is sensor %s currently active? (1 for yes, 0 for no): ", sensorName + i * sizeof(char));
    scanf("%d", &sensorStatus[i]);
  }

  // Main loop for monitoring sensors
  while (TRUE) {
    // Read in current time
    struct tm *currentTime;
    time_t now;
    time(&now);
    currentTime = localtime(&now);

    // Print current time and date
    printf("\nCurrent time and date: %s", asctime(currentTime));

    // Print header for sensor data
    printf("\nSensor\tReading (C)\tStatus\n");

    // Loop through sensors and print data
    for (int i = 0; i < numSensors; i++) {
      printf("%s\t%.2f\t%d\n", sensorName + i * sizeof(char), sensorReading[i], sensorStatus[i]);
    }

    // Wait for 5 seconds before looping again
    sleep(5);
  }

  // Free memory
  free(sensorReading);
  free(sensorName);
  free(sensorStatus);

  return 0;
}