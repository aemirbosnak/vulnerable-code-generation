//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

struct City {
    char name[50];
    int temperature;
    int humidity;
    int windSpeed;
};

void generateRandomWeather(struct City* city) {
    city->temperature = rand() % 50 + 1;
    city->humidity = rand() % 101;
    city->windSpeed = rand() % 21 + 1;
}

void printCityWeather(struct City* city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d°C\n", city->temperature);
    printf("Humidity: %d%%\n", city->humidity);
    printf("Wind Speed: %d km/h\n\n", city->windSpeed);
}

int main() {
    srand(time(NULL));

    struct City cities[MAX_CITIES];
    int numCities;

    printf("How many cities do you want to simulate? (Maximum %d)\n", MAX_CITIES);
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);
        generateRandomWeather(&cities[i]);
    }

    int numDays;

    printf("How many days do you want to simulate? (Maximum %d)\n", MAX_DAYS);
    scanf("%d", &numDays);

    for (int i = 0; i < numDays; i++) {
        for (int j = 0; j < numCities; j++) {
            printCityWeather(&cities[j]);
        }
    }

    return 0;
}