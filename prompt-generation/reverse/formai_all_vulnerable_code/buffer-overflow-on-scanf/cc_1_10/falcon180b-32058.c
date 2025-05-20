//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_WEATHER_TYPES 10

struct WeatherType {
    char name[20];
    int temperature;
    int humidity;
};

struct City {
    char name[20];
    int population;
    struct WeatherType currentWeather;
};

void generateRandomWeather(struct WeatherType *weather) {
    weather->temperature = rand() % 50 + 1;
    weather->humidity = rand() % 100;
}

void printWeather(struct WeatherType weather) {
    printf("Temperature: %d\n", weather.temperature);
    printf("Humidity: %d%%\n", weather.humidity);
}

int main() {
    srand(time(NULL));

    struct WeatherType weatherTypes[MAX_WEATHER_TYPES];
    for (int i = 0; i < MAX_WEATHER_TYPES; i++) {
        generateRandomWeather(&weatherTypes[i]);
    }

    struct City cities[MAX_CITIES];
    int numCities = 0;

    while (numCities < MAX_CITIES) {
        printf("Enter the name of a city (or type 'quit' to finish):\n");
        scanf("%s", cities[numCities].name);

        if (strcmp(cities[numCities].name, "quit") == 0) {
            break;
        }

        printf("Enter the population of %s:\n", cities[numCities].name);
        scanf("%d", &cities[numCities].population);

        cities[numCities].currentWeather = weatherTypes[rand() % MAX_WEATHER_TYPES];
        numCities++;
    }

    printf("\nWeather Report:\n");
    for (int i = 0; i < numCities; i++) {
        printf("In %s (%d people), the weather is:\n", cities[i].name, cities[i].population);
        printWeather(cities[i].currentWeather);
    }

    return 0;
}