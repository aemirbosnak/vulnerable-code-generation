//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 20
#define RAINDROPS 50

struct Weather {
    int temperature;
    int humidity;
    int cloudiness;
    int wind_speed;
    int wind_direction;
    int raining;
};

void init_weather(struct Weather *weather) {
    weather->temperature = rand() % 30 + 1;
    weather->humidity = rand() % 10 + 1;
    weather->cloudiness = rand() % 5 + 1;
    weather->wind_speed = rand() % 10 + 1;
    weather->wind_direction = rand() % 360;
    weather->raining = 0;
}

void update_weather(struct Weather *weather) {
    weather->temperature += rand() % 5 - 2;
    weather->humidity += rand() % 5 - 2;
    weather->cloudiness += rand() % 5 - 2;
    weather->wind_speed += rand() % 5 - 2;
    weather->wind_direction += rand() % 10 - 5;

    if (weather->cloudiness > 8 && weather->temperature > 10) {
        weather->raining = 1;
    } else {
        weather->raining = 0;
    }
}

void print_weather(struct Weather *weather) {
    printf("Weather:\n");
    printf("Temperature: %d°C\n", weather->temperature);
    printf("Humidity: %d%%\n", weather->humidity);
    printf("Cloudiness: %d/%d\n", weather->cloudiness, 5);
    printf("Wind speed: %d m/s\n", weather->wind_speed);
    printf("Wind direction: %d°\n", weather->wind_direction);
    if (weather->raining) {
        printf("Rain: Yes\n");
    } else {
        printf("Rain: No\n");
    }
}

void simulate_weather(int duration) {
    struct Weather weather;
    init_weather(&weather);

    int i;
    for (i = 0; i < duration; i++) {
        update_weather(&weather);
        print_weather(&weather);
        printf("\n");
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