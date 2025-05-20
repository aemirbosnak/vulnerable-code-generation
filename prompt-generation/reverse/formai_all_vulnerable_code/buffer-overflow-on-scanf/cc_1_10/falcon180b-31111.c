//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_DAYS 7

typedef struct {
    char name[20];
    int temperature[NUM_DAYS];
    int humidity[NUM_DAYS];
} City;

void generateWeather(City* city) {
    for (int i = 0; i < NUM_DAYS; i++) {
        city->temperature[i] = rand() % 100;
        city->humidity[i] = rand() % 100;
    }
}

void printWeather(City* city) {
    printf("Weather forecast for %s:\n", city->name);
    for (int i = 0; i < NUM_DAYS; i++) {
        printf("Day %d: Temperature - %d degrees, Humidity - %d%%\n", i+1, city->temperature[i], city->humidity[i]);
    }
}

int main() {
    City cities[NUM_CITIES];
    srand(time(NULL));

    for (int i = 0; i < NUM_CITIES; i++) {
        sprintf(cities[i].name, "City %d", i+1);
        generateWeather(&cities[i]);
    }

    int choice;
    do {
        printf("\nSelect a city:\n");
        for (int i = 0; i < NUM_CITIES; i++) {
            printf("%d. %s\n", i+1, cities[i].name);
        }
        scanf("%d", &choice);
        if (choice >= 1 && choice <= NUM_CITIES) {
            printWeather(&cities[choice-1]);
        } else {
            printf("Invalid choice.\n");
        }
        printf("\nDo you want to check the weather for another city? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}