//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_WEATHER 10

struct city {
    char name[50];
    int x, y;
};

struct weather {
    int temperature;
    int humidity;
    int pressure;
};

void init_cities(struct city* cities, int num_cities) {
    int i;
    for (i = 0; i < num_cities; i++) {
        sprintf(cities[i].name, "City %d", i+1);
        cities[i].x = rand() % 100;
        cities[i].y = rand() % 100;
    }
}

void init_weather(struct weather* weather, int num_weather) {
    int i;
    for (i = 0; i < num_weather; i++) {
        weather[i].temperature = rand() % 50 + 10;
        weather[i].humidity = rand() % 100;
        weather[i].pressure = rand() % 1000;
    }
}

void print_weather(struct weather* weather, int num_weather) {
    int i;
    for (i = 0; i < num_weather; i++) {
        printf("Temperature: %d\n", weather[i].temperature);
        printf("Humidity: %d\n", weather[i].humidity);
        printf("Pressure: %d\n\n", weather[i].pressure);
    }
}

int main() {
    srand(time(NULL));
    int num_cities = rand() % MAX_CITIES + 1;
    int num_weather = rand() % MAX_WEATHER + 1;

    struct city* cities = malloc(num_cities * sizeof(struct city));
    init_cities(cities, num_cities);

    struct weather* weather = malloc(num_weather * sizeof(struct weather));
    init_weather(weather, num_weather);

    printf("Welcome to the Weather Simulation!\n");
    printf("We have data for %d cities:\n", num_cities);

    int city_index = rand() % num_cities;
    printf("Current weather in %s:\n", cities[city_index].name);
    print_weather(weather, num_weather);

    free(cities);
    free(weather);

    return 0;
}