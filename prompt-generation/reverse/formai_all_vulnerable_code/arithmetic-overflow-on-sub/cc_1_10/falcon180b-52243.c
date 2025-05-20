//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int year, month, day, hour, minute, second;
    struct tm time_travel_date;
    time_t now;
    char input[100];

    // Set current date and time
    time(&now);
    localtime_r(&now, &time_travel_date);

    while(1) {
        printf("Enter your choice:\n");
        printf("1. Time Travel\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter the year (YYYY): ");
            scanf("%d", &year);

            printf("Enter the month (1-12): ");
            scanf("%d", &month);

            printf("Enter the day (1-31): ");
            scanf("%d", &day);

            printf("Enter the hour (0-23): ");
            scanf("%d", &hour);

            printf("Enter the minute (0-59): ");
            scanf("%d", &minute);

            printf("Enter the second (0-59): ");
            scanf("%d", &second);

            time_travel_date.tm_year = year - 1900;
            time_travel_date.tm_mon = month - 1;
            time_travel_date.tm_mday = day;
            time_travel_date.tm_hour = hour;
            time_travel_date.tm_min = minute;
            time_travel_date.tm_sec = second;

            mktime(&time_travel_date);

            printf("You have successfully traveled to %s", ctime(&now));
        } else if(choice == 2) {
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}