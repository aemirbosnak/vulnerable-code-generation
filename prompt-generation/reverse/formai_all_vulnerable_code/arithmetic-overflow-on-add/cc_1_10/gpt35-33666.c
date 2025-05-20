//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t current_time;
    struct tm * time_info;
    char time_str[100];
    int year, option;

    // Get the current time and format it as a string
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_str, sizeof(time_str), "%Y", time_info);
    year = atoi(time_str);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are now in the year %d.\n", year);
    printf("What would you like to do? Enter the corresponding number:\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    scanf("%d", &option);

    if (option == 1) {
        int past_year;
        printf("Enter the year you would like to travel to (before %d): ", year);
        scanf("%d", &past_year);

        if (past_year >= year) {
            printf("Invalid input. You can't travel to a year equal or after the current year.\n");
            return 1;
        }

        int years_to_travel = year - past_year;
        printf("Travelling %d years into the past...\n", years_to_travel);

        // Update the current time by going back to the past
        time_info->tm_year -= years_to_travel;
        mktime(time_info);
        strftime(time_str, sizeof(time_str), "%Y", time_info);
        year = atoi(time_str);

        printf("You have arrived in the year %d!\n", year);
    } else if (option == 2) {
        int future_years;
        printf("Enter the number of years you would like to travel into the future: ");
        scanf("%d", &future_years);

        if (future_years <= 0) {
            printf("Invalid input. You need to travel at least one year into the future.\n");
            return 1;
        }

        printf("Travelling %d years into the future...\n", future_years);

        // Update the current time by going to the future
        time_info->tm_year += future_years;
        mktime(time_info);
        strftime(time_str, sizeof(time_str), "%Y", time_info);
        year = atoi(time_str);

        printf("You have arrived in the year %d!\n", year);
    } else {
        printf("Invalid input.\n");
        return 1;
    }

    return 0;
}