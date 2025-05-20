//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define DROPS 200
#define DROP_SPEED 2
#define RAIN_DELAY 500
#define RAIN_DURATION 5000
#define THUNDER_DELAY 10000

enum {
    CLEAR = 0,
    CLOUDY = 1,
    RAINING = 2,
    THUNDERSTORM = 3
};

void draw_weather(int weather) {
    switch (weather) {
        case CLEAR:
            printf(" ...\n");
            break;
        case CLOUDY:
            printf("...\n");
            break;
        case RAINING:
            printf(" R..\n");
            break;
        case THUNDERSTORM:
            printf(" T..\n");
            break;
    }
}

void simulate_weather(int duration) {
    srand(time(NULL));
    int weather = CLEAR;
    int rain_delay = rand() % RAIN_DELAY + 1;
    int thunder_delay = rand() % THUNDER_DELAY + 1;

    for (int i = 0; i < duration; i++) {
        system("clear");
        printf("Weather Simulation - Press Ctrl+C to exit\n");
        printf("Time: %d\n", i + 1);

        if (weather == CLEAR || weather == CLOUDY) {
            if (i >= rain_delay) {
                weather = RAINING;
                rain_delay = rand() % RAIN_DELAY + 1;
            }
        } else if (weather == RAINING) {
            if (i >= RAIN_DURATION) {
                weather = CLEAR;
            }
        } else if (weather == THUNDERSTORM) {
            if (i >= thunder_delay) {
                weather = RAINING;
                rain_delay = rand() % RAIN_DELAY + 1;
            }
        }

        draw_weather(weather);
        usleep(100000);
    }
}

int main() {
    int width, height;
    printf("Enter the terminal width (default 80): ");
    scanf("%d", &width);
    printf("Enter the terminal height (default 25): ");
    scanf("%d", &height);

    if (width <= 0 || height <= 0) {
        printf("Invalid terminal dimensions.\n");
        return 1;
    }

    int drops = DROPS;
    while (drops % width!= 0) {
        drops--;
    }

    simulate_weather(drops * height);

    return 0;
}