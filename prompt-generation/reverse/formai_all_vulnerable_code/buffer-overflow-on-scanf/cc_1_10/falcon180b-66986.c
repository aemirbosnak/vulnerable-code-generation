//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_CITIES 10
#define MAX_DAYS 365

typedef struct {
    char name[20];
    int x;
    int y;
} City;

typedef struct {
    int temperature;
    int humidity;
    int windSpeed;
} Weather;

City cities[MAX_CITIES];
Weather weather[MAX_DAYS];

void initCities() {
    int i;
    for (i = 0; i < MAX_CITIES; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        printf("Enter city coordinates (x, y): ");
        scanf("%d %d", &cities[i].x, &cities[i].y);
    }
}

void generateWeather() {
    int i;
    srand(time(NULL));
    for (i = 0; i < MAX_DAYS; i++) {
        weather[i].temperature = rand() % 41 - 20;
        weather[i].humidity = rand() % 81;
        weather[i].windSpeed = rand() % 21;
    }
}

void printWeather() {
    int i;
    printf("Weather forecast for the next 365 days:\n");
    for (i = 0; i < MAX_DAYS; i++) {
        printf("%d: %s - Temperature: %d°C, Humidity: %d%, Wind Speed: %d km/h\n", i+1, weather[i].temperature >= 0? "Sunny" : "Rainy", abs(weather[i].temperature), weather[i].humidity, weather[i].windSpeed);
    }
}

int main() {
    initCities();
    generateWeather();
    printWeather();
    return 0;
}