//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_CITIES 5

struct City {
    char name[20];
    double latitude;
    double longitude;
    double temperature;
    double humidity;
    double pressure;
};

void get_weather_data(struct City *cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);
        printf("Enter the latitude of %s: ", cities[i].name);
        scanf("%lf", &cities[i].latitude);
        printf("Enter the longitude of %s: ", cities[i].name);
        scanf("%lf", &cities[i].longitude);
        cities[i].temperature = rand() % 41 + 20;
        cities[i].humidity = rand() % 61 + 20;
        cities[i].pressure = rand() % 1016 + 850;
    }
}

void display_weather_data(struct City *cities, int num_cities) {
    printf("\nWeather Data:\n");
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Latitude: %.2lf\n", cities[i].latitude);
        printf("Longitude: %.2lf\n", cities[i].longitude);
        printf("Temperature: %.2lf C\n", cities[i].temperature);
        printf("Humidity: %.2lf %%\n", cities[i].humidity);
        printf("Pressure: %.2lf hPa\n", cities[i].pressure);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    struct City cities[NUM_CITIES];
    get_weather_data(cities, NUM_CITIES);
    display_weather_data(cities, NUM_CITIES);
    return 0;
}