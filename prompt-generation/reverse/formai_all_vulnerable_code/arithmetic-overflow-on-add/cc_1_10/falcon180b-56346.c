//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int year, month, day;
    struct tm time_travel;
    time_t now;

    // Setting current time
    time(&now);
    localtime_r(&now, &time_travel);

    // Display current time
    printf("Current time: %d-%d-%d %d:%d:%d\n", time_travel.tm_year + 1900, time_travel.tm_mon + 1, time_travel.tm_mday, time_travel.tm_hour, time_travel.tm_min, time_travel.tm_sec);

    do {
        printf("\nEnter your choice:\n");
        printf("1. Time travel to the past\n2. Time travel to the future\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the year you want to travel to: ");
                scanf("%d", &year);
                printf("Enter the month (1-12): ");
                scanf("%d", &month);
                printf("Enter the day: ");
                scanf("%d", &day);

                // Setting time travel date
                time_travel.tm_year = year - 1900;
                time_travel.tm_mon = month - 1;
                time_travel.tm_mday = day;

                // Displaying time travel date
                printf("\nYou are traveling to %d-%d-%d\n", time_travel.tm_year + 1900, time_travel.tm_mon + 1, time_travel.tm_mday);
                break;

            case 2:
                printf("\nEnter the year you want to travel to: ");
                scanf("%d", &year);
                printf("Enter the month (1-12): ");
                scanf("%d", &month);
                printf("Enter the day: ");
                scanf("%d", &day);

                // Setting time travel date
                time_travel.tm_year = year - 1900;
                time_travel.tm_mon = month - 1;
                time_travel.tm_mday = day;

                // Displaying time travel date
                printf("\nYou are traveling to %d-%d-%d\n", time_travel.tm_year + 1900, time_travel.tm_mon + 1, time_travel.tm_mday);
                break;

            case 3:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice!= 3);

    return 0;
}