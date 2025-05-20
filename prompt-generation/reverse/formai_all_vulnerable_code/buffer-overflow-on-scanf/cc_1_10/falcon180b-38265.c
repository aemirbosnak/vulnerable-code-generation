//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_TIME_TRAVELS 10
#define MAX_TIME_TRAVEL_LENGTH 100

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

void print_time(Time time) {
    printf("%d-%02d-%02d %02d:%02d:%02d\n", time.year, time.month, time.day, time.hour, time.minute, time.second);
}

int compare_times(Time a, Time b) {
    if (a.year > b.year) {
        return 1;
    } else if (a.year < b.year) {
        return -1;
    } else if (a.month > b.month) {
        return 1;
    } else if (a.month < b.month) {
        return -1;
    } else if (a.day > b.day) {
        return 1;
    } else if (a.day < b.day) {
        return -1;
    } else if (a.hour > b.hour) {
        return 1;
    } else if (a.hour < b.hour) {
        return -1;
    } else if (a.minute > b.minute) {
        return 1;
    } else if (a.minute < b.minute) {
        return -1;
    } else if (a.second > b.second) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_time_travels;
    Time time_travels[MAX_TIME_TRAVELS];
    char input[MAX_TIME_TRAVEL_LENGTH];

    printf("Enter the number of time travels (1-%d): ", MAX_TIME_TRAVELS);
    scanf("%d", &num_time_travels);

    for (int i = 0; i < num_time_travels; i++) {
        printf("Enter the destination time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);
        strptime(input, "%Y-%m-%d %H:%M:%S", &time_travels[i]);
    }

    qsort(time_travels, num_time_travels, sizeof(Time), compare_times);

    for (int i = 0; i < num_time_travels; i++) {
        print_time(time_travels[i]);
    }

    return 0;
}