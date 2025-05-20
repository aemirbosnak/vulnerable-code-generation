//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_WEATHER_TYPES 6

enum weather_type {
    SUNNY = 0,
    CLOUDY = 1,
    RAINY = 2,
    SNOWY = 3,
    STORMY = 4,
    FOGGY = 5
};

struct city {
    char name[20];
    double temperature;
    enum weather_type weather;
};

void generate_random_weather(enum weather_type* weather) {
    int rand_num = rand() % NUM_WEATHER_TYPES;
    *weather = (enum weather_type)rand_num;
}

void generate_random_temperature(double* temperature) {
    int rand_num = rand() % 31 - 15;
    *temperature = rand_num * 0.5;
}

void print_city(struct city city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %.1f°C\n", city.temperature);
    printf("Weather: ");

    switch(city.weather) {
        case SUNNY:
            printf("Sunny\n");
            break;
        case CLOUDY:
            printf("Cloudy\n");
            break;
        case RAINY:
            printf("Rainy\n");
            break;
        case SNOWY:
            printf("Snowy\n");
            break;
        case STORMY:
            printf("Stormy\n");
            break;
        case FOGGY:
            printf("Foggy\n");
            break;
    }
}

int main() {
    struct city cities[NUM_CITIES];
    srand(time(NULL));

    for(int i = 0; i < NUM_CITIES; i++) {
        strcpy(cities[i].name, "City ");
        char num_str[2];
        snprintf(num_str, 2, "%d", i + 1);
        strcat(cities[i].name, num_str);

        generate_random_weather(&cities[i].weather);
        generate_random_temperature(&cities[i].temperature);
    }

    printf("Weather Report:\n");

    for(int i = 0; i < NUM_CITIES; i++) {
        print_city(cities[i]);
    }

    return 0;
}