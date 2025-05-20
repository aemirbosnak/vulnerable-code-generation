//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WEATHER_TYPES 5

typedef struct {
    char name[30];
    float temperature;
    int humidity;
} WeatherType;

WeatherType weatherTypes[MAX_WEATHER_TYPES] = {
    {"Sunny", 25.0, 50},
    {"Rainy", 18.0, 80},
    {"Snowy", 5.0, 90},
    {"Cloudy", 15.0, 60},
    {"Thunderstorm", 20.0, 70}
};

void generateRandomWeather() {
    srand(time(NULL));
    int index = rand() % MAX_WEATHER_TYPES;
    printf("\nRandom Weather: %s, Temperature: %.1f deg C, Humidity: %d%%", weatherTypes[index].name, weatherTypes[index].temperature, weatherTypes[index].humidity);
}

int main() {
    int choice;

    printf("\nWelcome to the Weather Simulator!\n");
    printf("1. Generate Random Weather\n");
    printf("2. Exit\n");

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateRandomWeather();
                break;
            case 2:
                printf("Exiting the Weather Simulator...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}