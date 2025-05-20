//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TIME_MAX 10000
#define TIME_MIN -10000
#define TIME_STEP 1

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
    int choice;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter your current time:\n");
    printf("Year: ");
    scanf("%d", &current_time.year);
    printf("Month: ");
    scanf("%d", &current_time.month);
    printf("Day: ");
    scanf("%d", &current_time.day);
    printf("Hour: ");
    scanf("%d", &current_time.hour);
    printf("Minute: ");
    scanf("%d", &current_time.minute);
    printf("Second: ");
    scanf("%d", &current_time.second);

    printf("Where would you like to travel to?\n");
    printf("1. Back in time\n");
    printf("2. Forward in time\n");
    scanf("%d", &choice);

    if (choice == 1) {
        int time_diff;
        printf("How many years back would you like to travel? ");
        scanf("%d", &time_diff);
        current_time.year -= time_diff;
        while (current_time.year < TIME_MIN) {
            current_time.year += 100;
        }
        current_time.month = 1;
        current_time.day = 1;
        current_time.hour = 0;
        current_time.minute = 0;
        current_time.second = 0;
    } else if (choice == 2) {
        int time_diff;
        printf("How many years forward would you like to travel? ");
        scanf("%d", &time_diff);
        current_time.year += time_diff;
        while (current_time.year > TIME_MAX) {
            current_time.year -= 100;
        }
        current_time.month = 1;
        current_time.day = 1;
        current_time.hour = 0;
        current_time.minute = 0;
        current_time.second = 0;
    }

    printf("You have traveled to ");
    print_time(current_time);

    return 0;
}