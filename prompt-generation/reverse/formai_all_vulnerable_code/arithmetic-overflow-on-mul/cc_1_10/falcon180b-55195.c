//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_CITIES 100
#define MAX_DAYS 365
#define MIN_TEMP -50
#define MAX_TEMP 50

struct City {
    char name[50];
    double lat, lon;
    int population;
};

struct Weather {
    int day;
    double temp, humidity, wind_speed;
};

void init_cities(struct City cities[], int num_cities) {
    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        cities[i].population = rand() % 1000000;
        cities[i].lat = rand() % 180 - 90;
        cities[i].lon = rand() % 360 - 180;
        sprintf(cities[i].name, "City %d", i + 1);
    }
}

void generate_weather(struct Weather weather[], int num_days, double avg_temp) {
    for (int i = 0; i < num_days; i++) {
        weather[i].day = i + 1;
        weather[i].temp = avg_temp + rand() % 10 - 5;
        weather[i].humidity = rand() % 101;
        weather[i].wind_speed = rand() % 101;
    }
}

void print_weather(struct Weather weather[], int num_days) {
    for (int i = 0; i < num_days; i++) {
        printf("%d: Temperature %.2fC, Humidity %.2f%, Wind Speed %.2f m/s\n", weather[i].day, weather[i].temp, weather[i].humidity, weather[i].wind_speed);
    }
}

int main() {
    struct City cities[MAX_CITIES];
    int num_cities = rand() % MAX_CITIES + 1;
    init_cities(cities, num_cities);

    struct Weather weather[MAX_DAYS];
    int num_days = rand() % MAX_DAYS + 1;
    double avg_temp = MIN_TEMP + (MAX_TEMP - MIN_TEMP) * rand() / RAND_MAX;
    generate_weather(weather, num_days, avg_temp);

    printf("Weather forecast for %d cities in the next %d days:\n", num_cities, num_days);
    for (int i = 0; i < num_cities; i++) {
        printf("City %s:\n", cities[i].name);
        print_weather(weather, num_days);
    }

    return 0;
}