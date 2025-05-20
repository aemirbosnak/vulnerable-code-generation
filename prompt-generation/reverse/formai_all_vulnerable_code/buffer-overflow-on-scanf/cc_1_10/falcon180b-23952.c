//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 80
#define RAINDROPS 10

enum weather_type {
    SUNNY,
    RAINY,
    CLOUDY
};

enum weather_type current_weather = SUNNY;

void print_weather(enum weather_type weather) {
    switch(weather) {
        case SUNNY:
            printf("It's a beautiful day outside!\n");
            break;
        case RAINY:
            printf("It's raining cats and dogs!\n");
            break;
        case CLOUDY:
            printf("It's a bit cloudy today.\n");
            break;
    }
}

void simulate_weather(int duration) {
    int i;
    for(i=0; i<duration; i++) {
        if(current_weather == SUNNY) {
            if(rand() % 2 == 0) {
                current_weather = CLOUDY;
            }
        } else if(current_weather == CLOUDY) {
            if(rand() % 2 == 0) {
                current_weather = RAINY;
            }
        } else if(current_weather == RAINY) {
            if(rand() % 2 == 0) {
                current_weather = SUNNY;
            }
        }
        print_weather(current_weather);
        usleep(500000);
    }
}

int main() {
    int duration;
    printf("Enter the duration of the simulation in seconds: ");
    scanf("%d", &duration);
    srand(time(NULL));
    simulate_weather(duration);
    return 0;
}