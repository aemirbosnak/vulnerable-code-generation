//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10

// Define the city structure
typedef struct {
    char name[50];
    int temperature;
    int humidity;
} City;

// Function to initialize a city with random weather conditions
void initCity(City *city) {
    city->temperature = rand() % 40 + 10; // Temperature between 10 and 50 degrees Celsius
    city->humidity = rand() % 90 + 10; // Humidity between 10 and 100 percent
}

// Function to print the weather conditions of a city
void printCity(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d degrees Celsius\n", city.temperature);
    printf("Humidity: %d%%\n\n", city.humidity);
}

// Function to simulate the weather for all cities
void simulateWeather(City cities[], int numCities, int days) {
    for (int day = 0; day < days; day++) {
        for (int i = 0; i < numCities; i++) {
            City city = cities[i];

            // Simulate temperature change based on humidity
            if (city.humidity > 70) {
                city.temperature++;
            } else if (city.humidity < 30) {
                city.temperature--;
            }

            // Limit temperature range
            if (city.temperature < 10) {
                city.temperature = 10;
            } else if (city.temperature > 50) {
                city.temperature = 50;
            }

            // Simulate humidity change based on temperature
            if (city.temperature > 30) {
                city.humidity++;
            } else if (city.temperature < 20) {
                city.humidity--;
            }

            // Limit humidity range
            if (city.humidity < 10) {
                city.humidity = 10;
            } else if (city.humidity > 90) {
                city.humidity = 90;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Initialize cities with random weather conditions
    City cities[MAX_CITIES];
    for (int i = 0; i < MAX_CITIES; i++) {
        initCity(&cities[i]);
    }

    // Simulate weather for 7 days
    simulateWeather(cities, MAX_CITIES, 7);

    // Print weather conditions for each city
    for (int i = 0; i < MAX_CITIES; i++) {
        printCity(cities[i]);
    }

    return 0;
}