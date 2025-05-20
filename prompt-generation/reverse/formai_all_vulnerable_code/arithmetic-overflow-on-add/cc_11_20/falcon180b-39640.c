//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVELS 100

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

    print_time(current_time);

    int num_time_travels;
    scanf("%d", &num_time_travels);

    if (num_time_travels > MAX_TIME_TRAVELS) {
        printf("Error: Maximum number of time travels exceeded.\n");
        return 1;
    }

    for (int i = 0; i < num_time_travels; i++) {
        Time destination_time;
        char input[100];

        printf("Enter destination time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", input);

        sscanf(input, "%04d-%02d-%02d %02d:%02d:%02d", &destination_time.year, &destination_time.month, &destination_time.day, &destination_time.hour, &destination_time.minute, &destination_time.second);

        if (destination_time.year < 1900 || destination_time.year > 9999 || destination_time.month < 1 || destination_time.month > 12 || destination_time.day < 1 || destination_time.day > 31 || destination_time.hour < 0 || destination_time.hour > 23 || destination_time.minute < 0 || destination_time.minute > 59 || destination_time.second < 0 || destination_time.second > 59) {
            printf("Error: Invalid destination time.\n");
            return 1;
        }

        if (destination_time.year < current_time.year || (destination_time.year == current_time.year && destination_time.month < current_time.month) || (destination_time.year == current_time.year && destination_time.month == current_time.month && destination_time.day < current_time.day)) {
            printf("Error: Cannot travel to the past.\n");
            return 1;
        }

        printf("Traveling to %04d-%02d-%02d %02d:%02d:%02d...\n", destination_time.year, destination_time.month, destination_time.day, destination_time.hour, destination_time.minute, destination_time.second);
        sleep(1);
    }

    return 0;
}