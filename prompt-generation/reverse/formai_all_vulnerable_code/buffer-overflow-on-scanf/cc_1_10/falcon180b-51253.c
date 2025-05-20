//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 30

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int pressure;
} City;

void generate_data(City cities[], int num_cities, int start_day) {
    srand(time(NULL));

    for (int i = 0; i < num_cities; i++) {
        cities[i].temperature = rand() % 41 - 20;
        cities[i].humidity = rand() % 101;
        cities[i].pressure = rand() % 101;
    }

    printf("Weather Data for %d Days:\n", MAX_DAYS);

    for (int day = start_day; day < start_day + MAX_DAYS; day++) {
        printf("Day %d:\n", day);

        for (int i = 0; i < num_cities; i++) {
            printf("City %s: Temperature %d°C, Humidity %d%%\n", cities[i].name, cities[i].temperature, cities[i].humidity);
        }

        printf("\n");
    }
}

int main() {
    City cities[MAX_CITIES];
    int num_cities;

    printf("Enter the number of cities (1 to %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    printf("Enter the names of the cities:\n");

    for (int i = 0; i < num_cities; i++) {
        scanf("%s", cities[i].name);
    }

    int start_day;

    printf("Enter the starting day (1 to %d): ", MAX_DAYS);
    scanf("%d", &start_day);

    generate_data(cities, num_cities, start_day);

    return 0;
}