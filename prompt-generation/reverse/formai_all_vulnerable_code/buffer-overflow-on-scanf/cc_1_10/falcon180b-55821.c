//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define DAYS_IN_WEEK 7

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int windSpeed;
    int precipitation;
} City;

void generateRandomWeather(City* city) {
    city->temperature = rand() % 40 + 1;
    city->humidity = rand() % 100;
    city->windSpeed = rand() % 20 + 1;
    city->precipitation = rand() % 3;
}

void printCityWeather(City* city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d degrees\n", city->temperature);
    printf("Humidity: %d%%\n", city->humidity);
    printf("Wind Speed: %d mph\n", city->windSpeed);
    printf("Precipitation: %s\n\n", city->precipitation == 0? "None" : city->precipitation == 1? "Light" : "Heavy");
}

int main() {
    srand(time(NULL));

    City cities[MAX_CITIES];
    int numCities;

    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generateRandomWeather(&cities[i]);
    }

    int day = 0;
    while (day < DAYS_IN_WEEK) {
        printf("\nDay %d:\n", day + 1);
        for (int i = 0; i < numCities; i++) {
            printCityWeather(&cities[i]);
        }
        day++;
    }

    return 0;
}