//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_WEATHER_TYPES 10
#define MAX_WEATHER_DURATION 7

struct City {
    char name[20];
    int population;
    int temperature;
    int humidity;
    int wind_speed;
    int weather_type;
    int weather_duration;
};

void generate_weather_data(struct City *city) {
    city->temperature = rand() % 31 + 20;
    city->humidity = rand() % 81 + 20;
    city->wind_speed = rand() % 21 + 5;
    city->weather_type = rand() % MAX_WEATHER_TYPES;
    city->weather_duration = rand() % MAX_WEATHER_DURATION + 1;
}

void print_city_weather(struct City *city) {
    printf("City: %s\n", city->name);
    printf("Population: %d\n", city->population);
    printf("Temperature: %d\n", city->temperature);
    printf("Humidity: %d\n", city->humidity);
    printf("Wind Speed: %d\n", city->wind_speed);
    printf("Weather Type: %d\n", city->weather_type);
    printf("Weather Duration: %d\n\n", city->weather_duration);
}

int main() {
    srand(time(NULL));

    struct City cities[MAX_CITIES];
    int num_cities = 0;

    while (num_cities < MAX_CITIES) {
        printf("Enter the name of a city or press enter to finish: ");
        scanf("%s", cities[num_cities].name);

        if (cities[num_cities].name[0] == '\0') {
            break;
        }

        printf("Enter the population of %s: ", cities[num_cities].name);
        scanf("%d", &cities[num_cities].population);
        generate_weather_data(&cities[num_cities]);
        num_cities++;
    }

    printf("Weather Report:\n");

    for (int i = 0; i < num_cities; i++) {
        print_city_weather(&cities[i]);
    }

    return 0;
}