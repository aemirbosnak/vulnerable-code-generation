//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct weather {
    int temperature;
    int humidity;
    int wind_speed;
    int cloud_coverage;
    int precipitation;
} Weather;

void generate_weather(Weather *weather) {
    weather->temperature = rand() % 40 + 1;
    weather->humidity = rand() % 100;
    weather->wind_speed = rand() % 20 + 1;
    weather->cloud_coverage = rand() % 100;
    weather->precipitation = rand() % 3;
}

void print_weather(Weather weather) {
    printf("Temperature: %d degrees\n", weather.temperature);
    printf("Humidity: %d%%\n", weather.humidity);
    printf("Wind speed: %d km/h\n", weather.wind_speed);
    printf("Cloud coverage: %d%%\n", weather.cloud_coverage);
    if (weather.precipitation == 0) {
        printf("Precipitation: None\n");
    } else if (weather.precipitation == 1) {
        printf("Precipitation: Light rain\n");
    } else {
        printf("Precipitation: Heavy rain\n");
    }
}

void simulate_weather(int num_days) {
    srand(time(NULL));
    Weather weather;
    for (int i = 0; i < num_days; i++) {
        generate_weather(&weather);
        print_weather(weather);
        printf("\n");
    }
}

int main() {
    int num_days;
    printf("Enter number of days to simulate: ");
    scanf("%d", &num_days);
    if (num_days <= 0) {
        printf("Invalid number of days.\n");
        return 1;
    }
    simulate_weather(num_days);
    return 0;
}