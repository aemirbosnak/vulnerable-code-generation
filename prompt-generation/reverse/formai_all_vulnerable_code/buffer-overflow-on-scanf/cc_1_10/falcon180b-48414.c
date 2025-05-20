//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100
#define MAX_YEAR 3000

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeTravel;

int main() {
    int num_time_travels;
    int i, j;
    TimeTravel time_travels[MAX_TIME_TRAVELS];

    printf("Enter the number of time travels: ");
    scanf("%d", &num_time_travels);

    for (i = 0; i < num_time_travels; i++) {
        printf("Enter the details for time travel %d:\n", i + 1);
        printf("Enter the departure year (between 1900 and %d): ", MAX_YEAR);
        scanf("%d", &time_travels[i].year);
        printf("Enter the departure month (between 1 and 12): ");
        scanf("%d", &time_travels[i].month);
        printf("Enter the departure day (between 1 and 31): ");
        scanf("%d", &time_travels[i].day);
        printf("Enter the departure hour (between 0 and 23): ");
        scanf("%d", &time_travels[i].hour);
        printf("Enter the departure minute (between 0 and 59): ");
        scanf("%d", &time_travels[i].minute);
        printf("Enter the departure second (between 0 and 59): ");
        scanf("%d", &time_travels[i].second);
    }

    for (i = 0; i < num_time_travels; i++) {
        for (j = i + 1; j < num_time_travels; j++) {
            if (time_travels[i].year == time_travels[j].year &&
                time_travels[i].month == time_travels[j].month &&
                time_travels[i].day == time_travels[j].day &&
                time_travels[i].hour == time_travels[j].hour &&
                time_travels[i].minute == time_travels[j].minute &&
                time_travels[i].second == time_travels[j].second) {
                printf("Time travel %d and %d are the same!\n", i + 1, j + 1);
            }
        }
    }

    return 0;
}