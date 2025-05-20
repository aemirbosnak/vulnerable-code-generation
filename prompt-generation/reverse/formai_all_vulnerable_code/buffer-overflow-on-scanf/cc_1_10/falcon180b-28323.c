//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_DAYS 7

struct City {
    char name[20];
    int temperature[NUM_DAYS];
    int humidity[NUM_DAYS];
};

void generateWeather(struct City* city) {
    for (int i = 0; i < NUM_DAYS; i++) {
        city->temperature[i] = rand() % 40 + 10;
        city->humidity[i] = rand() % 90 + 10;
    }
}

void printWeather(struct City* city) {
    printf("Weather forecast for %s:\n", city->name);
    for (int i = 0; i < NUM_DAYS; i++) {
        printf("Day %d: %d degrees Celsius, %d%% humidity\n", i + 1, city->temperature[i], city->humidity[i]);
    }
}

int main() {
    srand(time(NULL));

    struct City cities[NUM_CITIES];

    for (int i = 0; i < NUM_CITIES; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
        generateWeather(&cities[i]);
    }

    int choice;
    while (1) {
        printf("\n1. Print weather for all cities\n2. Print weather for a specific city\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            for (int i = 0; i < NUM_CITIES; i++) {
                printWeather(&cities[i]);
            }
        } else if (choice == 2) {
            printf("Enter the name of the city: ");
            char cityName[20];
            scanf("%s", cityName);

            for (int i = 0; i < NUM_CITIES; i++) {
                if (strcmp(cities[i].name, cityName) == 0) {
                    printWeather(&cities[i]);
                    break;
                }
            }
        } else {
            break;
        }
    }

    return 0;
}