//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    int hour;
    int minute;
    int second;
} Time;

Time current_time() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    Time time = {
        .date = {
            .year = tm->tm_year + 1900,
            .month = tm->tm_mon + 1,
            .day = tm->tm_mday,
        },
        .hour = tm->tm_hour,
        .minute = tm->tm_min,
        .second = tm->tm_sec,
    };
    return time;
}

void print_time(Time time) {
    printf("%d-%02d-%02d %02d:%02d:%02d\n", time.date.year, time.date.month, time.date.day, time.hour, time.minute, time.second);
}

int main() {
    Time time = current_time();
    print_time(time);

    int years_to_travel;
    printf("Enter the number of years to travel: ");
    scanf("%d", &years_to_travel);

    time.date.year += years_to_travel;
    print_time(time);

    return 0;
}