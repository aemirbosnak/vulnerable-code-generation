//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    // Get current time
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);

    // Set initial date to current date
    int current_year = local_time->tm_year + 1900;
    int current_month = local_time->tm_mon + 1;
    int current_day = local_time->tm_mday;

    printf("Welcome to Time Travel Simulator!\n");
    printf("Enter the date you'd like to travel to (YYYY/MM/DD):\n");

    // Get user input
    int target_year, target_month, target_day;
    scanf("%d/%d/%d", &target_year, &target_month, &target_day);

    // Handle errors
    if (target_year < 0 || target_year > current_year) {
        printf("Invalid year.\n");
        return 1;
    }
    if (target_year == current_year && target_month < current_month) {
        printf("Invalid month.\n");
        return 1;
    }
    if (target_year == current_year && target_month == current_month && target_day < current_day) {
        printf("Invalid day.\n");
        return 1;
    }

    // Travel to target date
    while (current_year < target_year || (current_year == target_year && current_month < target_month) || (current_year == target_year && current_month == target_month && current_day < target_day)) {
        printf("Travelling to %04d/%02d/%02d...\n", current_year, current_month, current_day);
        current_day++;

        // Handle end of month
        if ((current_month == 4 || current_month == 6 || current_month == 9 || current_month == 11) && current_day == 31) {
            current_month++;
            current_day = 1;
        } else if (current_month == 2 && ((current_year % 4 == 0 && current_year % 100 != 0) || current_year % 400 == 0) && current_day == 30) {
            current_month++;
            current_day = 1;
        } else if (current_month == 2 && current_day == 29) {
            current_month++;
            current_day = 1;
        } else if (current_month == 12 && current_day == 32) {
            current_year++;
            current_month = 1;
            current_day = 1;
        } else if (current_day == 32) {
            current_month++;
            current_day = 1;
        }
    }

    // Print final date
    printf("You have arrived at %04d/%02d/%02d!\n", current_year, current_month, current_day);

    return 0;
}