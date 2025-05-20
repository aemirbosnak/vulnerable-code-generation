//Falcon2-11B DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int numCities = 5; // Number of cities in the simulation
int cityData[5][2]; // Array of city data
double temp[5][5]; // Array of temperature values
int numDays = 30; // Number of days in the simulation
double tempMin = -30.0; // Minimum temperature
double tempMax = 50.0; // Maximum temperature
double temperatureVariance = 5.0; // Temperature variance
int day = 0; // Current day of the simulation
int cityIndex = 0; // Current city index
double totalTemp = 0.0; // Total temperature

void initCities() {
    srand(time(NULL)); // Seed random number generator

    for (int i = 0; i < numCities; i++) {
        cityData[i][0] = rand() % 1000; // City ID
        cityData[i][1] = rand() % 1000; // City name
        temp[i][0] = (rand() % 100 - 50) + tempMin; // Initial temperature
        temp[i][1] = (rand() % 100 - 50) + tempMin; // Initial temperature
    }
}

void printCityData() {
    printf("City ID\tCity Name\n");
    for (int i = 0; i < numCities; i++) {
        printf("%d\t\t%s\n", cityData[i][0], cityData[i][1]);
    }
}

void printTemperature(int cityIndex) {
    printf("Day\tCity Index\tTemperature\n");
    for (int i = 0; i < numDays; i++) {
        printf("%d\t\t%d\t\t%f\n", day + 1, cityIndex, temp[cityIndex][i]);
    }
}

int main() {
    initCities(); // Initialize city data

    printf("City Data:\n");
    printCityData(); // Print city data

    for (int i = 0; i < numDays; i++) {
        day++; // Increment day count

        for (int j = 0; j < numCities; j++) {
            cityIndex = j; // Update city index

            temp[cityIndex][i] = (rand() % 100 - 50) + tempMin + (rand() % 100 - 50) * temperatureVariance; // Update temperature with random value

            totalTemp += temp[cityIndex][i]; // Add temperature to total temperature
        }

        printf("Day %d:\n", day);
        printTemperature(cityIndex); // Print temperature data
    }

    printf("Total Temperature: %f\n", totalTemp); // Print total temperature

    return 0;
}