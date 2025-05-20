//FormAI DATASET v1.0 Category: Weather simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temperature_high, temperature_low, wind_speed, precipitation_chance;
    int day = 1;

    srand(time(NULL)); // set seed for random number generation

    printf("Welcome to Weather Simulator!\n");
    printf("Enter the highest temperature for the day: ");
    scanf("%d", &temperature_high);
    printf("Enter the lowest temperature for the day: ");
    scanf("%d", &temperature_low);
    printf("Enter the wind speed (in mph): ");
    scanf("%d", &wind_speed);
    printf("Enter the chance of precipitation (in percentage): ");
    scanf("%d", &precipitation_chance);

    printf("\n");

    while (day <= 7) { // simulate weather for 7 days
        int temperature = (rand() % (temperature_high - temperature_low)) + temperature_low;
        int wind_direction = rand() % 360;
        float precipitation = (float) precipitation_chance / 100;

        printf("Day %d:\n", day);
        printf("Temperature: %d\n", temperature);
        printf("Wind Speed: %dmph, Wind Direction: %d degrees\n", wind_speed, wind_direction);
        
        if (precipitation_chance == 0) {
            printf("No precipitation expected.\n\n");
        }
        else {
            if ((float) rand() / RAND_MAX < precipitation) {
                printf("Expecting precipitation today.\n\n");
            }
            else {
                printf("No precipitation expected.\n\n");
            }
        }

        day++; // move onto next day
    }

    printf("Thank you for using Weather Simulator!\n");

    return 0;
}