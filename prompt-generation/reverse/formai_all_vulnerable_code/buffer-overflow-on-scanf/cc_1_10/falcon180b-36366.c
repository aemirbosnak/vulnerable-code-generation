//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void initWeather(int *weather);
void printWeather(int weather);

int main() {
    int weather;
    int choice;
    int seed;

    printf("Welcome to the Weather Simulation!\n");

    // Seed the random number generator with the current time
    seed = time(NULL);
    srand(seed);

    // Initialize the weather
    initWeather(&weather);

    // Main loop
    while (1) {
        printf("Current weather: ");
        printWeather(weather);

        printf("\nWhat would you like to do?\n");
        printf("1. Continue\n2. Change weather\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                break;
            case 2:
                initWeather(&weather);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void initWeather(int *weather) {
    // Initialize the weather to a random value between 1 and 6
    *weather = rand() % 6 + 1;
}

void printWeather(int weather) {
    switch (weather) {
        case 1:
            printf("Sunny\n");
            break;
        case 2:
            printf("Cloudy\n");
            break;
        case 3:
            printf("Rainy\n");
            break;
        case 4:
            printf("Thunderstorm\n");
            break;
        case 5:
            printf("Snowy\n");
            break;
        case 6:
            printf("Hurricane\n");
            break;
        default:
            printf("Invalid weather.\n");
    }
}