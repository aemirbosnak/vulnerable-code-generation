//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int temperature = 0;
int humidity = 0;
int windSpeed = 0;
int cloudCoverage = 0;
int precipitation = 0;

void updateWeather() {
    int random = rand() % 100;
    if (random < 30) {
        temperature++;
    } else if (random < 60) {
        humidity++;
    } else if (random < 80) {
        windSpeed++;
    } else if (random < 90) {
        cloudCoverage++;
    } else {
        precipitation++;
    }
}

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to the Weather Simulator!\n");
    printf("What kind of weather do you want to simulate?\n");
    printf("1. Sunny\n");
    printf("2. Cloudy\n");
    printf("3. Rainy\n");
    printf("4. Stormy\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("The weather is sunny.\n");
            break;
        case 2:
            printf("The weather is cloudy.\n");
            break;
        case 3:
            printf("The weather is rainy.\n");
            break;
        case 4:
            printf("The weather is stormy.\n");
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    while (1) {
        updateWeather();
        printf("Temperature: %d\n", temperature);
        printf("Humidity: %d\n", humidity);
        printf("Wind Speed: %d\n", windSpeed);
        printf("Cloud Coverage: %d\n", cloudCoverage);
        printf("Precipitation: %d\n", precipitation);
        printf("Press any key to continue...\n");
        getchar();
    }

    return 0;
}