//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define DAYS_IN_A_WEEK 7

struct City {
    char name[20];
    int temp[DAYS_IN_A_WEEK];
};

void generateRandomWeather(struct City* city) {
    srand(time(NULL));
    for (int i = 0; i < DAYS_IN_A_WEEK; i++) {
        city->temp[i] = rand() % 40 + 1;
    }
}

void printWeather(struct City* city) {
    printf("Weather forecast for %s:\n", city->name);
    for (int i = 0; i < DAYS_IN_A_WEEK; i++) {
        printf("Day %d: %d degrees Celsius\n", i + 1, city->temp[i]);
    }
}

int main() {
    struct City cities[MAX_CITIES];
    int numCities;

    printf("Welcome to the Weather Simulator!\n");
    printf("How many cities would you like to simulate? (Max %d): ", MAX_CITIES);
    scanf("%d", &numCities);

    for (int i = 0; i < numCities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
        generateRandomWeather(&cities[i]);
    }

    int choice;
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Print weather forecast for a city\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the name of the city: ");
            char cityName[20];
            scanf("%s", cityName);

            for (int i = 0; i < numCities; i++) {
                if (strcmp(cityName, cities[i].name) == 0) {
                    printWeather(&cities[i]);
                    break;
                }
            }
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}