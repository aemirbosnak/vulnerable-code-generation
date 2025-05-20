//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_WEATHER_TYPES 10
#define MIN_TEMP -50
#define MAX_TEMP 50
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 100

typedef struct {
    char name[50];
    int temperature;
    int humidity;
    int wind_speed;
    int weather_type;
} City;

void generate_weather_data(City cities[], int num_cities) {
    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        cities[i].temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        cities[i].humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
        cities[i].wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
        cities[i].weather_type = rand() % MAX_WEATHER_TYPES;
    }
}

void print_weather_data(City cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Temperature: %d\n", cities[i].temperature);
        printf("Humidity: %d\n", cities[i].humidity);
        printf("Wind Speed: %d\n", cities[i].wind_speed);
        printf("Weather Type: %d\n\n", cities[i].weather_type);
    }
}

int main() {
    City cities[MAX_CITIES];
    int num_cities;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);
    }

    generate_weather_data(cities, num_cities);
    print_weather_data(cities, num_cities);

    return 0;
}