//FormAI DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temperature = (rand() % 60) - 20;
    int humidity = rand() % 100;
    int wind_speed = rand() % 100;

    printf("Welcome to the Weather Simulation Program\n");
    printf("----------------------------------------\n\n");

    printf("Today's weather conditions:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n\n", wind_speed);

    printf("Enter a city name to simulate weather for:\n");
    char city[50];
    scanf("%s", city);

    printf("\nSimulating weather conditions for %s...\n\n", city);

    int city_temperature = temperature + (rand() % 20) - 10;
    int city_humidity = humidity + (rand() % 20) - 10;
    int city_wind_speed = wind_speed + (rand() % 20) - 10;

    printf("Today's weather conditions for %s:\n", city);
    printf("Temperature: %d degrees Celsius\n", city_temperature);
    printf("Humidity: %d%%\n", city_humidity);
    printf("Wind Speed: %d km/h\n", city_wind_speed);

    printf("\nDo you want to see a 5-day forecast for %s? (y/n)\n", city);
    char answer;
    scanf(" %c", &answer);

    if(answer == 'y') {
        printf("\nHere is the 5-day forecast for %s:\n\n", city);
        for(int i = 1; i <= 5; i++) {
            int forecast_temperature = city_temperature + (rand() % 10) - 5;
            int forecast_humidity = city_humidity + (rand() % 10) - 5;
            int forecast_wind_speed = city_wind_speed + (rand() % 10) - 5;

            printf("Day %d:\n", i);
            printf("    Temperature: %d degrees Celsius\n", forecast_temperature);
            printf("    Humidity: %d%%\n", forecast_humidity);
            printf("    Wind Speed: %d km/h\n\n", forecast_wind_speed);
        }
    } else {
        printf("\nThank you for using the Weather Simulation Program!\n");
    }

    return 0;
}