//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME_TRAVELS 100
#define MAX_YEARS 1000
#define TIME_TRAVEL_DISTANCE 100

struct TimeTravel {
    int year;
    int distance;
    int result;
};

int main() {
    int numTimeTravels;
    int i;
    struct TimeTravel timeTravels[MAX_TIME_TRAVELS];

    printf("Enter the number of time travels: ");
    scanf("%d", &numTimeTravels);

    for (i = 0; i < numTimeTravels; i++) {
        printf("Enter the year for time travel %d: ", i+1);
        scanf("%d", &timeTravels[i].year);

        printf("Enter the distance for time travel %d: ", i+1);
        scanf("%d", &timeTravels[i].distance);
    }

    srand(time(NULL));

    for (i = 0; i < numTimeTravels; i++) {
        int randomResult = rand() % 2;
        timeTravels[i].result = randomResult;

        if (randomResult == 0) {
            printf("Time travel %d failed.\n", i+1);
        } else {
            int newYear = timeTravels[i].year + timeTravels[i].distance;

            if (newYear > MAX_YEARS) {
                printf("Time travel %d went too far into the future.\n", i+1);
            } else if (newYear < 0) {
                printf("Time travel %d went too far into the past.\n", i+1);
            } else {
                printf("Time travel %d succeeded. New year: %d.\n", i+1, newYear);
            }
        }
    }

    return 0;
}