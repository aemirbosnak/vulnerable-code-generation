//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

int main() {
    int numTravels, i;
    Time travels[MAX_TIME_TRAVELS];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("How many time travels would you like to simulate? ");
    scanf("%d", &numTravels);

    for (i = 0; i < numTravels; i++) {
        printf("Enter the details for time travel #%d:\n", i + 1);
        printf("Year: ");
        scanf("%d", &travels[i].year);
        printf("Month: ");
        scanf("%d", &travels[i].month);
        printf("Day: ");
        scanf("%d", &travels[i].day);
        printf("Hour: ");
        scanf("%d", &travels[i].hour);
        printf("Minute: ");
        scanf("%d", &travels[i].minute);
        printf("Second: ");
        scanf("%d", &travels[i].second);
    }

    printf("\n");
    printf("Time Travel Simulation:\n");
    printf("=========================\n");

    for (i = 0; i < numTravels; i++) {
        time_t currentTime = time(NULL);
        struct tm *t = localtime(&currentTime);
        t->tm_year += travels[i].year - 1900;
        t->tm_mon += travels[i].month - 1;
        t->tm_mday = travels[i].day;
        t->tm_hour = travels[i].hour;
        t->tm_min = travels[i].minute;
        t->tm_sec = travels[i].second;

        time_t travelTime = mktime(t);
        printf("Travel #%d: %s", i + 1, ctime(&travelTime));
    }

    return 0;
}