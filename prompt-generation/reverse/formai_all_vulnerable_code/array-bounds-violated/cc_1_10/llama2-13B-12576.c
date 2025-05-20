//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WEATHER_TYPES 6
#define DAY_LENGTH 24

typedef struct {
    char day[7];
    int temperature_min[7];
    int temperature_max[7];
    int humidity[7];
    int weather_code[7];
} weather_data_t;

weather_data_t weather_data[7];

void init_weather_data(void) {
    int i;
    for (i = 0; i < 7; i++) {
        weather_data[i].day[0] = 'S'; // Sunday
        weather_data[i].temperature_min[0] = (i % 2) * 10 + 10;
        weather_data[i].temperature_max[0] = (i % 2) * 20 + 20;
        weather_data[i].humidity[0] = (i % 3) * 10 + 20;
        weather_data[i].weather_code[0] = i % 2 ? 100 : 200; // 100: sunny, 200: cloudy
    }
}

void print_weather(void) {
    int i;
    for (i = 0; i < 7; i++) {
        printf("%c: %d°C - %d°C, %d%% humidity, %d weather\n",
               weather_data[i].day,
               weather_data[i].temperature_min[i],
               weather_data[i].temperature_max[i],
               weather_data[i].humidity[i],
               weather_data[i].weather_code[i]);
    }
}

int main(void) {
    srand(time(NULL));
    init_weather_data();

    for (int i = 0; i < DAY_LENGTH; i++) {
        int weather_code = rand() % WEATHER_TYPES;
        weather_data[i % 7].weather_code[i] = weather_code;
    }

    print_weather();

    return 0;
}