//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct city {
    char name[50];
    int temperature;
    int humidity;
    int wind_speed;
};

void generate_weather_data(struct city *cities, int num_cities, int start_day, int end_day) {
    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        cities[i].temperature = rand() % 31 + 1;
        cities[i].humidity = rand() % 101;
        cities[i].wind_speed = rand() % 21 + 1;
    }

    for (int day = start_day; day <= end_day; day++) {
        for (int i = 0; i < num_cities; i++) {
            cities[i].temperature += rand() % 6 - 3;
            cities[i].humidity += rand() % 11 - 5;
            cities[i].wind_speed += rand() % 6 - 3;
        }
    }
}

void print_weather_data(struct city *cities, int num_cities, int start_day, int end_day) {
    for (int day = start_day; day <= end_day; day++) {
        printf("Day %d:\n", day);
        for (int i = 0; i < num_cities; i++) {
            printf("City %s: Temperature %d°C, Humidity %d%, Wind Speed %d m/s\n", cities[i].name, cities[i].temperature, cities[i].humidity, cities[i].wind_speed);
        }
    }
}

int main() {
    struct city cities[MAX_CITIES];
    int num_cities;
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        scanf("%s", cities[i].name);
    }

    int start_day, end_day;
    scanf("%d %d", &start_day, &end_day);

    generate_weather_data(cities, num_cities, start_day, end_day);
    print_weather_data(cities, num_cities, start_day, end_day);

    return 0;
}