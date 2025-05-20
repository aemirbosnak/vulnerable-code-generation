//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm * time_info;
    char time_str[50];
    int years_diff, months_diff, days_diff, hours_diff, 
        minutes_diff, seconds_diff, years_travel, months_travel, 
        days_travel, hours_travel, minutes_travel, seconds_travel;
    char travel_dir;

    //get the current time
    time(&current_time);
    time_info = localtime(&current_time);

    //get user input for travel direction and amount
    printf("Welcome to the Time Travel Simulator\n");
    printf("Enter the direction to travel (P for past, F for future): ");
    scanf(" %c", &travel_dir);
    printf("Enter the years to travel: ");
    scanf("%d", &years_travel);
    printf("Enter the months to travel: ");
    scanf("%d", &months_travel);
    printf("Enter the days to travel: ");
    scanf("%d", &days_travel);
    printf("Enter the hours to travel: ");
    scanf("%d", &hours_travel);
    printf("Enter the minutes to travel: ");
    scanf("%d", &minutes_travel);
    printf("Enter the seconds to travel: ");
    scanf("%d", &seconds_travel);

    //check if user input for travel direction is valid
    if (travel_dir != 'P' && travel_dir != 'F') {
        printf("Invalid travel direction. Program will exit.\n");
        exit(0);
    }

    //calculate difference in time based on travel direction
    if (travel_dir == 'P') {
        years_diff = -years_travel;
        months_diff = -months_travel;
        days_diff = -days_travel;
        hours_diff = -hours_travel;
        minutes_diff = -minutes_travel;
        seconds_diff = -seconds_travel;
    } else if (travel_dir == 'F') {
        years_diff = years_travel;
        months_diff = months_travel;
        days_diff = days_travel;
        hours_diff = hours_travel;
        minutes_diff = minutes_travel;
        seconds_diff = seconds_travel;
    }

    //convert current time to string
    strftime(time_str, sizeof(time_str), "%c", time_info);

    //display current time and travel direction
    printf("Current time: %s\n", time_str);
    if (travel_dir == 'P') {
        printf("Travelling %d years, %d months, %d days, %d hours, %d minutes, %d seconds into the past...\n", years_travel, months_travel, days_travel, hours_travel, minutes_travel, seconds_travel);
    } else if (travel_dir == 'F') {
        printf("Travelling %d years, %d months, %d days, %d hours, %d minutes, %d seconds into the future...\n", years_travel, months_travel, days_travel, hours_travel, minutes_travel, seconds_travel);
    }

    //calculate future/past time
    time_info->tm_year += years_diff;
    time_info->tm_mon += months_diff;
    time_info->tm_mday += days_diff;
    time_info->tm_hour += hours_diff;
    time_info->tm_min += minutes_diff;
    time_info->tm_sec += seconds_diff;

    //convert future/past time to string
    mktime(time_info);
    strftime(time_str, sizeof(time_str), "%c", time_info);

    //display future/past time
    if (travel_dir == 'P') {
        printf("Time travel complete. You are now in the past! The date and time is: %s\n", time_str);
    } else if (travel_dir == 'F') {
        printf("Time travel complete. You are now in the future! The date and time is: %s\n", time_str);
    }

    return 0;
}