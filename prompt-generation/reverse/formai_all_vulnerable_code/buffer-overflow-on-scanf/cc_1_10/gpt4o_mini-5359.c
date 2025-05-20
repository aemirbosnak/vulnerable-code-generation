//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>

#define MAX_READINGS 100

// Function to get temperature readings from the user
void getTemperatureReadings(float readings[], int *numReadings) {
    float input;
    printf("Enter temperature readings (in °C) one by one (Enter -999 to stop):\n");
    
    while (*numReadings < MAX_READINGS) {
        scanf("%f", &input);
        
        if (input == -999) {
            break; // Stop reading temperatures if user inputs -999
        }
        
        readings[*numReadings] = input;
        (*numReadings)++;
    }
}

// Function to calculate the average temperature
float calculateAverage(float readings[], int numReadings) {
    float sum = 0.0;
    for (int i = 0; i < numReadings; i++) {
        sum += readings[i];
    }
    return (numReadings > 0) ? (sum / numReadings) : 0.0;
}

// Function to find the maximum temperature
float findMaximum(float readings[], int numReadings) {
    float maxTemp = readings[0];
    for (int i = 1; i < numReadings; i++) {
        if (readings[i] > maxTemp) {
            maxTemp = readings[i];
        }
    }
    return maxTemp;
}

// Function to find the minimum temperature
float findMinimum(float readings[], int numReadings) {
    float minTemp = readings[0];
    for (int i = 1; i < numReadings; i++) {
        if (readings[i] < minTemp) {
            minTemp = readings[i];
        }
    }
    return minTemp;
}

// Function to display temperature statistics
void displayStatistics(float average, float max, float min) {
    printf("\nTemperature Statistics:\n");
    printf("Average Temperature: %.2f °C\n", average);
    printf("Maximum Temperature: %.2f °C\n", max);
    printf("Minimum Temperature: %.2f °C\n", min);
}

int main() {
    float temperatureReadings[MAX_READINGS];
    int numReadings = 0;

    getTemperatureReadings(temperatureReadings, &numReadings);
    
    if (numReadings > 0) {
        float average = calculateAverage(temperatureReadings, numReadings);
        float max = findMaximum(temperatureReadings, numReadings);
        float min = findMinimum(temperatureReadings, numReadings);
        
        displayStatistics(average, max, min);
    } else {
        printf("No temperature readings were entered.\n");
    }
    
    return 0;
}