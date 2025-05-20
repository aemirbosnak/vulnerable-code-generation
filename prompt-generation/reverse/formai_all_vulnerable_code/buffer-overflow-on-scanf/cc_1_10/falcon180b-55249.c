//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 100
#define MIN_TEMPERATURE 0
#define MAX_HUMIDITY 100
#define MIN_HUMIDITY 0
#define MAX_WIND_SPEED 100
#define MIN_WIND_SPEED 0
#define MAX_CLOUDINESS 100
#define MIN_CLOUDINESS 0

#define NUM_DAYS 7
#define DAY_LENGTH 24 * 60 * 60

struct Weather {
    int temperature;
    int humidity;
    int wind_speed;
    int cloudiness;
};

void generate_weather(struct Weather *weather) {
    srand(time(NULL));
    weather->temperature = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
    weather->humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
    weather->wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
    weather->cloudiness = rand() % (MAX_CLOUDINESS - MIN_CLOUDINESS + 1) + MIN_CLOUDINESS;
}

void print_weather(const struct Weather *weather) {
    printf("Temperature: %d°C\n", weather->temperature);
    printf("Humidity: %d%%\n", weather->humidity);
    printf("Wind Speed: %d m/s\n", weather->wind_speed);
    printf("Cloudiness: %d%%\n", weather->cloudiness);
}

int main() {
    struct Weather weather[NUM_DAYS];
    char choice;

    printf("Welcome to the weather simulation!\n");
    printf("This program will simulate the weather for the next %d days.\n", NUM_DAYS);

    for (int i = 0; i < NUM_DAYS; i++) {
        generate_weather(&weather[i]);
        print_weather(&weather[i]);
        printf("Press any key to continue...\n");
        scanf("%c", &choice);
    }

    return 0;
}