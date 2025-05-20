//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[20];
    int temperature;
    int humidity;
} City;

void init_cities(City cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        sprintf(cities[i].name, "City %d", i + 1);
        cities[i].temperature = rand() % 40 + 1;
        cities[i].humidity = rand() % 101;
    }
}

void print_city(City city) {
    printf("Name: %s\n", city.name);
    printf("Temperature: %d°C\n", city.temperature);
    printf("Humidity: %d%%\n\n", city.humidity);
}

void simulate_weather(City cities[], int num_cities, int days) {
    srand(time(NULL));

    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < days; j++) {
            if (j % 7 == 0) {
                cities[i].temperature += rand() % 6 - 3;
            } else if (j % 3 == 0) {
                cities[i].humidity += rand() % 6 - 3;
            }
        }
    }
}

int main() {
    City cities[MAX_CITIES];
    int num_cities, days;

    printf("Enter the number of cities (1-%d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    printf("Enter the number of days to simulate (1-%d): ", MAX_DAYS);
    scanf("%d", &days);

    init_cities(cities, num_cities);

    printf("Weather simulation for %d cities over %d days:\n", num_cities, days);

    for (int i = 0; i < num_cities; i++) {
        print_city(cities[i]);
    }

    simulate_weather(cities, num_cities, days);

    printf("Weather simulation complete!\n");

    return 0;
}