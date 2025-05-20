//FormAI DATASET v1.0 Category: Weather simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main() {
    int temperature, humidity, rainfall;
    int i, j;

    srand(time(0)); // for random number generation

    printf("Welcome to Weather Simulator!\n");
    printf("----------------------------------------\n");

    printf("Enter the temperature: ");
    scanf("%d", &temperature);
    if (temperature < -30 || temperature > 50) {
        printf("Invalid temperature range!");
        return 0;
    }

    printf("Enter the humidity: ");
    scanf("%d", &humidity);
    if (humidity < 0 || humidity > 100) {
        printf("Invalid humidity range!");
        return 0;
    }

    printf("Enter the rainfall: ");
    scanf("%d", &rainfall);
    if (rainfall < 0 || rainfall > 500) {
        printf("Invalid rainfall range!");
        return 0;
    }

    printf("\nGenerating weather data....\n\n");

    for (i = 1; i <= 7; i++) {
        printf("\nOn Day %d:\n", i);

        int random_temperature = (rand() % (10 + 1 - (-10))) - 10 + temperature;

        printf("Temperature: %d\n", random_temperature);

        int random_humidity = (rand() % (20 + 1 - (-20))) - 20 + humidity;

        printf("Humidity: %d\n", random_humidity);

        int random_rainfall = (rand() % (100 + 1 - (-100))) - 100 + rainfall;

        printf("Rainfall: %d\n", random_rainfall);

        if (random_temperature >= 40) {
            printf("Heat Warning!\n");
        } else if (random_temperature <= -10) {
            printf("Cold Warning!\n");
        }

        if (random_humidity >= 80) {
            printf("Humidity Warning!\n");
        } else if (random_humidity <= 20) {
            printf("Dryness Warning!\n");
        }

        if (random_rainfall >= 250) {
            printf("Heavy Rainfall Warning!\n");
        } else if (random_rainfall <= 50) {
            printf("Low Rainfall Warning!\n");
        }

        printf("----------------------------------------\n");

    }

    printf("\nThanks for using Weather Simulator!\n");

    return 0;
}