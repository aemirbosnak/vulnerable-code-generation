//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_HOURS 24

typedef struct {
    char name[50];
    int temperature;
    int humidity;
    int windSpeed;
    int cloudCover;
} City;

void generateWeather(City* city) {
    city->temperature = rand() % 100;
    city->humidity = rand() % 100;
    city->windSpeed = rand() % 50;
    city->cloudCover = rand() % 100;
}

void printWeather(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d degrees\n", city.temperature);
    printf("Humidity: %d%%\n", city.humidity);
    printf("Wind Speed: %d mph\n", city.windSpeed);
    printf("Cloud Cover: %d%%\n", city.cloudCover);
}

int main() {
    City cities[MAX_CITIES];
    int numCities;
    int i, j, k;
    char cityName[50];
    int choice;
    time_t currentTime;
    struct tm* timeInfo;

    printf("Welcome to the Weather Simulator!\n");
    printf("How many cities would you like to simulate? ");
    scanf("%d", &numCities);

    for (i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);
        generateWeather(&cities[i]);
    }

    while (1) {
        currentTime = time(NULL);
        timeInfo = localtime(&currentTime);
        k = 0;

        for (i = 0; i < numCities; i++) {
            if (timeInfo->tm_hour == 0 || timeInfo->tm_hour == 6 || timeInfo->tm_hour == 12 || timeInfo->tm_hour == 18) {
                printf("\n%s Weather Update:\n", cities[i].name);
                printWeather(cities[i]);
                k++;
            }
        }

        if (k == 0) {
            printf("\nNo weather updates at this time.\n");
        }

        printf("\nPress 1 to continue or any other key to exit: ");
        scanf("%d", &choice);
        if (choice!= 1) {
            break;
        }
    }

    return 0;
}