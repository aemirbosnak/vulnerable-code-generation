//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 20
#define DAYS_IN_WEEK 7

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int windSpeed;
} City;

void generateRandomWeather(City *city) {
    city->temperature = rand() % 40 + 10;
    city->humidity = rand() % 100;
    city->windSpeed = rand() % 20 + 1;
}

void printWeatherReport(City *cities, int numCities) {
    printf("Weather Report for %d cities:\n", numCities);
    for (int i = 0; i < numCities; i++) {
        printf("City %s: Temperature %d°C, Humidity %d%% and Wind Speed %d km/h\n", cities[i].name, cities[i].temperature, cities[i].humidity, cities[i].windSpeed);
    }
}

int main() {
    srand(time(NULL));

    City cities[MAX_CITIES];
    int numCities = 0;

    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    printf("Enter the names of the cities:\n");
    for (int i = 0; i < numCities; i++) {
        scanf("%s", cities[i].name);
        generateRandomWeather(&cities[i]);
    }

    int choice;
    do {
        printf("\nWeather Simulation Menu:\n");
        printf("1. Print current weather report\n");
        printf("2. Simulate weather for a week\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printWeatherReport(cities, numCities);
                break;
            case 2:
                for (int day = 1; day <= DAYS_IN_WEEK; day++) {
                    printf("\nDay %d:\n", day);
                    for (int i = 0; i < numCities; i++) {
                        generateRandomWeather(&cities[i]);
                        printf("City %s: Temperature %d°C, Humidity %d%% and Wind Speed %d km/h\n", cities[i].name, cities[i].temperature, cities[i].humidity, cities[i].windSpeed);
                    }
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}