//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOCATIONS 10
#define MAX_WEATHER_TYPES 5

typedef struct {
    char name[20];
    int temp;
    int humidity;
    int wind_speed;
    int precipitation;
    int weather_type;
} Weather;

void init_weather(Weather *weather) {
    weather->temp = rand() % 50 + 1;
    weather->humidity = rand() % 100;
    weather->wind_speed = rand() % 20 + 1;
    weather->precipitation = rand() % 5;
    weather->weather_type = rand() % MAX_WEATHER_TYPES;
}

void print_weather(Weather *weather) {
    printf("Location: %s\n", weather->name);
    printf("Temperature: %d\n", weather->temp);
    printf("Humidity: %d%%\n", weather->humidity);
    printf("Wind Speed: %d mph\n", weather->wind_speed);
    printf("Precipitation: %d mm\n", weather->precipitation);
    printf("Weather Type: %d\n", weather->weather_type);
    printf("\n");
}

int main() {
    srand(time(NULL));

    Weather weather[MAX_LOCATIONS];
    int num_locations = 0;

    while (num_locations < MAX_LOCATIONS) {
        printf("Enter a location name (or type 'q' to quit): ");
        scanf("%s", weather[num_locations].name);

        if (strcmp(weather[num_locations].name, "q") == 0) {
            break;
        }

        init_weather(&weather[num_locations]);
        num_locations++;
    }

    printf("Weather Report:\n");

    for (int i = 0; i < num_locations; i++) {
        print_weather(&weather[i]);
    }

    return 0;
}