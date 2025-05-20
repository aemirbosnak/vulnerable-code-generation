//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_WEEK 7

enum weather_type {
    SUNNY,
    CLOUDY,
    RAINY,
    SNOWY
};

struct weather_data {
    enum weather_type type;
    int temperature;
    int humidity;
};

void print_weather_data(struct weather_data* data) {
    printf("Weather type: ");
    switch(data->type) {
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
        default:
            printf("Unknown\n");
            break;
    }
    printf("Temperature: %d\n", data->temperature);
    printf("Humidity: %d\n", data->humidity);
}

struct weather_data generate_random_weather() {
    struct weather_data data;
    data.type = (enum weather_type) rand() % 4;
    data.temperature = rand() % 41 - 20;
    data.humidity = rand() % 101;
    return data;
}

void simulate_weather(int days) {
    srand(time(NULL));
    for(int i=0; i<days; i++) {
        struct weather_data weather = generate_random_weather();
        print_weather_data(&weather);
    }
}

int main() {
    int num_days;
    printf("Enter number of days to simulate: ");
    scanf("%d", &num_days);
    simulate_weather(num_days);
    return 0;
}