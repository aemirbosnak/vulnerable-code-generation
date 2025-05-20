//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365
#define MIN_TEMP -20
#define MAX_TEMP 50

typedef struct {
    char name[20];
    int x;
    int y;
} City;

typedef struct {
    City *cities;
    int num_cities;
    int **weather;
} Simulation;

void init_simulation(Simulation *sim, int num_cities) {
    sim->num_cities = num_cities;
    sim->cities = malloc(num_cities * sizeof(City));
    sim->weather = malloc(num_cities * sizeof(int*));
    for (int i = 0; i < num_cities; i++) {
        sim->cities[i].x = rand() % 100;
        sim->cities[i].y = rand() % 100;
        sim->weather[i] = malloc(MAX_DAYS * sizeof(int));
        for (int j = 0; j < MAX_DAYS; j++) {
            sim->weather[i][j] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        }
    }
}

void print_weather(int *weather, int num_days) {
    for (int i = 0; i < num_days; i++) {
        printf("%d ", weather[i]);
    }
    printf("\n");
}

void free_simulation(Simulation *sim) {
    for (int i = 0; i < sim->num_cities; i++) {
        free(sim->weather[i]);
    }
    free(sim->weather);
    free(sim->cities);
}

int main() {
    srand(time(NULL));
    Simulation sim;
    int num_cities;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    init_simulation(&sim, num_cities);

    while (1) {
        system("clear");
        printf("Enter the city name: ");
        char city_name[20];
        scanf("%s", city_name);

        int index = -1;
        for (int i = 0; i < sim.num_cities; i++) {
            if (strcmp(sim.cities[i].name, city_name) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("City not found.\n");
            continue;
        }

        printf("Weather forecast for %s:\n", city_name);
        print_weather(sim.weather[index], MAX_DAYS);
    }

    return 0;
}