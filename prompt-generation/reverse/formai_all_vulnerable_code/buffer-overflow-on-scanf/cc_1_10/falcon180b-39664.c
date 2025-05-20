//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_DAYS 7

typedef struct {
    char name[20];
    int temperature;
} City;

void generateRandomWeather(City* cities, int numCities, int numDays) {
    srand(time(NULL));

    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numDays; j++) {
            int temp = rand() % 41 - 20; // Generate random temperature between -20 and 20 degrees Celsius
            cities[i].temperature = temp;
        }
    }
}

void printWeatherForecast(City* cities, int numCities, int numDays) {
    printf("Weather Forecast for the next %d days:\n", numDays);

    for (int i = 0; i < numCities; i++) {
        printf("In %s:\n", cities[i].name);

        for (int j = 0; j < numDays; j++) {
            printf("Day %d: %d degrees Celsius\n", j + 1, cities[i].temperature);
        }

        printf("\n");
    }
}

int main() {
    City cities[NUM_CITIES];

    for (int i = 0; i < NUM_CITIES; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
    }

    generateRandomWeather(cities, NUM_CITIES, NUM_DAYS);
    printWeatherForecast(cities, NUM_CITIES, NUM_DAYS);

    return 0;
}