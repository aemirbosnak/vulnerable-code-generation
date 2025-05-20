//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);

    int year = local_time->tm_year + 1900;
    int month = local_time->tm_mon + 1;
    int day = local_time->tm_mday;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Today is %d/%d/%d\n\n", month, day, year);

    printf("Choose a year to travel to: ");
    int travel_year;
    scanf("%d", &travel_year);

    if (travel_year >= year) {
        printf("You can only travel to years in the past. Please choose a year before %d.\n", year);
        exit(1);
    }

    printf("Travelling to %d...\n\n", travel_year);

    int i;
    for (i = year; i >= travel_year; i--) {
        printf("Year: %d\n", i);
        printf("----------------------\n");

        if (i == 1912) {
            printf("Titanic sinks - April 15, 1912\n\n");
        }
        if (i == 1945) {
            printf("World War II ends - September 2, 1945\n\n");
        }
        if (i == 1969) {
            printf("Neil Armstrong walks on the moon - July 20, 1969\n\n");
        }
        if (i == 1989) {
            printf("Berlin Wall falls - November 9, 1989\n\n");
        }
        if (i == 2001) {
            printf("September 11 attacks - September 11, 2001\n\n");
        }
    }

    printf("You have arrived in %d! Enjoy your trip!\n", travel_year);

    return 0;
}