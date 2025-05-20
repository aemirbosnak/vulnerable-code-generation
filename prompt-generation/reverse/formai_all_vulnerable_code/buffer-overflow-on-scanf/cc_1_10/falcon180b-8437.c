//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAIN_LEVEL 10
#define MAX_TEMP_LEVEL 100
#define MIN_TEMP_LEVEL 0
#define NUM_HOURS 24

struct Weather {
    int temperature;
    int humidity;
    int rain;
};

void print_weather(struct Weather weather) {
    printf("Temperature: %d\n", weather.temperature);
    printf("Humidity: %d\n", weather.humidity);
    printf("Rain: %d\n", weather.rain);
}

void simulate_weather(struct Weather *weather, int hours) {
    srand(time(NULL));
    for (int i = 0; i < hours; i++) {
        if (weather->temperature >= MAX_TEMP_LEVEL) {
            weather->temperature = MAX_TEMP_LEVEL;
        } else if (weather->temperature <= MIN_TEMP_LEVEL) {
            weather->temperature = MIN_TEMP_LEVEL;
        } else {
            weather->temperature += rand() % 5 - 2;
        }

        if (weather->humidity >= MAX_RAIN_LEVEL) {
            weather->rain = 1;
        } else if (weather->humidity <= 0) {
            weather->rain = 0;
        } else {
            weather->humidity += rand() % 3 - 1;
            if (weather->humidity >= MAX_RAIN_LEVEL) {
                weather->rain = 1;
            } else {
                weather->rain = 0;
            }
        }
    }
}

int main() {
    struct Weather weather = {
       .temperature = rand() % (MAX_TEMP_LEVEL - MIN_TEMP_LEVEL) + MIN_TEMP_LEVEL,
       .humidity = rand() % MAX_RAIN_LEVEL,
       .rain = 0
    };

    int hours;
    printf("Enter number of hours to simulate: ");
    scanf("%d", &hours);

    simulate_weather(&weather, hours);

    print_weather(weather);

    return 0;
}