//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define DAYS 365
#define SUN_CHAR '*'
#define CLOUD_CHAR '.'
#define RAIN_CHAR 'X'
#define SNOW_CHAR 'O'

enum Weather {
    SUNNY = 0,
    CLOUDY = 1,
    RAINY = 2,
    SNOWY = 3
};

struct Day {
    int weather;
    int temperature;
    int humidity;
};

void init_weather(struct Day* weather, int seed) {
    srand(seed);
    for (int i = 0; i < DAYS; i++) {
        int weather_type = rand() % 4;
        switch (weather_type) {
            case 0:
                weather[i].weather = SUNNY;
                weather[i].temperature = rand() % 31 + 20;
                weather[i].humidity = rand() % 51;
                break;
            case 1:
                weather[i].weather = CLOUDY;
                weather[i].temperature = rand() % 26 + 15;
                weather[i].humidity = rand() % 76;
                break;
            case 2:
                weather[i].weather = RAINY;
                weather[i].temperature = rand() % 21 + 10;
                weather[i].humidity = rand() % 91;
                break;
            case 3:
                weather[i].weather = SNOWY;
                weather[i].temperature = rand() % 16 - 5;
                weather[i].humidity = rand() % 81;
                break;
        }
    }
}

void print_weather(struct Day* weather, int day) {
    printf("Day %d:\n", day + 1);
    printf("Weather: ");
    switch (weather[day].weather) {
        case SUNNY:
            printf("Sunny\n");
            break;
        case CLOUDY:
            printf("Cloudy\n");
            break;
        case RAINY:
            printf("Rainy\n");
            break;
        case SNOWY:
            printf("Snowy\n");
            break;
    }
    printf("Temperature: %d°C\n", weather[day].temperature);
    printf("Humidity: %d%%\n\n", weather[day].humidity);
}

void print_calendar(int day) {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);

    printf("Current date: %d-%02d-%02d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
    printf("Day %d of the year\n\n", day);
}

int main() {
    int seed;
    printf("Enter a seed for the random number generator: ");
    scanf("%d", &seed);

    struct Day weather[DAYS];
    init_weather(weather, seed);

    int day = 0;
    while (day < DAYS) {
        system("clear");
        print_calendar(day);
        print_weather(weather, day);
        day++;
        sleep(1);
    }

    return 0;
}