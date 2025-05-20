//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 365

// Structure for city
typedef struct {
    char name[50];
    int temperature;
    int humidity;
} City;

// Function to generate random weather data for a city
void generateWeatherData(City *city) {
    srand(time(NULL));
    city->temperature = rand() % 50 + 1;
    city->humidity = rand() % 101;
}

// Function to display weather data for a city
void displayWeatherData(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d degrees Celsius\n", city.temperature);
    printf("Humidity: %d%%\n\n", city.humidity);
}

// Function to simulate weather for multiple cities over multiple days
void weatherSimulation(City cities[], int numCities, int numDays) {
    int i, j;
    for (i = 0; i < numCities; i++) {
        generateWeatherData(&cities[i]);
    }

    for (j = 0; j < numDays; j++) {
        printf("Day %d:\n", j + 1);
        for (i = 0; i < numCities; i++) {
            displayWeatherData(cities[i]);
        }
    }
}

int main() {
    City cities[MAX_CITIES];
    int numCities, numDays;

    // Get user input for number of cities and days
    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    printf("Enter the number of days (max %d): ", MAX_DAYS);
    scanf("%d", &numDays);

    // Get user input for city names and simulate weather
    int i;
    for (i = 0; i < numCities; i++) {
        printf("Enter city name %d: ", i + 1);
        scanf("%s", cities[i].name);
    }

    weatherSimulation(cities, numCities, numDays);

    return 0;
}