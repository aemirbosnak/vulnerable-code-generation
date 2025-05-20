//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100

// Structure to store city information
typedef struct {
    char name[50];
    int temperature;
    int humidity;
    int windSpeed;
} City;

// Function to generate random weather data for a city
void generateWeather(City *city) {
    city->temperature = rand() % 50 + 10;
    city->humidity = rand() % 100;
    city->windSpeed = rand() % 20 + 5;
}

// Function to print weather data for a city
void printWeather(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d degrees\n", city.temperature);
    printf("Humidity: %d%%\n", city.humidity);
    printf("Wind Speed: %d mph\n\n", city.windSpeed);
}

// Function to simulate weather for all cities
void simulateWeather(City cities[], int numCities) {
    for (int i = 0; i < numCities; i++) {
        generateWeather(&cities[i]);
        printWeather(cities[i]);
    }
}

int main() {
    City cities[MAX_CITIES];
    int numCities = 0;

    // Read city information from user
    printf("Enter city information (name, temperature, humidity, wind speed):\n");
    while (numCities < MAX_CITIES && scanf("%s %d %d %d", cities[numCities].name, &cities[numCities].temperature, &cities[numCities].humidity, &cities[numCities].windSpeed) == 4) {
        numCities++;
    }

    // Simulate weather for all cities
    printf("Simulating weather...\n");
    simulateWeather(cities, numCities);

    return 0;
}