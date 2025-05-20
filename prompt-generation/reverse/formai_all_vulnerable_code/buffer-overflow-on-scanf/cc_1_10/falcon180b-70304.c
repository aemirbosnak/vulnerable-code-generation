//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1000

struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} time_travel;

int main() {
    srand(time(NULL));
    int random_year = rand() % (MAX_YEAR - MIN_YEAR + 1) + MIN_YEAR;
    time_travel.year = random_year;
    time_travel.month = 1;
    time_travel.day = 1;
    time_travel.hour = 0;
    time_travel.minute = 0;
    time_travel.second = 0;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d.\n", time_travel.year);

    while (1) {
        printf("Enter your destination year (between %d and %d): ", MIN_YEAR, MAX_YEAR);
        scanf("%d", &time_travel.year);

        if (time_travel.year < MIN_YEAR || time_travel.year > MAX_YEAR) {
            printf("Invalid year entered.\n");
            continue;
        }

        printf("You are now traveling through time to the year %d...\n", time_travel.year);

        for (int i = time_travel.year; i > MIN_YEAR; i--) {
            printf("%d...\n", i);
            sleep(1);
        }

        printf("You have arrived in the year %d!\n", time_travel.year);

        while (1) {
            printf("What would you like to do?\n");
            printf("1. Explore\n");
            printf("2. Return to the present\n");
            printf("3. Travel to a different year\n");
            scanf("%d", &time_travel.year);

            if (time_travel.year < MIN_YEAR || time_travel.year > MAX_YEAR) {
                printf("Invalid year entered.\n");
                continue;
            }

            if (time_travel.year == time_travel.year) {
                printf("You are already in the year %d.\n", time_travel.year);
                continue;
            }

            if (time_travel.year < time_travel.year) {
                printf("You cannot travel to a year in the past.\n");
                continue;
            }

            break;
        }
    }

    return 0;
}