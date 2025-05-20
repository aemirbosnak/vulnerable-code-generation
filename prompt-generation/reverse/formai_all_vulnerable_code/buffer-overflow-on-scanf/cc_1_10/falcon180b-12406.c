//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100

// structure to hold time travel information
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeTravel;

int main() {
    int numTimeTravels;
    TimeTravel timeTravels[MAX_TIME_TRAVELS];
    int i;

    // get number of time travels from user
    printf("Enter the number of time travels: ");
    scanf("%d", &numTimeTravels);

    // get time travel information from user
    for (i = 0; i < numTimeTravels; i++) {
        printf("Enter the year for time travel %d: ", i+1);
        scanf("%d", &timeTravels[i].year);

        printf("Enter the month for time travel %d: ", i+1);
        scanf("%d", &timeTravels[i].month);

        printf("Enter the day for time travel %d: ", i+1);
        scanf("%d", &timeTravels[i].day);

        printf("Enter the hour for time travel %d: ", i+1);
        scanf("%d", &timeTravels[i].hour);

        printf("Enter the minute for time travel %d: ", i+1);
        scanf("%d", &timeTravels[i].minute);

        printf("Enter the second for time travel %d: ", i+1);
        scanf("%d", &timeTravels[i].second);
    }

    // simulate time travel
    for (i = 0; i < numTimeTravels; i++) {
        time_t timeTravelTime = mktime(&(timeTravels[i]));
        printf("Time travel %d will occur at: %s", i+1, ctime(&timeTravelTime));
    }

    return 0;
}