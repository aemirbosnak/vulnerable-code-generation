//MISTRAL-7B DATASET v1.0 Category: Weather simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUN_RISE 6
#define SUN_SET 18

struct Weather {
    int temp;
    char condition[20];
};

int main() {
    srand(time(NULL));
    int day = 1, hour, minute;
    struct Weather *weather;

    weather = malloc(sizeof(struct Weather) * 30);

    printf("\n--- WEATHER SIMULATION ---\n\n");

    while (day <= 30) {
        weather[day - 1].temp = rand() % 30 + 10;

        switch (rand() % 5) {
            case 0: strcpy(weather[day - 1].condition, "Rainy"); break;
            case 1: strcpy(weather[day - 1].condition, "Sunny"); break;
            case 2: strcpy(weather[day - 1].condition, "Cloudy"); break;
            case 3: strcpy(weather[day - 1].condition, "Snowy"); break;
            case 4: strcpy(weather[day - 1].condition, "Misty"); break;
        }

        printf("\nDay %d:\n", day);

        for (hour = SUN_RISE; hour <= SUN_SET; hour++) {
            minute = rand() % 60;

            if (hour == SUN_RISE) {
                printf("\nSunrise at %d:%02d", hour, minute);
            }

            if (hour == SUN_SET) {
                printf("\nSunset at %d:%02d", hour, minute);
            }

            if ((hour > SUN_RISE) && (hour < SUN_SET)) {
                printf("\n%d:%02d - Temperature: %d°C, Condition: %s", hour, minute, weather[day - 1].temp, weather[day - 1].condition);
            }
        }

        day++;
    }

    free(weather);
    return 0;
}