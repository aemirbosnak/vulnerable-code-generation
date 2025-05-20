//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITY 5
#define MAX_DAY 365
#define MAX_HOUR 24
#define MAX_MINUTE 60
#define MAX_SECOND 60

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int cloudiness;
    int windSpeed;
} City;

void initCity(City* city) {
    strcpy(city->name, "Unknown");
    city->temperature = 0;
    city->humidity = 0;
    city->cloudiness = 0;
    city->windSpeed = 0;
}

void printCity(City city) {
    printf("City Name: %s\n", city.name);
    printf("Temperature: %d\n", city.temperature);
    printf("Humidity: %d\n", city.humidity);
    printf("Cloudiness: %d\n", city.cloudiness);
    printf("Wind Speed: %d\n", city.windSpeed);
}

void simulateDay(City* cities, int numCities) {
    int i;
    for (i = 0; i < numCities; i++) {
        cities[i].temperature += rand() % 10 - 5;
        cities[i].humidity += rand() % 10;
        cities[i].cloudiness += rand() % 10;
        cities[i].windSpeed += rand() % 10;
    }
}

int main() {
    srand(time(NULL));
    City cities[MAX_CITY];
    int numCities = 0;
    char choice;

    do {
        printf("Weather Simulation\n");
        printf("=================\n");
        printf("A - Add City\n");
        printf("S - Start Simulation\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                if (numCities >= MAX_CITY) {
                    printf("Maximum number of cities reached.\n");
                } else {
                    printf("Enter City Name: ");
                    scanf("%s", cities[numCities].name);
                    initCity(&cities[numCities]);
                    numCities++;
                }
                break;
            case 'S':
                if (numCities == 0) {
                    printf("No cities added.\n");
                } else {
                    int day = 0;
                    while (day < MAX_DAY) {
                        simulateDay(cities, numCities);
                        printf("\nDay %d\n", day+1);
                        for (int i = 0; i < numCities; i++) {
                            printCity(cities[i]);
                        }
                        day++;
                        printf("\n");
                    }
                }
                break;
            case 'Q':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 'Q');

    return 0;
}