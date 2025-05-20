//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    SUNNY,
    CLOUDY,
    RAINING,
    SNOWING
} weather_t;

struct weather_system {
    int seed;
    int day;
    int temperature;
    weather_t weather;
};

const char *weather_names[] = {
    "Sunny",
    "Cloudy",
    "Raining",
    "Snowing"
};

void init_weather_system(struct weather_system *system) {
    system->seed = time(NULL);
    system->day = 0;
    system->temperature = 20;
    system->weather = SUNNY;
}

void update_weather_system(struct weather_system *system) {
    srand(system->seed + system->day);
    int random_number = rand() % 100;
    if (random_number < 20) {
        system->weather = SUNNY;
    } else if (random_number < 40) {
        system->weather = CLOUDY;
    } else if (random_number < 60) {
        system->weather = RAINING;
    } else {
        system->weather = SNOWING;
    }
    system->day++;
    system->temperature += (rand() % 10) - 5;
}

void print_weather_system(struct weather_system *system) {
    printf("Day: %d\n", system->day);
    printf("Temperature: %d degrees Celsius\n", system->temperature);
    printf("Weather: %s\n", weather_names[system->weather]);
}

int main() {
    struct weather_system system;
    init_weather_system(&system);
    for (int i = 0; i < 100; i++) {
        update_weather_system(&system);
        print_weather_system(&system);
    }
    return 0;
}