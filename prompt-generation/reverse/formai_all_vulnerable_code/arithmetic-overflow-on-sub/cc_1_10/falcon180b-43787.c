//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s destination_time\n", argv[0]);
        return 1;
    }

    Time destination;
    if (sscanf(argv[1], "%04d-%02d-%02d %02d:%02d:%02d", &destination.year, &destination.month, &destination.day, &destination.hour, &destination.minute, &destination.second)!= 6) {
        printf("Invalid destination time\n");
        return 1;
    }

    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    Time departure = {
       .year = tm_now->tm_year + 1900,
       .month = tm_now->tm_mon + 1,
       .day = tm_now->tm_mday,
       .hour = tm_now->tm_hour,
       .minute = tm_now->tm_min,
       .second = tm_now->tm_sec
    };

    int years = destination.year - departure.year;
    int months = destination.month - departure.month;
    int days = destination.day - departure.day;
    int hours = destination.hour - departure.hour;
    int minutes = destination.minute - departure.minute;
    int seconds = destination.second - departure.second;

    if (years < 0 || months < 0 || days < 0 || hours < 0 || minutes < 0 || seconds < 0) {
        printf("Cannot travel back in time\n");
        return 1;
    }

    time_t departure_time = mktime(&departure);
    time_t arrival_time = mktime(&destination);

    if (departure_time == -1 || arrival_time == -1) {
        printf("Invalid time\n");
        return 1;
    }

    if (arrival_time < departure_time) {
        printf("Cannot travel back in time\n");
        return 1;
    }

    double time_diff = difftime(arrival_time, departure_time);
    int days_diff = (int)(time_diff / (60 * 60 * 24));

    printf("Traveling from %s to %s (%d days)\n", ctime(&departure_time), ctime(&arrival_time), days_diff);

    return 0;
}