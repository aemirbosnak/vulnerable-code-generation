//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP -20
#define MAX_TEMP 40

void printTemperatures(float temperatures[], int size);
float averageTemperature(float temperatures[], int size);
float highestTemperature(float temperatures[], int size);
float lowestTemperature(float temperatures[], int size);

int main() {
    srand(time(NULL));  // Initialize random seed
    int numDays;        
    printf("Enter the number of days to monitor: ");
    scanf("%d", &numDays); // Get number of days from user
    
    float temperatures[numDays];
    // Generate random temperatures and store them in the array
    for (int i = 0; i < numDays; i++) {
        float temp = (float)(rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP) + (float)(rand() % 100) / 100.0;
        temperatures[i] = temp;
    }
    
    printTemperatures(temperatures, numDays);
    
    float avgTemp = averageTemperature(temperatures, numDays);
    printf("The average temperature over the %d day period was %.2f degrees Celsius.\n", numDays, avgTemp);
    
    float highestTemp = highestTemperature(temperatures, numDays);
    printf("The highest temperature recorded over the %d day period was %.2f degrees Celsius.\n", numDays, highestTemp);
    
    float lowestTemp = lowestTemperature(temperatures, numDays);
    printf("The lowest temperature recorded over the %d day period was %.2f degrees Celsius.\n", numDays, lowestTemp);
    
    return 0;
}

// Function to print all temperatures in the given array
void printTemperatures(float temperatures[], int size) {
    printf("Temperatures:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", temperatures[i]);
    }
    printf("\n");
}

// Function to calculate the average temperature of the given array
float averageTemperature(float temperatures[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += temperatures[i];
    }
    float average = sum / size;
    return average;
}

// Function to find the highest temperature in the given array
float highestTemperature(float temperatures[], int size) {
    float highest = temperatures[0];
    for (int i = 1; i < size; i++) {
        if (temperatures[i] > highest) {
            highest = temperatures[i];
        }
    }
    return highest;
}

// Function to find the lowest temperature in the given array
float lowestTemperature(float temperatures[], int size) {
    float lowest = temperatures[0];
    for (int i = 1; i < size; i++) {
        if (temperatures[i] < lowest) {
            lowest = temperatures[i];
        }
    }
    return lowest;
}