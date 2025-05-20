//LLAMA2-13B DATASET v1.0 Category: Weather simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WEATHER_MAX 5
#define WEATHER_FACTOR 3

typedef struct weather {
    char type[20];
    int temperature;
    int humidity;
} weather_t;

weather_t weather[WEATHER_MAX];
int weather_index = 0;

void update_weather() {
    int i;
    for (i = 0; i < WEATHER_MAX; i++) {
        if (weather_index % WEATHER_FACTOR == 0) {
            weather[i].temperature += 5;
        } else {
            weather[i].humidity += 10;
        }
        weather_index++;
    }
}

void print_weather() {
    int i;
    for (i = 0; i < WEATHER_MAX; i++) {
        printf("%s: %d°C, %d%%\n", weather[i].type, weather[i].temperature, weather[i].humidity);
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < WEATHER_MAX; i++) {
        weather[i].type[0] = 'S'; // Sunny
        weather[i].temperature = 25 + (rand() % 15) - 5;
        weather[i].humidity = 60 + (rand() % 10) - 5;
    }

    while (1) {
        update_weather();
        print_weather();
        printf("It's %s outside! What's your next move? (1/2/3/4/5): ", weather[weather_index - 1].type);
        int choice = getchar() - '1';
        if (choice == 0) {
            // Do something sunny 🌞
        } else if (choice == 1) {
            // Do something cloudy ☔️
        } else if (choice == 2) {
            // Do something rainy 🌧️
        } else if (choice == 3) {
            // Do something snowy ❄️
        } else if (choice == 4) {
            // Do something stormy 🌪️
        } else {
            // Do something unexpected 😱
        }
    }
    return 0;
}