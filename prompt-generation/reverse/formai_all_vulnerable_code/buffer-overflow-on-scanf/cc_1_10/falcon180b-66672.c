//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int temperature;
    int humidity;
    int windSpeed;
} Weather;

void generateWeather(Weather* weather) {
    srand(time(NULL));
    weather->temperature = rand() % 40 + 1;
    weather->humidity = rand() % 100;
    weather->windSpeed = rand() % 20 + 1;
}

void printWeather(Weather weather) {
    printf("Temperature: %d\n", weather.temperature);
    printf("Humidity: %d%%\n", weather.humidity);
    printf("Wind Speed: %d m/s\n", weather.windSpeed);
}

int main() {
    Weather weather;
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Generate weather\n");
        printf("2. Print weather\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                generateWeather(&weather);
                break;
            case 2:
                printWeather(weather);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 3);

    return 0;
}