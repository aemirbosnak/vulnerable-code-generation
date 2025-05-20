//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define RAIN_CHANCE 0.2
#define RAIN_DURATION 5
#define RAIN_INTENSITY 0.1

// Define the weather conditions
typedef enum {
    CLEAR = 0,
    CLOUDY = 1,
    RAINY = 2
} Weather;

// Define the weather forecast
typedef struct {
    Weather condition;
    int duration;
} Forecast;

// Generate a random weather forecast
Forecast generate_forecast() {
    Forecast forecast;
    forecast.condition = CLEAR;
    forecast.duration = rand() % (HEIGHT - 1) + 1;
    return forecast;
}

// Print the weather forecast
void print_forecast(Forecast forecast) {
    printf("Today's weather forecast:\n");
    switch (forecast.condition) {
        case CLEAR:
            printf("Sunny with a chance of happiness.\n");
            break;
        case CLOUDY:
            printf("Cloudy with a chance of melancholy.\n");
            break;
        case RAINY:
            printf("Rainy with a chance of sadness.\n");
            break;
    }
    printf("This weather will last for %d days.\n", forecast.duration);
}

// Simulate the weather
void simulate_weather(int days) {
    srand(time(NULL));
    for (int i = 0; i < days; i++) {
        Forecast forecast = generate_forecast();
        print_forecast(forecast);
        for (int j = 0; j < forecast.duration; j++) {
            system("clear");
            printf("Day %d:\n", i + 1);
            switch (forecast.condition) {
                case CLEAR:
                    printf("The sun is shining brightly!\n");
                    break;
                case CLOUDY:
                    printf("The sky is covered with clouds.\n");
                    break;
                case RAINY:
                    printf("It's raining cats and dogs!\n");
                    break;
            }
            sleep(1);
        }
    }
}

int main() {
    int days;
    printf("How many days do you want to simulate the weather for? ");
    scanf("%d", &days);
    simulate_weather(days);
    return 0;
}