//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME_TRAVELS 100
#define TIME_TRAVEL_SPEED 10

typedef struct TimeTravel {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeTravel;

int main() {
    srand(time(NULL));
    int numTimeTravels = rand() % MAX_TIME_TRAVELS + 1;
    TimeTravel timeTravels[MAX_TIME_TRAVELS];

    for (int i = 0; i < numTimeTravels; i++) {
        timeTravels[i].year = rand() % 1000 + 1;
        timeTravels[i].month = rand() % 12 + 1;
        timeTravels[i].day = rand() % 28 + 1;
        timeTravels[i].hour = rand() % 24;
        timeTravels[i].minute = rand() % 60;
        timeTravels[i].second = rand() % 60;
    }

    int choice;
    do {
        printf("Choose a time travel destination:\n");
        for (int i = 0; i < numTimeTravels; i++) {
            printf("%d. %d/%d/%d %d:%d:%d\n", i+1, timeTravels[i].year, timeTravels[i].month, timeTravels[i].day, timeTravels[i].hour, timeTravels[i].minute, timeTravels[i].second);
        }
        scanf("%d", &choice);
        choice--;

        double timeDifference = difftime(mktime(&(timeTravels[choice])), time(NULL));
        double timeTravelSpeed = TIME_TRAVEL_SPEED;
        double timeTravelDuration = timeDifference / timeTravelSpeed;

        printf("Time travel will take %.2f seconds.\n", timeTravelDuration);
        sleep(timeTravelDuration);

        printf("You have arrived at %d/%d/%d %d:%d:%d.\n", timeTravels[choice].year, timeTravels[choice].month, timeTravels[choice].day, timeTravels[choice].hour, timeTravels[choice].minute, timeTravels[choice].second);

    } while (choice >= 0 && choice < numTimeTravels);

    return 0;
}