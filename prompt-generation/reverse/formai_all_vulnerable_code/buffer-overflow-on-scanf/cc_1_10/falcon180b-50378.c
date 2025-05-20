//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MIN_TEMP -40
#define MAX_TEMP 50
#define MIN_HUMIDITY 0
#define MAX_HUMIDITY 100
#define MIN_WIND_SPEED 0
#define MAX_WIND_SPEED 50
#define MIN_RAINFALL 0
#define MAX_RAINFALL 50

struct day {
    int temperature;
    int humidity;
    int wind_speed;
    int rainfall;
};

void generate_weather(struct day *weather, int num_days) {
    srand(time(NULL));

    for (int i = 0; i < num_days; i++) {
        weather[i].temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        weather[i].humidity = rand() % (MAX_HUMIDITY - MIN_HUMIDITY + 1) + MIN_HUMIDITY;
        weather[i].wind_speed = rand() % (MAX_WIND_SPEED - MIN_WIND_SPEED + 1) + MIN_WIND_SPEED;
        weather[i].rainfall = rand() % (MAX_RAINFALL - MIN_RAINFALL + 1) + MIN_RAINFALL;
    }
}

void print_weather(struct day *weather, int num_days) {
    printf("Weather forecast for the next %d days:\n", num_days);

    for (int i = 0; i < num_days; i++) {
        printf("Day %d: Temperature %d°C, Humidity %d%, Wind Speed %d km/h, Rainfall %d mm\n",
               i + 1, weather[i].temperature, weather[i].humidity, weather[i].wind_speed, weather[i].rainfall);
    }
}

int main() {
    int num_days;

    printf("Welcome to the weather simulation!\n");
    printf("How many days of weather forecast would you like to see? (1-365): ");
    scanf("%d", &num_days);

    if (num_days < 1 || num_days > MAX_DAYS) {
        printf("Invalid number of days. Please enter a number between 1 and %d.\n", MAX_DAYS);
        return 1;
    }

    struct day weather[num_days];

    generate_weather(weather, num_days);
    print_weather(weather, num_days);

    return 0;
}