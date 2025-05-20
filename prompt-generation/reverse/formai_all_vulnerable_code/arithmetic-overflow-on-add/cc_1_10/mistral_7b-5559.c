//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EPOCH_JAN_1_1970 2208988800L /* Number of seconds elapsed since 01/01/1970 */

struct time_trip {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

void time_travel(long int seconds) {
    struct tm *ptm;
    struct time_trip trip;

    time_t current_time = time(NULL);
    time_t target_time = EPOCH_JAN_1_1970 + seconds;

    ptm = localtime(&target_time);

    trip.year = 1900 + ptm->tm_year;
    trip.month = 1 + ptm->tm_mon;
    trip.day = ptm->tm_mday;
    trip.hour = ptm->tm_hour;
    trip.minute = ptm->tm_min;
    trip.second = ptm->tm_sec;

    printf("\nTime Travel Log:\n");
    printf("Destination Reached:\n");
    printf("Year: %d\n", trip.year);
    printf("Month: %d\n", trip.month);
    printf("Day: %d\n", trip.day);
    printf("Hour: %d\n", trip.hour);
    printf("Minute: %d\n", trip.minute);
    printf("Second: %d\n", trip.second);
}

int main() {
    long int target_time;

    printf("Enter the number of seconds you want to travel from the current time:\n");
    scanf("%ld", &target_time);

    time_travel(target_time);

    return EXIT_SUCCESS;
}