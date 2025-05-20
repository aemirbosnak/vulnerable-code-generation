//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

// Structure for a city
typedef struct {
    char name[20];
    int temperature;
} City;

// Function to generate random weather data for a city
void generateWeather(City *city) {
    srand(time(NULL));
    city->temperature = rand() % 40 + 1;
}

// Function to print weather data for a city
void printWeather(City *city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d\n", city->temperature);
}

// Function to simulate weather for a given number of days
void simulateWeather(City *cities, int numDays) {
    int i, j;
    for (i = 0; i < numDays; i++) {
        for (j = 0; j < MAX_CITIES; j++) {
            generateWeather(&cities[j]);
        }
        printf("Day %d:\n", i+1);
        for (j = 0; j < MAX_CITIES; j++) {
            printWeather(&cities[j]);
        }
    }
}

// Main function
int main() {
    City cities[MAX_CITIES];
    int numCities, numDays;

    // Get number of cities from user
    printf("Enter number of cities: ");
    scanf("%d", &numCities);

    // Get city names and simulate weather
    for (int i = 0; i < numCities; i++) {
        printf("City %d name: ", i+1);
        scanf("%s", cities[i].name);
    }
    printf("Enter number of days to simulate: ");
    scanf("%d", &numDays);
    simulateWeather(cities, numDays);

    return 0;
}