//Gemma-7B DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

// Define a structure to store sensor data
typedef struct SensorData {
    int temperature;
    char status;
} SensorData;

// Function to read sensor data from a file
SensorData readSensorData(char *filename) {
    SensorData sensorData;
    FILE *fp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fscanf(fp, "%d %c", &sensorData.temperature, &sensorData.status);
    fclose(fp);

    return sensorData;
}

// Function to write sensor data to a file
void writeSensorData(char *filename, SensorData sensorData) {
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(fp, "%d %c", sensorData.temperature, sensorData.status);
    fclose(fp);
}

int main() {
    // Define the sensor data file path
    char *sensorDataFilename = "/tmp/sensor_data.txt";

    // Read sensor data from the file
    SensorData sensorData = readSensorData(sensorDataFilename);

    // Print sensor data
    printf("Temperature: %d\n", sensorData.temperature);
    printf("Status: %c\n", sensorData.status);

    // Write sensor data to the file
    writeSensorData(sensorDataFilename, sensorData);

    return 0;
}