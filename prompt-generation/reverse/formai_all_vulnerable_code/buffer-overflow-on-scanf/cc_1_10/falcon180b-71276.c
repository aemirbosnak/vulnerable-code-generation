//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int temperature;
    int humidity;
    int wind_speed;
} Weather;

// Function to generate random weather conditions
void generate_weather(Weather *weather) {
    srand(time(NULL));
    weather->temperature = rand() % 41 - 20;
    weather->humidity = rand() % 101;
    weather->wind_speed = rand() % 21;
}

int main() {
    int choice;
    Weather current_weather;

    do {
        system("clear");
        printf("Weather Simulation\n");
        printf("1. Generate weather\n");
        printf("2. Display current weather\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_weather(&current_weather);
                printf("Current weather: Temperature - %d degrees Celsius, Humidity - %d%% and Wind Speed - %d km/h\n", current_weather.temperature, current_weather.humidity, current_weather.wind_speed);
                break;

            case 2:
                printf("Current weather: Temperature - %d degrees Celsius, Humidity - %d%% and Wind Speed - %d km/h\n", current_weather.temperature, current_weather.humidity, current_weather.wind_speed);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice!= 3);

    return 0;
}