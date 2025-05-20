//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30
#define MIN_TEMP -20
#define MAX_TEMP 50
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100

// Define the city structure
typedef struct {
    char name[20];
    int temperature;
    int humidity;
} City;

// Define the weather data
City cities[MAX_CITIES];

// Function to generate random weather data
void generateWeather(int numCities) {
    for (int i = 0; i < numCities; i++) {
        cities[i].temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        cities[i].humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
    }
}

// Function to print the weather data
void printWeather(int numCities) {
    for (int i = 0; i < numCities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Temperature: %d\n", cities[i].temperature);
        printf("Humidity: %d\n", cities[i].humidity);
        printf("\n");
    }
}

// Function to simulate weather changes over time
void simulateWeather(int numCities, int numDays) {
    for (int i = 0; i < numDays; i++) {
        // Generate random weather data for each day
        generateWeather(numCities);
        // Print the weather data for each day
        printf("Day %d:\n", i + 1);
        printWeather(numCities);
    }
}

int main() {
    srand(time(NULL));

    int numCities, numDays;

    // Get user input for number of cities and simulation days
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);
    printf("Enter the number of simulation days: ");
    scanf("%d", &numDays);

    // Initialize the city names
    for (int i = 0; i < numCities; i++) {
        sprintf(cities[i].name, "City %d", i + 1);
    }

    // Simulate the weather changes over time
    simulateWeather(numCities, numDays);

    return 0;
}