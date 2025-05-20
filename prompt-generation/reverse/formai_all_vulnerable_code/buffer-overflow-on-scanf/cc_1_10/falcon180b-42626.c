//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365
#define MIN_TEMPERATURE -50
#define MAX_TEMPERATURE 50

typedef struct {
    char name[20];
    int temperature[MAX_DAYS];
} City;

void generate_random_city(City* city) {
    srand(time(NULL));
    for (int i = 0; i < MAX_DAYS; i++) {
        city->temperature[i] = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
    }
}

void print_city(City* city) {
    printf("City: %s\n", city->name);
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("%d: %d\n", i + 1, city->temperature[i]);
    }
}

int main() {
    City cities[MAX_CITIES];

    int num_cities;
    printf("Enter the number of cities (1-%d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
        generate_random_city(&cities[i]);
    }

    int num_days;
    printf("Enter the number of days to simulate (1-%d): ", MAX_DAYS);
    scanf("%d", &num_days);

    for (int i = 0; i < num_days; i++) {
        for (int j = 0; j < num_cities; j++) {
            cities[j].temperature[i] = (cities[j].temperature[i] + cities[j].temperature[i-1]) / 2;
        }
    }

    printf("Simulation results:\n");
    for (int i = 0; i < num_cities; i++) {
        print_city(&cities[i]);
    }

    return 0;
}