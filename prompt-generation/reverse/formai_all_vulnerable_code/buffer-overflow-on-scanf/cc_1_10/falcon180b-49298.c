//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_WEATHER_TYPES 10

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int wind_speed;
    int weather_type;
} City;

void generate_random_weather(City* city) {
    srand(time(NULL));
    city->temperature = rand() % 40 + 10;
    city->humidity = rand() % 101;
    city->wind_speed = rand() % 21 + 5;
    city->weather_type = rand() % MAX_WEATHER_TYPES;
}

void print_city_weather(City city) {
    printf("City: %s\n", city.name);
    printf("Temperature: %d°C\n", city.temperature);
    printf("Humidity: %d%%\n", city.humidity);
    printf("Wind Speed: %d m/s\n", city.wind_speed);
    printf("Weather Type: ");
    switch (city.weather_type) {
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
            break;
    }
}

int main() {
    City cities[MAX_CITIES];
    int num_cities;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i + 1);
        scanf("%s", cities[i].name);
        generate_random_weather(&cities[i]);
    }

    printf("\nWeather Report:\n");
    for (int i = 0; i < num_cities; i++) {
        print_city_weather(cities[i]);
    }

    return 0;
}