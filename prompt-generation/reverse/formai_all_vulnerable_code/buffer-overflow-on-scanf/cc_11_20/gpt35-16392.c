//FormAI DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

enum weather_condition { sunny, cloudy, rainy, stormy };

int main() {
    int temperature, humidity;
    enum weather_condition current_condition;
    srand(time(NULL));

    printf("Welcome to the Weather Simulation Program!\n");
    printf("Please enter the current temperature in Celsius: ");
    scanf("%d", &temperature);
    printf("Please enter the current humidity (0-100): ");
    scanf("%d", &humidity);

    if (temperature > 30 && humidity > 70) {
        current_condition = stormy;
    } else if (temperature > 25 && humidity > 50) {
        current_condition = rainy;
    } else if (temperature > 20 && humidity > 40) {
        current_condition = cloudy;
    } else {
        current_condition = sunny;
    }

    printf("\nCurrent Conditions:\n");

    switch (current_condition) {
        case sunny:
            printf("Weather: Sunny\n");
            printf("Temperature: %dC\n", temperature);
            printf("Humidity: %d%%\n", humidity);
            break;
        case cloudy:
            printf("Weather: Cloudy\n");
            printf("Temperature: %dC\n", temperature);
            printf("Humidity: %d%%\n", humidity);
            break;
        case rainy:
            printf("Weather: Rainy\n");
            printf("Temperature: %dC\n", temperature);
            printf("Humidity: %d%%\n", humidity);
            printf("Amount of rainfall: %dmm\n", rand() % 20);
            break;
        case stormy:
            printf("Weather: Stormy\n");
            printf("Temperature: %dC\n", temperature);
            printf("Humidity: %d%%\n", humidity);
            printf("Storm severity: %d/10\n", rand() % 11);
            break;
    }

    return 0;
}