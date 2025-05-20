//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    time_t current_time;
    struct tm *local_time;
    int year, month, day, hour, minute, second, choice, travel_year, travel_month, travel_day, travel_hour, travel_minute, travel_second;
    double time_difference;
    time(&current_time);
    local_time = localtime(&current_time);

    printf("WELCOME TO THE TIME TRAVEL SIMULATOR\n");
    printf("Your current time is %s\n", asctime(local_time));
    printf("Press 1 to travel to a specific date and time.\n");
    printf("Press 2 to travel a certain number of years into the future.\n");
    printf("Press 3 to travel a certain number of years into the past.\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the year (yyyy): ");
            scanf("%d", &travel_year);
            printf("Enter the month (mm): ");
            scanf("%d", &travel_month);
            printf("Enter the day (dd): ");
            scanf("%d", &travel_day);
            printf("Enter the hour (24-hour format): ");
            scanf("%d", &travel_hour);
            printf("Enter the minute: ");
            scanf("%d", &travel_minute);
            printf("Enter the second: ");
            scanf("%d", &travel_second);

            struct tm travel_time = { 0 };
            travel_time.tm_year = travel_year - 1900;
            travel_time.tm_mon = travel_month - 1;
            travel_time.tm_mday = travel_day;
            travel_time.tm_hour = travel_hour;
            travel_time.tm_min = travel_minute;
            travel_time.tm_sec = travel_second;
            time_t travel_seconds = mktime(&travel_time);

            time_difference = difftime(travel_seconds, current_time);

            if (time_difference >= 0) {
                printf("Traveling to %s", asctime(&travel_time));
                printf("...\n");
                sleep(2);
                printf("You have arrived at %s", asctime(&travel_time));
            } else {
                printf("You cannot travel back in time. Please try again.\n");
            }

            break;

        case 2:
            printf("Enter the number of years to travel into the future: ");
            scanf("%d", &year);
            time_difference = year * 31536000; // 1 year = 31536000 seconds
            current_time += (time_t)time_difference;
            localtime_r(&current_time, local_time);
            printf("Traveling %d years into the future...\n", year);
            sleep(2);
            printf("You have arrived at %s", asctime(local_time));

            break;

        case 3:
            printf("Enter the number of years to travel into the past: ");
            scanf("%d", &year);
            time_difference = year * 31536000; // 1 year = 31536000 seconds
            current_time -= (time_t)time_difference;
            localtime_r(&current_time, local_time);
            printf("Traveling %d years into the past...\n", year);
            sleep(2);
            printf("You have arrived at %s", asctime(local_time));

            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}