//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of sensors
#define MAX_SENSORS 10

// Define the structure for each sensor
typedef struct {
    char name[20];
    double temperature;
} Sensor;

// Function to read the sensor data from a file
void readSensorData(Sensor sensors[], FILE *fp) {
    int i = 0;
    while (fscanf(fp, "%s %lf\n", sensors[i].name, &sensors[i].temperature) == 2) {
        i++;
        if (i >= MAX_SENSORS) {
            break;
        }
    }
}

// Function to print the sensor data
void printSensorData(Sensor sensors[], int numSensors) {
    printf("Sensor Name\tTemperature\n");
    for (int i = 0; i < numSensors; i++) {
        printf("%s\t%.2lf\n", sensors[i].name, sensors[i].temperature);
    }
}

// Function to calculate the average temperature
double calculateAverageTemperature(Sensor sensors[], int numSensors) {
    double sum = 0.0;
    for (int i = 0; i < numSensors; i++) {
        sum += sensors[i].temperature;
    }
    return sum / numSensors;
}

// Function to find the highest temperature
double findHighestTemperature(Sensor sensors[], int numSensors) {
    double highestTemp = sensors[0].temperature;
    for (int i = 1; i < numSensors; i++) {
        if (sensors[i].temperature > highestTemp) {
            highestTemp = sensors[i].temperature;
        }
    }
    return highestTemp;
}

// Function to find the lowest temperature
double findLowestTemperature(Sensor sensors[], int numSensors) {
    double lowestTemp = sensors[0].temperature;
    for (int i = 1; i < numSensors; i++) {
        if (sensors[i].temperature < lowestTemp) {
            lowestTemp = sensors[i].temperature;
        }
    }
    return lowestTemp;
}

int main() {
    FILE *fp;
    char filename[50];
    Sensor sensors[MAX_SENSORS];
    
    // Prompt the user for the filename
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    
    // Read the sensor data from the file
    readSensorData(sensors, fp);
    
    // Print the sensor data
    printf("\nSensor Data:\n");
    printSensorData(sensors, MAX_SENSORS);
    
    // Calculate the average temperature
    double avgTemp = calculateAverageTemperature(sensors, MAX_SENSORS);
    printf("\nAverage Temperature: %.2lf\n", avgTemp);
    
    // Find the highest temperature
    double highestTemp = findHighestTemperature(sensors, MAX_SENSORS);
    printf("Highest Temperature: %.2lf\n", highestTemp);
    
    // Find the lowest temperature
    double lowestTemp = findLowestTemperature(sensors, MAX_SENSORS);
    printf("Lowest Temperature: %.2lf\n", lowestTemp);
    
    // Close the file
    fclose(fp);
    
    return 0;
}