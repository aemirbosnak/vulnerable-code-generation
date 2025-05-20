//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 50
#define MAX_WEATHER_TYPES 10
#define MIN_TEMPERATURE -50
#define MAX_TEMPERATURE 50

typedef struct {
    char name[20];
    int temperature;
    int weatherType;
} City;

void generateRandomWeather(City* city) {
    int weatherType = rand() % MAX_WEATHER_TYPES;
    switch(weatherType) {
        case 0:
            city->weatherType = "Sunny";
            break;
        case 1:
            city->weatherType = "Cloudy";
            break;
        case 2:
            city->weatherType = "Rainy";
            break;
        case 3:
            city->weatherType = "Thunderstorm";
            break;
        case 4:
            city->weatherType = "Snowy";
            break;
        default:
            city->weatherType = "Unknown";
            break;
    }
}

void printCityWeather(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d°C\n", city.temperature);
    printf("Weather: %s\n", city.weatherType);
    printf("\n");
}

int main() {
    srand(time(NULL));
    City cities[MAX_CITIES];
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);
    for(int i = 0; i < numCities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        cities[i].temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
        generateRandomWeather(&cities[i]);
    }
    printf("City Weather Report:\n");
    for(int i = 0; i < numCities; i++) {
        printCityWeather(cities[i]);
    }
    return 0;
}