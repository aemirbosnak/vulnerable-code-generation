//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365
#define MIN_TEMP -50
#define MAX_TEMP 50
#define DELTA_TEMP 5
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100
#define DELTA_HUMIDITY 5

typedef struct {
    char name[50];
    int x, y;
    int temperature;
    int humidity;
} City;

void init_city(City *city) {
    city->temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    city->humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
}

void print_city(City *city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d°C\n", city->temperature);
    printf("Humidity: %d%%\n", city->humidity);
}

int main() {
    srand(time(NULL));

    City cities[MAX_CITIES];
    int num_cities;

    printf("How many cities do you want to simulate? ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
        printf("Enter the coordinates of city %s: ", cities[i].name);
        scanf("%d %d", &cities[i].x, &cities[i].y);
        init_city(&cities[i]);
    }

    int day = 0;

    while (day < MAX_DAYS) {
        for (int i = 0; i < num_cities; i++) {
            cities[i].temperature = (cities[i].temperature + rand() % 5 - 2) % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            cities[i].humidity = (cities[i].humidity + rand() % 5 - 2) % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
        }

        printf("\nDay %d:\n", day + 1);
        for (int i = 0; i < num_cities; i++) {
            print_city(&cities[i]);
        }

        day++;
    }

    return 0;
}