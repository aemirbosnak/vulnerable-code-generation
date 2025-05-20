//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct city {
    char name[20];
    int population;
    int temperature;
    int precipitation;
};

void init_city(struct city *city) {
    strcpy(city->name, "Unknown");
    city->population = 0;
    city->temperature = 0;
    city->precipitation = 0;
}

int main() {
    int num_cities;
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    struct city cities[MAX_CITIES];
    for (int i = 0; i < num_cities; i++) {
        init_city(&cities[i]);
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        printf("Enter population: ");
        scanf("%d", &cities[i].population);
    }

    int num_days;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);

    srand(time(NULL));

    for (int day = 1; day <= num_days; day++) {
        for (int i = 0; i < num_cities; i++) {
            cities[i].temperature += rand() % 10 - 5;
            cities[i].precipitation += rand() % 20;
        }
    }

    printf("\nWeather Simulation Results:\n");
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Population: %d\n", cities[i].population);
        printf("Average temperature: %.2f\n", (float)cities[i].temperature / num_days);
        printf("Average precipitation: %.2f\n\n", (float)cities[i].precipitation / num_days);
    }

    return 0;
}