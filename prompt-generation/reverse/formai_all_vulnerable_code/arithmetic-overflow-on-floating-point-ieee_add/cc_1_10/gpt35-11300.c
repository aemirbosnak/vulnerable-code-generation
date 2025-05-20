//FormAI DATASET v1.0 Category: Weather simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DAYS 365

// Function declarations
float calculateAverageTemperature(float temperatures[NUM_DAYS]);
float calculateTemperatureChange(float previousTemp, float averageTemp);
void simulateWeather(float temperatures[NUM_DAYS]);
void printWeatherStats(float temperatures[NUM_DAYS], float averageTemp, float maxTemp, float minTemp);

int main() {

    srand(time(NULL)); // Seed the random number generator

    float temperatures[NUM_DAYS];
    simulateWeather(temperatures);

    // Calculate the average temperature
    float averageTemp = calculateAverageTemperature(temperatures);

    // Calculate the maximum and minimum temperature
    float maxTemp = temperatures[0];
    float minTemp = temperatures[0];

    for (int i = 1; i < NUM_DAYS; i++){
        if (temperatures[i] > maxTemp){
            maxTemp = temperatures[i];
        }
        if (temperatures[i] < minTemp){
            minTemp = temperatures[i];
        }
    }

    printWeatherStats(temperatures, averageTemp, maxTemp, minTemp);

    return 0;
}

// Function definitions

// This function calculates the average temperature for a year
float calculateAverageTemperature(float temperatures[NUM_DAYS]){

    float sum = 0;
    for (int i = 0; i < NUM_DAYS; i++){
        sum += temperatures[i];
    }

    return sum / NUM_DAYS;
}

// This function calculates the temperature change for a day
float calculateTemperatureChange(float previousTemp, float averageTemp){

    float randomNum = ((float)rand()/(float)(RAND_MAX)) * 10 - 5; // Generate a random number between -5 and 5
    return (previousTemp + averageTemp + randomNum) / 2;
}

// This function simulates the weather for a year
void simulateWeather(float temperatures[NUM_DAYS]){

    for (int i = 0; i < NUM_DAYS; i++){

        if (i == 0){
            temperatures[i] = 20; // Set the temperature on the first day to 20 degrees Celsius
        } else {
            temperatures[i] = calculateTemperatureChange(temperatures[i-1], calculateAverageTemperature(temperatures));
        }
    }
}

// This function prints the statistics of the simulated weather
void printWeatherStats(float temperatures[NUM_DAYS], float averageTemp, float maxTemp, float minTemp){

    printf("Simulation Results for Weather Data\n");
    printf("-----------------------------------\n");
    printf("Average Temperature: %.2f degrees Celsius\n", averageTemp);
    printf("Maximum Temperature: %.2f degrees Celsius\n", maxTemp);
    printf("Minimum Temperature: %.2f degrees Celsius\n", minTemp);
    printf("\n");

    printf("Day     Temperature\n");
    printf("--------------------\n");
    for (int i = 0; i < NUM_DAYS; i++){
        printf("%3d     %.2f degrees Celsius\n", i+1, temperatures[i]);
    }
}