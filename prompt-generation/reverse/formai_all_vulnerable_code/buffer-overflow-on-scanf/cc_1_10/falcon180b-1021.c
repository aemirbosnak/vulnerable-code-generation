//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 10
#define MAX_YEAR 3000

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

int main() {
    Time currentTime;
    Time travelTimes[MAX_TIME_TRAVELS];
    int numTravels = 0;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    currentTime.year = t->tm_year + 1900;
    currentTime.month = t->tm_mon + 1;
    currentTime.day = t->tm_mday;
    currentTime.hour = t->tm_hour;
    currentTime.minute = t->tm_min;
    currentTime.second = t->tm_sec;

    printf("Current time: %d-%02d-%02d %02d:%02d:%02d\n",
           currentTime.year, currentTime.month, currentTime.day,
           currentTime.hour, currentTime.minute, currentTime.second);

    while (numTravels < MAX_TIME_TRAVELS) {
        printf("Enter destination year (between %d and %d): ",
               currentTime.year, MAX_YEAR);
        scanf("%d", &travelTimes[numTravels].year);

        printf("Enter destination month (between 1 and 12): ");
        scanf("%d", &travelTimes[numTravels].month);

        printf("Enter destination day (between 1 and 31): ");
        scanf("%d", &travelTimes[numTravels].day);

        printf("Enter destination hour (between 0 and 23): ");
        scanf("%d", &travelTimes[numTravels].hour);

        printf("Enter destination minute (between 0 and 59): ");
        scanf("%d", &travelTimes[numTravels].minute);

        printf("Enter destination second (between 0 and 59): ");
        scanf("%d", &travelTimes[numTravels].second);

        numTravels++;
    }

    printf("\nTime travel destinations:\n");
    for (int i = 0; i < numTravels; i++) {
        time_t travelTime = mktime(&(struct tm){0, 0, 0, travelTimes[i].day,
                                               travelTimes[i].month - 1,
                                               travelTimes[i].year - 1900,
                                               0, 0, -1});

        struct tm *t = localtime(&travelTime);
        printf("%d-%02d-%02d %02d:%02d:%02d\n",
               travelTimes[i].year, travelTimes[i].month, travelTimes[i].day,
               t->tm_hour, t->tm_min, t->tm_sec);
    }

    return 0;
}