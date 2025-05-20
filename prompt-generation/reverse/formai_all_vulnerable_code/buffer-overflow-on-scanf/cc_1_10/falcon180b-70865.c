//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
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

void generateWeather(struct City* city, int day) {
    if (day % 7 == 0) {
        city->temperature = rand() % 41 + 10;
        city->humidity = rand() % 91 + 10;
        city->windSpeed = rand() % 21 + 10;
    } else {
        city->temperature = rand() % 11 + city->temperature;
        city->humidity = rand() % 11 + city->humidity;
        city->windSpeed = rand() % 11 + city->windSpeed;
    }
}

void printWeather(struct City* city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d°C\n", city->temperature);
    printf("Humidity: %d%%\n", city->humidity);
    printf("Wind Speed: %d m/s\n\n", city->windSpeed);
}

int main() {
    srand(time(NULL));

    struct City cities[MAX_CITIES];
    int numCities;

    printf("Welcome to the Weather Simulator!\n");
    printf("How many cities would you like to simulate? (Max: %d) ", MAX_CITIES);
    scanf("%d", &numCities);

    printf("Enter the names of the cities:\n");
    for (int i = 0; i < numCities; i++) {
        scanf("%s", cities[i].name);
    }

    int days;
    printf("How many days would you like to simulate? (Max: %d) ", MAX_DAYS);
    scanf("%d", &days);

    for (int i = 0; i < numCities; i++) {
        printf("Initial weather for %s:\n", cities[i].name);
        printWeather(&cities[i]);
    }

    for (int day = 1; day <= days; day++) {
        printf("\nDay %d:\n", day);
        for (int i = 0; i < numCities; i++) {
            generateWeather(&cities[i], day);
            printWeather(&cities[i]);
        }
    }

    return 0;
}