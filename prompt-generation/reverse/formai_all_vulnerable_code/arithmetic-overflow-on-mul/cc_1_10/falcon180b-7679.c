//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEARS_BACK 100
#define MAX_YEARS_FORWARD 100

int main() {
    int year, month, day;
    time_t current_time;
    struct tm *local_time;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the current date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &year, &month, &day);

    time(&current_time);
    local_time = localtime(&current_time);

    if (year < 1000 || year > 9999) {
        printf("Invalid year entered.\n");
        return 1;
    }

    if (month < 1 || month > 12) {
        printf("Invalid month entered.\n");
        return 1;
    }

    if (day < 1 || day > 31) {
        printf("Invalid day entered.\n");
        return 1;
    }

    printf("You are currently in the year %d.\n", year);

    printf("Where would you like to travel to?\n");
    printf("1. Back in time\n");
    printf("2. Forward in time\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        int years_back;
        printf("How many years back would you like to travel? (Max %d)\n", MAX_YEARS_BACK);
        scanf("%d", &years_back);

        time_t new_time;
        struct tm *new_local_time;

        new_time = mktime(local_time) - (years_back * 365 * 24 * 60 * 60);
        new_local_time = localtime(&new_time);

        printf("You have traveled back in time to the year %d.\n", new_local_time->tm_year + 1900);
    } else if (choice == 2) {
        int years_forward;
        printf("How many years forward would you like to travel? (Max %d)\n", MAX_YEARS_FORWARD);
        scanf("%d", &years_forward);

        time_t new_time;
        struct tm *new_local_time;

        new_time = mktime(local_time) + (years_forward * 365 * 24 * 60 * 60);
        new_local_time = localtime(&new_time);

        printf("You have traveled forward in time to the year %d.\n", new_local_time->tm_year + 1900);
    } else {
        printf("Invalid choice entered.\n");
    }

    return 0;
}