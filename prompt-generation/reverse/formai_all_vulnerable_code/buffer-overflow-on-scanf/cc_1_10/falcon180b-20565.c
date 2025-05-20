//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int temperature;
    int humidity;
    int windSpeed;
    int cloudCover;
} WeatherData;

WeatherData generateWeather() {
    WeatherData weather;
    weather.temperature = rand() % 100;
    weather.humidity = rand() % 101;
    weather.windSpeed = rand() % 101;
    weather.cloudCover = rand() % 101;
    return weather;
}

void printWeather(WeatherData weather) {
    printf("Temperature: %d\n", weather.temperature);
    printf("Humidity: %d%%\n", weather.humidity);
    printf("Wind Speed: %d mph\n", weather.windSpeed);
    printf("Cloud Cover: %d%%\n", weather.cloudCover);
}

int main() {
    srand(time(NULL));
    WeatherData weather;
    int choice;
    while (1) {
        printf("Enter 1 to generate new weather data\n");
        printf("Enter 2 to print current weather data\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            weather = generateWeather();
            printf("New weather data generated:\n");
            printWeather(weather);
            break;
        case 2:
            printWeather(weather);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}