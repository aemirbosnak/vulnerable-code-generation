//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *local_time = localtime(&now);
    int curr_year = local_time->tm_year + 1900;
    int curr_month = local_time->tm_mon + 1;
    int curr_day = local_time->tm_mday;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Today's date is %d-%02d-%02d.\n", curr_year, curr_month, curr_day);
    printf("Enter a year to travel to: ");

    int target_year;
    scanf("%d", &target_year);

    if (target_year < curr_year) {
        printf("Time travel backwards is not yet possible.\n");
        return 0;
    }

    int target_month, target_day;
    printf("Enter a month and day in the format MM-DD: ");
    scanf("%d-%d", &target_month, &target_day);

    if (target_month < 1 || target_month > 12 || target_day < 1 || target_day > 31) {
        printf("Invalid date format.\n");
        return 0;
    }

    int year_diff = target_year - curr_year;
    time_t target_time = now + year_diff * 31536000;
    struct tm *target_local_time = localtime(&target_time);
    target_local_time->tm_mon = target_month - 1;
    target_local_time->tm_mday = target_day;
    target_time = mktime(target_local_time);

    printf("\nYour time travel destination is set for %d-%02d-%02d.\n",
           target_year, target_month, target_day);
    printf("Press ENTER to begin time travel.\n");
    getchar();
    printf("Initializing time travel sequence...\n");
    printf("Please wait...\n");
    printf("Time travel completed successfully!\n");
    printf("\nYou have arrived at %d-%02d-%02d.\n", target_year, target_month, target_day);

    return 0;
}