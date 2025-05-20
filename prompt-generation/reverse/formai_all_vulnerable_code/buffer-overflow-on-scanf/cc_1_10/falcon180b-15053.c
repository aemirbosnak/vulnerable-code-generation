//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_CITIES 5
#define DAYS_IN_YEAR 365
#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60

typedef struct {
    char name[20];
    double latitude;
    double longitude;
    double temperature;
    double humidity;
    double pressure;
} City;

void generate_weather_data(City *cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        sprintf(cities[i].name, "City %d", i + 1);
        cities[i].latitude = rand() % 90 + 1;
        cities[i].longitude = rand() % 180 + 1;
        cities[i].temperature = rand() % 50 + 1;
        cities[i].humidity = rand() % 100;
        cities[i].pressure = rand() % 1013 + 1;
    }
}

void print_weather_data(City *cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        printf("City %s:\n", cities[i].name);
        printf("Latitude: %.2f\n", cities[i].latitude);
        printf("Longitude: %.2f\n", cities[i].longitude);
        printf("Temperature: %.2f\n", cities[i].temperature);
        printf("Humidity: %.2f%%\n", cities[i].humidity);
        printf("Pressure: %.2f hPa\n\n", cities[i].pressure);
    }
}

int main() {
    srand(time(NULL));

    City cities[NUM_CITIES];
    generate_weather_data(cities, NUM_CITIES);

    int choice;
    do {
        printf("Weather Simulation\n");
        printf("1. Print weather data\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            print_weather_data(cities, NUM_CITIES);
            break;
        case 2:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}