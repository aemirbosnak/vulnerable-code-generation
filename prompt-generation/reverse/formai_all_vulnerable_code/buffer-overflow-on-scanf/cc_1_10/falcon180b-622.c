//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define weather conditions
#define SUNNY 1
#define CLOUDY 2
#define RAINY 3
#define THUNDERSTORM 4

// define temperature ranges
#define FREEZING 0
#define COLD 1
#define MILD 2
#define WARM 3
#define HOT 4

// define wind speeds
#define CALM 0
#define LIGHT 1
#define MODERATE 2
#define STRONG 3
#define VERY_STRONG 4

int current_weather_condition;
int current_temperature_range;
int current_wind_speed;

void generate_weather() {
    srand(time(NULL));

    current_weather_condition = rand() % 4;
    current_temperature_range = rand() % 5;
    current_wind_speed = rand() % 5;

    if (current_weather_condition == SUNNY) {
        printf("The sun is shining brightly!\n");
    } else if (current_weather_condition == CLOUDY) {
        printf("The sky is overcast with clouds.\n");
    } else if (current_weather_condition == RAINY) {
        printf("It's raining outside.\n");
    } else if (current_weather_condition == THUNDERSTORM) {
        printf("There's a thunderstorm raging!\n");
    }

    if (current_temperature_range == FREEZING) {
        printf("It's freezing cold!\n");
    } else if (current_temperature_range == COLD) {
        printf("It's quite cold outside.\n");
    } else if (current_temperature_range == MILD) {
        printf("The temperature is mild.\n");
    } else if (current_temperature_range == WARM) {
        printf("It's warm outside.\n");
    } else if (current_temperature_range == HOT) {
        printf("It's scorching hot!\n");
    }

    if (current_wind_speed == CALM) {
        printf("The air is still and calm.\n");
    } else if (current_wind_speed == LIGHT) {
        printf("There's a light breeze blowing.\n");
    } else if (current_wind_speed == MODERATE) {
        printf("The wind is blowing moderately.\n");
    } else if (current_wind_speed == STRONG) {
        printf("The wind is blowing strongly.\n");
    } else if (current_wind_speed == VERY_STRONG) {
        printf("The wind is blowing very strongly!\n");
    }
}

int main() {
    int num_iterations;

    printf("Welcome to the futuristic weather simulation!\n");
    printf("How many iterations would you like to run? ");
    scanf("%d", &num_iterations);

    for (int i = 0; i < num_iterations; i++) {
        generate_weather();
    }

    return 0;
}