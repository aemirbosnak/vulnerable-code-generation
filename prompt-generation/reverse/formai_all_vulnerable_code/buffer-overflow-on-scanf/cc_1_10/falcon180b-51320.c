//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TIME_TRAVELS 100
#define TIME_TRAVEL_SUCCESS 0
#define TIME_TRAVEL_FAILURE 1

struct time_travel {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status; // 0 for success, 1 for failure
};

void print_time(struct time_travel time) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", time.year, time.month, time.day, time.hour, time.minute, time.second);
}

int main() {
    srand(time(NULL));

    int num_time_travels;
    printf("Enter the number of time travels (1 to %d): ", MAX_TIME_TRAVELS);
    scanf("%d", &num_time_travels);

    struct time_travel time_travels[num_time_travels];

    for (int i = 0; i < num_time_travels; i++) {
        time_travels[i].year = rand() % 1000 + 1;
        time_travels[i].month = rand() % 12 + 1;
        time_travels[i].day = rand() % 28 + 1;
        time_travels[i].hour = rand() % 24;
        time_travels[i].minute = rand() % 60;
        time_travels[i].second = rand() % 60;
        time_travels[i].status = TIME_TRAVEL_FAILURE;
    }

    printf("Time Travel Log:\n");
    for (int i = 0; i < num_time_travels; i++) {
        printf("Attempt #%d: ", i + 1);
        print_time(time_travels[i]);
        if (time_travels[i].status == TIME_TRAVEL_FAILURE) {
            printf("Failed.\n");
        }
    }

    return 0;
}