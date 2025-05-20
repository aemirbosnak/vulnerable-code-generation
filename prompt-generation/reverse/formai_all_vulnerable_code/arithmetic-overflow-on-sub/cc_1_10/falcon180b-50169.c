//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int year, month, day;
    int hour, minute, second;
    time_t current_time;
    struct tm *local_time;

    // Get the current time
    time(&current_time);
    local_time = localtime(&current_time);

    // Display the current time and date
    printf("The current time and date is: %s", asctime(local_time));

    // Ask the user if they want to travel through time
    printf("\nDo you want to travel through time? (y/n): ");
    scanf("%c", &choice);

    // If the user chooses to travel through time, ask for the destination time and date
    if (choice == 'y' || choice == 'Y') {
        printf("\nEnter the destination year (between 1900 and 2099): ");
        scanf("%d", &year);

        printf("\nEnter the destination month (between 1 and 12): ");
        scanf("%d", &month);

        printf("\nEnter the destination day (between 1 and 31): ");
        scanf("%d", &day);

        printf("\nEnter the destination hour (between 0 and 23): ");
        scanf("%d", &hour);

        printf("\nEnter the destination minute (between 0 and 59): ");
        scanf("%d", &minute);

        printf("\nEnter the destination second (between 0 and 59): ");
        scanf("%d", &second);

        // Set the destination time and date
        local_time->tm_year = year - 1900;
        local_time->tm_mon = month - 1;
        local_time->tm_mday = day;
        local_time->tm_hour = hour;
        local_time->tm_min = minute;
        local_time->tm_sec = second;

        // Display the destination time and date
        printf("\nThe destination time and date is: %s", asctime(local_time));
    }

    return 0;
}