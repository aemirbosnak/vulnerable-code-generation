//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_WEATHER_TYPES 10

typedef struct {
    char name[50];
    int x;
    int y;
    int temperature;
    int humidity;
    int wind_speed;
    int weather_type;
} City;

void generate_weather(City *cities, int num_cities) {
    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        cities[i].temperature = rand() % 100;
        cities[i].humidity = rand() % 100;
        cities[i].wind_speed = rand() % 50;
        cities[i].weather_type = rand() % MAX_WEATHER_TYPES;
    }
}

void print_weather(City *cities, int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Temperature: %d°C\n", cities[i].temperature);
        printf("Humidity: %d%%\n", cities[i].humidity);
        printf("Wind Speed: %d km/h\n", cities[i].wind_speed);
        printf("Weather Type: ");
        switch (cities[i].weather_type) {
            case 0:
                printf("Sunny\n");
                break;
            case 1:
                printf("Cloudy\n");
                break;
            case 2:
                printf("Rainy\n");
                break;
            case 3:
                printf("Thunderstorm\n");
                break;
            case 4:
                printf("Snowy\n");
                break;
            default:
                printf("Unknown\n");
        }
        printf("\n");
    }
}

int main() {
    int num_cities;
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    City cities[num_cities];
    printf("Enter the names of the cities:\n");
    for (int i = 0; i < num_cities; i++) {
        scanf("%s", cities[i].name);
    }

    printf("Enter the coordinates of the cities:\n");
    for (int i = 0; i < num_cities; i++) {
        scanf("%d %d", &cities[i].x, &cities[i].y);
    }

    generate_weather(cities, num_cities);
    print_weather(cities, num_cities);

    return 0;
}