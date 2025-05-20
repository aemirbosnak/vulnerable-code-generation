//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_TYPES 5
#define WEATHER_CHANCE 100
#define WEATHER_DURATION 5

enum weather_type {
    SUNNY,
    CLOUDY,
    RAINY,
    THUNDERSTORM,
    SNOWY
};

void weather_simulation(int duration) {
    enum weather_type current_weather = SUNNY;
    int weather_duration = 0;
    int weather_chance = rand() % WEATHER_CHANCE;

    printf("Welcome to the weather simulation!\n");
    printf("The weather will change every %d seconds.\n", WEATHER_DURATION);

    srand(time(NULL));
    while (duration-- > 0) {
        switch (current_weather) {
            case SUNNY:
                printf("The sun is shining!\n");
                break;
            case CLOUDY:
                printf("It's cloudy today.\n");
                break;
            case RAINY:
                printf("It's raining cats and dogs!\n");
                break;
            case THUNDERSTORM:
                printf("There's a thunderstorm brewing.\n");
                break;
            case SNOWY:
                printf("It's snowing heavily!\n");
                break;
        }

        weather_duration++;
        if (weather_duration == WEATHER_DURATION) {
            weather_duration = 0;
            int new_weather = rand() % WEATHER_TYPES;

            while (new_weather == current_weather) {
                new_weather = rand() % WEATHER_TYPES;
            }

            current_weather = (enum weather_type) new_weather;
        }

        if (current_weather == RAINY || current_weather == SNOWY) {
            printf("The precipitation is %d%%.\n", rand() % 101);
        }

        if (current_weather == THUNDERSTORM) {
            printf("There's a %d%% chance of lightning.\n", rand() % 101);
        }

        if (weather_chance == WEATHER_CHANCE / 2) {
            weather_chance = rand() % WEATHER_CHANCE;
            printf("The weather is changing...\n");
        }

        fflush(stdout);
        sleep(1);
    }
}

int main(int argc, char *argv[]) {
    int duration;

    printf("How long do you want the weather simulation to run (in seconds)? ");
    scanf("%d", &duration);

    weather_simulation(duration);

    return 0;
}