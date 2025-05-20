//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    int year = t->tm_year + 1900;
    int month = t->tm_mon + 1;
    int day = t->tm_mday;
    int hour = t->tm_hour;
    int minute = t->tm_min;
    int second = t->tm_sec;

    printf("Welcome to the Time Travel Simulator\n\n");
    printf("Today's date is %d/%d/%d\n", day, month, year);
    printf("The time is %02d:%02d:%02d\n\n", hour, minute, second);

    printf("Enter the year you'd like to travel to (yyyy): ");
    int travel_year;
    scanf("%d", &travel_year);
    getchar();

    if (travel_year < year) {
        printf("\nSorry, time travel to the past is not yet possible.\n");
        printf("Please enter a future year.\n");
        return 1;
    }

    printf("\nTravel date set to %d/%d/%d\n", day, month, travel_year);

    printf("Enter the month you'd like to travel to (mm): ");
    int travel_month;
    scanf("%d", &travel_month);
    getchar();

    if (travel_year == year && travel_month < month) {
        printf("\nSorry, time travel to the past is not yet possible.\n");
        printf("Please enter a future month.\n");
        return 1;
    }

    printf("\nTravel date set to %d/%02d/%d\n", day, travel_month, travel_year);

    printf("Enter the day you'd like to travel to (dd): ");
    int travel_day;
    scanf("%d", &travel_day);
    getchar();

    if (travel_year == year && travel_month == month && travel_day < day) {
        printf("\nSorry, time travel to the past is not yet possible.\n");
        printf("Please enter a future day.\n");
        return 1;
    }

    printf("\nTravel date set to %02d/%02d/%d\n", travel_day, travel_month, travel_year);

    printf("Enter the hour you'd like to travel to (24-hour format): ");
    int travel_hour;
    scanf("%d", &travel_hour);
    getchar();

    if (travel_year == year && travel_month == month && travel_day == day && travel_hour < hour) {
        printf("\nSorry, time travel to the past is not yet possible.\n");
        printf("Please enter a future hour.\n");
        return 1;
    }

    printf("\nTravel time set to %02d:%02d:%02d on %02d/%02d/%d\n\n", travel_hour, minute, second, travel_day, travel_month, travel_year);

    printf("You are now traveling through time...\n");
    printf("Please wait...\n");

    for (int i = 0; i < 10; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }

    printf("\n\nYou have arrived at your destination!\n");
    printf("The date is %02d/%02d/%d and the time is %02d:%02d:%02d.\n\n", travel_day, travel_month, travel_year, travel_hour, minute, second);

    return 0;
}