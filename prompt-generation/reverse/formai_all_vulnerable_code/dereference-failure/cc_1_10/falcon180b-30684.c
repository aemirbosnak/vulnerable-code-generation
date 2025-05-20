//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define TEMP_MIN 0
#define TEMP_MAX 100
#define RAIN_MIN 0
#define RAIN_MAX 10
#define DELAY 100

typedef struct {
    int x, y;
    int temp;
    int rain;
} Weather;

Weather* create_weather(int x, int y) {
    Weather* weather = (Weather*)malloc(sizeof(Weather));
    weather->x = x;
    weather->y = y;
    weather->temp = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
    weather->rain = rand() % (RAIN_MAX - RAIN_MIN + 1) + RAIN_MIN;
    return weather;
}

void print_weather(Weather* weather) {
    printf(" ");
    for (int i = 0; i < weather->rain; i++) {
        printf("*");
    }
    printf(" ");
}

void update_weather(Weather* weather) {
    weather->temp = (weather->temp + rand() % 5 - 2) % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
    weather->rain = (weather->rain + rand() % 3 - 1) % (RAIN_MAX - RAIN_MIN + 1) + RAIN_MIN;
}

int main() {
    srand(time(NULL));
    Weather* weather = create_weather(0, 0);
    int x = 0, y = 0;
    while (1) {
        system("clear");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (i == y && j == x) {
                    print_weather(weather);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("Press any key to move.\n");
        char c = getchar();
        if (c == 'w' && y > 0) {
            y--;
        } else if (c =='s' && y < HEIGHT - 1) {
            y++;
        } else if (c == 'a' && x > 0) {
            x--;
        } else if (c == 'd' && x < WIDTH - 1) {
            x++;
        }
        update_weather(weather);
        usleep(DELAY * 1000);
    }
    return 0;
}