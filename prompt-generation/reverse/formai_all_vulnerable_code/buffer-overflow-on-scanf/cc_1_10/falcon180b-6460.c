//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 100

struct TimeTravel {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

void print_time(struct TimeTravel time) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", time.year, time.month, time.day, time.hour, time.minute, time.second);
}

int main() {
    int num_time_travels;
    struct TimeTravel time_travels[MAX_TIME_TRAVEL];
    int i;

    printf("Enter the number of time travels: ");
    scanf("%d", &num_time_travels);

    for (i = 0; i < num_time_travels; i++) {
        printf("Enter the details of time travel %d:\n", i+1);
        printf("Year: ");
        scanf("%d", &time_travels[i].year);
        printf("Month: ");
        scanf("%d", &time_travels[i].month);
        printf("Day: ");
        scanf("%d", &time_travels[i].day);
        printf("Hour: ");
        scanf("%d", &time_travels[i].hour);
        printf("Minute: ");
        scanf("%d", &time_travels[i].minute);
        printf("Second: ");
        scanf("%d", &time_travels[i].second);
    }

    printf("Time Travels:\n");
    for (i = 0; i < num_time_travels; i++) {
        print_time(time_travels[i]);
    }

    return 0;
}