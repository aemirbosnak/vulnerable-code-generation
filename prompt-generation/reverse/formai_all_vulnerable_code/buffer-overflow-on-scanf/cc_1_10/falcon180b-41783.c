//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature = 0;
    int humidity = 0;
    int windSpeed = 0;
    int cloudiness = 0;
    int chanceOfRain = 0;
    int chanceOfThunderstorm = 0;

    srand(time(NULL));

    printf("Welcome to the Weather Simulation!\n");
    printf("Please enter your location (e.g. New York, Paris, Tokyo): ");
    scanf("%s", &temperature);

    printf("Current temperature: %d degrees Celsius\n", temperature);

    if (temperature > 30) {
        humidity = rand() % 101;
        printf("Current humidity: %d%%\n", humidity);
    } else {
        humidity = rand() % 51;
        printf("Current humidity: %d%%\n", humidity);
    }

    windSpeed = rand() % 101;
    printf("Current wind speed: %d km/h\n", windSpeed);

    if (temperature >= 20 && temperature <= 30) {
        cloudiness = rand() % 101;
        printf("Current cloudiness: %d%%\n", cloudiness);
    } else if (temperature > 30) {
        cloudiness = rand() % 51;
        printf("Current cloudiness: %d%%\n", cloudiness);
    } else {
        cloudiness = rand() % 101;
        printf("Current cloudiness: %d%%\n", cloudiness);
    }

    if (temperature >= 25 && temperature <= 35) {
        chanceOfRain = rand() % 101;
        printf("Chance of rain: %d%%\n", chanceOfRain);
    } else {
        chanceOfRain = rand() % 51;
        printf("Chance of rain: %d%%\n", chanceOfRain);
    }

    if (temperature >= 30 && temperature <= 40) {
        chanceOfThunderstorm = rand() % 101;
        printf("Chance of thunderstorm: %d%%\n", chanceOfThunderstorm);
    } else {
        chanceOfThunderstorm = rand() % 51;
        printf("Chance of thunderstorm: %d%%\n", chanceOfThunderstorm);
    }

    return 0;
}