//FormAI DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp, wind_speed, humidity, rain_chance, day;

    srand(time(0)); // seed random number generator with current time

    printf("Welcome to the Weather Simulator!\n\n");

    printf("Please enter the temperature (in degrees Celsius): ");
    scanf("%d", &temp);

    printf("Please enter the wind speed (in kilometers per hour): ");
    scanf("%d", &wind_speed);

    printf("Please enter the humidity (as a percentage): ");
    scanf("%d", &humidity);

    day = 1;
    while (day <= 7) { // simulate weather for 7 days
        printf("\nDay %d:\n", day);

        /* simulate temperature */
        int temp_variation = rand() % 6; // generate a random number between 0 and 5
        if (rand() % 2 == 0) {
            temp += temp_variation; // increase temperature
            printf("The temperature has increased by %d degrees Celsius. It is now %d degrees Celsius.\n", temp_variation, temp);
        } else {
            temp -= temp_variation; // decrease temperature
            printf("The temperature has decreased by %d degrees Celsius. It is now %d degrees Celsius.\n", temp_variation, temp);
        }

        /* simulate wind speed */
        int wind_variation = rand() % 6; // generate a random number between 0 and 5
        if (rand() % 2 == 0) {
            wind_speed += wind_variation; // increase wind speed
            printf("The wind speed has increased by %d kilometers per hour. It is now %d kilometers per hour.\n", wind_variation, wind_speed);
        } else {
            wind_speed -= wind_variation; // decrease wind speed
            printf("The wind speed has decreased by %d kilometers per hour. It is now %d kilometers per hour.\n", wind_variation, wind_speed);
        }

        /* simulate humidity */
        int humidity_variation = rand() % 6; // generate a random number between 0 and 5
        if (rand() % 2 == 0) {
            humidity += humidity_variation; // increase humidity
            printf("The humidity has increased by %d percentage points. It is now %d%%.\n", humidity_variation, humidity);
        } else {
            humidity -= humidity_variation; // decrease humidity
            printf("The humidity has decreased by %d percentage points. It is now %d%%.\n", humidity_variation, humidity);
        }

        /* simulate rain */
        int rain_threshold = 70 - (wind_speed / 10); // calculate rain threshold based on wind speed
        rain_chance = rand() % 101; // generate a random number between 0 and 100
        if (rain_chance > rain_threshold) {
            printf("It is currently raining.\n");
        } else {
            printf("It is currently not raining.\n");
        }

        day++; // move on to next day
    }

    return 0; // end program
}