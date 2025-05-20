//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

typedef struct {
    char name[20];
    int temperature[MAX_DAYS];
    int humidity[MAX_DAYS];
} City;

void generateWeather(City *city) {
    for(int i=0; i<MAX_DAYS; i++) {
        city->temperature[i] = rand() % 100;
        city->humidity[i] = rand() % 100;
    }
}

void printWeather(City *city) {
    printf("Weather for %s:\n", city->name);
    for(int i=0; i<MAX_DAYS; i++) {
        printf("Day %d: Temperature - %d, Humidity - %d\n", i+1, city->temperature[i], city->humidity[i]);
    }
}

int main() {
    City cities[MAX_CITIES];
    int numCities;

    printf("Enter number of cities: ");
    scanf("%d", &numCities);

    srand(time(NULL));

    for(int i=0; i<numCities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generateWeather(&cities[i]);
    }

    int choice;
    do {
        printf("\n1. Print weather for a city\n2. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter city name: ");
                char cityName[20];
                scanf("%s", cityName);

                for(int i=0; i<numCities; i++) {
                    if(strcmp(cityName, cities[i].name) == 0) {
                        printWeather(&cities[i]);
                        break;
                    }
                }
                break;

            case 2:
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice!= 2);

    return 0;
}