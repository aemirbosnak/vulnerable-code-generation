//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_WEATHERS 4

typedef struct {
    char name[20];
    int temperature;
    int humidity;
} City;

typedef struct {
    char name[20];
    int icon;
    int temperature;
    int humidity;
    int windSpeed;
} Weather;

City cities[NUM_CITIES] = {
    {"New York", 20},
    {"Los Angeles", 25},
    {"Chicago", 15},
    {"Houston", 30},
    {"Miami", 28}
};

Weather weathers[NUM_WEATHERS] = {
    {"Sunny", 0, 25, 50, 5},
    {"Cloudy", 1, 18, 80, 10},
    {"Rainy", 2, 15, 90, 20},
    {"Stormy", 3, 12, 95, 30}
};

void generateWeather(City* city, Weather* weather) {
    city->temperature = weather->temperature;
    city->humidity = weather->humidity;
}

void simulateWeather(int duration) {
    srand(time(NULL));

    for (int i = 0; i < NUM_CITIES; i++) {
        int weatherIndex = rand() % NUM_WEATHERS;
        generateWeather(&cities[i], &weathers[weatherIndex]);

        printf("Current weather in %s: %s, %d°C, %d%% humidity\n",
               cities[i].name,
               weathers[weatherIndex].name,
               cities[i].temperature,
               cities[i].humidity);
    }

    for (int i = 0; i < duration; i++) {
        for (int j = 0; j < NUM_CITIES; j++) {
            int weatherIndex = rand() % NUM_WEATHERS;
            generateWeather(&cities[j], &weathers[weatherIndex]);

            printf("Current weather in %s: %s, %d°C, %d%% humidity\n",
                   cities[j].name,
                   weathers[weatherIndex].name,
                   cities[j].temperature,
                   cities[j].humidity);
        }
    }
}

int main() {
    int duration;

    printf("Enter the duration of the simulation (in seconds): ");
    scanf("%d", &duration);

    simulateWeather(duration);

    return 0;
}