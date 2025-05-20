//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int weather;
    int temperature;
    int humidity;
    int windSpeed;
    int cloudCover;

    printf("Welcome to the Weather Simulation Program!\n");
    printf("Please choose a weather condition to simulate:\n");
    printf("1. Sunny\n2. Cloudy\n3. Rainy\n4. Stormy\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            weather = "Sunny";
            temperature = rand() % 40 + 60;
            humidity = rand() % 50;
            windSpeed = rand() % 20 + 5;
            cloudCover = rand() % 10;
            printf("The weather is %s with a temperature of %d degrees Celsius, %d%% humidity, %d km/h wind speed, and %d%% cloud cover.\n", weather, temperature, humidity, windSpeed, cloudCover);
            break;
        case 2:
            weather = "Cloudy";
            temperature = rand() % 30 + 50;
            humidity = rand() % 60;
            windSpeed = rand() % 15 + 5;
            cloudCover = rand() % 20 + 50;
            printf("The weather is %s with a temperature of %d degrees Celsius, %d%% humidity, %d km/h wind speed, and %d%% cloud cover.\n", weather, temperature, humidity, windSpeed, cloudCover);
            break;
        case 3:
            weather = "Rainy";
            temperature = rand() % 40 + 50;
            humidity = rand() % 80;
            windSpeed = rand() % 25 + 10;
            cloudCover = rand() % 30 + 70;
            printf("The weather is %s with a temperature of %d degrees Celsius, %d%% humidity, %d km/h wind speed, and %d%% cloud cover.\n", weather, temperature, humidity, windSpeed, cloudCover);
            break;
        case 4:
            weather = "Stormy";
            temperature = rand() % 50 + 40;
            humidity = rand() % 90;
            windSpeed = rand() % 50 + 20;
            cloudCover = rand() % 20 + 80;
            printf("The weather is %s with a temperature of %d degrees Celsius, %d%% humidity, %d km/h wind speed, and %d%% cloud cover.\n", weather, temperature, humidity, windSpeed, cloudCover);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}