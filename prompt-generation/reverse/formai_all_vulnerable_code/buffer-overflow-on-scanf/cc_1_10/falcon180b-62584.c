//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100

typedef struct {
    char name[50];
    float temperature;
    float humidity;
    float wind_speed;
} City;

City cities[MAX_CITIES];

void init_cities() {
    int i;
    for (i = 0; i < MAX_CITIES; i++) {
        sprintf(cities[i].name, "City %d", i + 1);
        cities[i].temperature = (float) rand() / RAND_MAX * 100;
        cities[i].humidity = (float) rand() / RAND_MAX * 100;
        cities[i].wind_speed = (float) rand() / RAND_MAX * 50;
    }
}

void print_city(City city) {
    printf("Name: %s\n", city.name);
    printf("Temperature: %.2f C\n", city.temperature);
    printf("Humidity: %.2f %%\n", city.humidity);
    printf("Wind Speed: %.2f km/h\n\n", city.wind_speed);
}

void simulate_weather(int duration) {
    int i, j;
    float temperature_change, humidity_change, wind_speed_change;
    time_t start_time, end_time;

    srand(time(NULL));
    init_cities();

    printf("Weather Simulation\n");
    printf("Duration: %d hours\n\n", duration);

    start_time = time(NULL);
    for (i = 0; i < duration; i++) {
        for (j = 0; j < MAX_CITIES; j++) {
            temperature_change = (float) rand() / RAND_MAX * 5 - 2.5;
            cities[j].temperature += temperature_change;

            humidity_change = (float) rand() / RAND_MAX * 10 - 5;
            cities[j].humidity += humidity_change;

            wind_speed_change = (float) rand() / RAND_MAX * 10 - 5;
            cities[j].wind_speed += wind_speed_change;
        }
        printf("Hour %d\n", i + 1);
        for (j = 0; j < MAX_CITIES; j++) {
            print_city(cities[j]);
        }
        printf("\n");
    }

    end_time = time(NULL);
    printf("\nSimulation complete!\n");
    printf("Total duration: %d seconds\n", end_time - start_time);
}

int main() {
    int duration;

    printf("Enter duration (hours): ");
    scanf("%d", &duration);

    simulate_weather(duration);

    return 0;
}