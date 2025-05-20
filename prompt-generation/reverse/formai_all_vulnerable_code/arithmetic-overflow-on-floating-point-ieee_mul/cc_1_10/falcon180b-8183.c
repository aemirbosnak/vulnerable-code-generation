//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME_TRAVELS 10
#define TIME_TRAVEL_SPEED 1000

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

void print_time(Time t) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", t.year, t.month, t.day, t.hour, t.minute, t.second);
}

int main() {
    Time current_time;
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    current_time.year = t->tm_year + 1900;
    current_time.month = t->tm_mon + 1;
    current_time.day = t->tm_mday;
    current_time.hour = t->tm_hour;
    current_time.minute = t->tm_min;
    current_time.second = t->tm_sec;

    printf("Current time: ");
    print_time(current_time);

    int num_time_travels;
    printf("Enter number of time travels (max %d): ", MAX_TIME_TRAVELS);
    scanf("%d", &num_time_travels);

    for (int i = 0; i < num_time_travels; i++) {
        printf("Enter destination year: ");
        int year;
        scanf("%d", &year);

        printf("Enter destination month (1-12): ");
        int month;
        scanf("%d", &month);

        printf("Enter destination day: ");
        int day;
        scanf("%d", &day);

        printf("Enter destination hour: ");
        int hour;
        scanf("%d", &hour);

        printf("Enter destination minute: ");
        int minute;
        scanf("%d", &minute);

        printf("Enter destination second: ");
        int second;
        scanf("%d", &second);

        Time destination_time;
        destination_time.year = year;
        destination_time.month = month;
        destination_time.day = day;
        destination_time.hour = hour;
        destination_time.minute = minute;
        destination_time.second = second;

        double time_difference = difftime(mktime(&destination_time), now);
        int time_travel_duration = (int) (time_difference * TIME_TRAVEL_SPEED);

        printf("Time travel duration: %d seconds\n", time_travel_duration);
        for (int j = 0; j < time_travel_duration; j++) {
            printf(".");
            fflush(stdout);
            usleep(100000);
        }

        printf("\nArrived at destination time: ");
        print_time(destination_time);
    }

    return 0;
}