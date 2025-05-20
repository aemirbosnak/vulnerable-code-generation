//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_CITIES 100
#define MIN_TEMP -50 // in degrees Celsius
#define MAX_TEMP 50 // in degrees Celsius
#define MIN_HUMIDITY 0 // in percentage
#define MAX_HUMIDITY 100 // in percentage
#define MIN_WIND 0 // in meters per second
#define MAX_WIND 20 // in meters per second
#define MIN_RAIN 0 // in millimeters
#define MAX_RAIN 50 // in millimeters

typedef struct {
    char name[50];
    double latitude;
    double longitude;
    int population;
} City;

City cities[MAX_CITIES];
int num_cities;

void generate_cities(int num) {
    int i;
    srand(time(NULL));
    for (i = 0; i < num; i++) {
        cities[i].latitude = rand() % 90 - 45; // between -45 and 45 degrees latitude
        cities[i].longitude = rand() % 180 - 90; // between -90 and 90 degrees longitude
        sprintf(cities[i].name, "City %d", i + 1);
        cities[i].population = rand() % 1000000; // between 0 and 1 million people
    }
    num_cities = num;
}

void print_city(City city) {
    printf("Name: %s\n", city.name);
    printf("Latitude: %.2f\n", city.latitude);
    printf("Longitude: %.2f\n", city.longitude);
    printf("Population: %d\n\n", city.population);
}

void print_weather(City city, double temp, double humidity, double wind, double rain) {
    printf("Weather in %s:\n", city.name);
    printf("Temperature: %.2f\u00B0C\n", temp);
    printf("Humidity: %.2f%%\n", humidity);
    printf("Wind speed: %.2f m/s\n", wind);
    printf("Rainfall: %.2f mm\n\n", rain);
}

int main() {
    int i;
    double temp, humidity, wind, rain;

    printf("Welcome to the Weather Simulator!\n\n");

    printf("Enter the number of cities to simulate (up to %d): ", MAX_CITIES);
    scanf("%d", &num_cities);
    generate_cities(num_cities);

    for (i = 0; i < num_cities; i++) {
        temp = MIN_TEMP + rand() % (MAX_TEMP - MIN_TEMP + 1); // between -50 and 50 degrees Celsius
        humidity = MIN_HUMIDITY + rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1); // between 0 and 100%
        wind = MIN_WIND + rand() % (MAX_WIND - MIN_WIND + 1); // between 0 and 20 meters per second
        rain = MIN_RAIN + rand() % (MAX_RAIN - MIN_RAIN + 1); // between 0 and 50 millimeters

        printf("City %d:\n", i + 1);
        print_city(cities[i]);
        print_weather(cities[i], temp, humidity, wind, rain);
    }

    return 0;
}