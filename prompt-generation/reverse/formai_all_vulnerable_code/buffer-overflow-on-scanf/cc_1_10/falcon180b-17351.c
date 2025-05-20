//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_DAYS 7

struct Weather {
    char city[20];
    int temperature;
    int humidity;
    int precipitation;
};

void generateWeather(int day, struct Weather *weather) {
    int i;
    for (i = 0; i < NUM_CITIES; i++) {
        weather[i].temperature = rand() % (30 - 15 + 1) + 15;
        weather[i].humidity = rand() % (80 - 60 + 1) + 60;
        weather[i].precipitation = rand() % (10 - 0 + 1) + 0;
    }
}

void printWeather(int day, struct Weather *weather) {
    int i;
    for (i = 0; i < NUM_CITIES; i++) {
        printf("City: %s\n", weather[i].city);
        printf("Temperature: %d\n", weather[i].temperature);
        printf("Humidity: %d\n", weather[i].humidity);
        printf("Precipitation: %d\n", weather[i].precipitation);
        printf("\n");
    }
}

int main() {
    struct Weather weather[NUM_CITIES];
    int day;
    char city[20];
    int i;

    // Initialize city names
    for (i = 0; i < NUM_CITIES; i++) {
        printf("Enter city name %d: ", i + 1);
        scanf("%s", city);
        strcpy(weather[i].city, city);
    }

    // Simulate weather for 7 days
    for (day = 1; day <= NUM_DAYS; day++) {
        printf("\nDay %d\n", day);
        generateWeather(day, weather);
        printWeather(day, weather);
    }

    return 0;
}