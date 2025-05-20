//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DAYS_PER_YEAR 365
#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60
#define SECONDS_PER_MINUTE 60

struct weather {
    int temperature;
    int humidity;
    int wind_speed;
};

void simulate_weather(struct weather *weather) {
    int day = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;

    srand(time(NULL));

    while (day < DAYS_PER_YEAR) {
        while (hour < HOURS_PER_DAY) {
            while (minute < MINUTES_PER_HOUR) {
                while (second < SECONDS_PER_MINUTE) {
                    int temperature_change = rand() % 10 - 5;
                    int humidity_change = rand() % 10 - 5;
                    int wind_speed_change = rand() % 10 - 5;

                    weather->temperature += temperature_change;
                    weather->humidity += humidity_change;
                    weather->wind_speed += wind_speed_change;

                    second++;
                }
                minute++;
            }
            hour++;
        }
        day++;
    }
}

int main() {
    struct weather weather;
    simulate_weather(&weather);

    printf("Temperature: %d\n", weather.temperature);
    printf("Humidity: %d\n", weather.humidity);
    printf("Wind Speed: %d\n", weather.wind_speed);

    return 0;
}