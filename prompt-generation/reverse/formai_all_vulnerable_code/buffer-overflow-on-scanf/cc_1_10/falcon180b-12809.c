//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int year, month, day, hour, minute, second;
    struct tm time;
    char input[100];
    int choice;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the current date and time:\n");
    scanf("%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

    time.tm_year = year - 1900;
    time.tm_mon = month - 1;
    time.tm_mday = day;
    time.tm_hour = hour;
    time.tm_min = minute;
    time.tm_sec = second;

    time_t now = mktime(&time);
    printf("The current time is: %s\n", ctime(&now));

    do {
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Travel to the past\n");
        printf("2. Travel to the future\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n");
            printf("Enter the year you want to travel to:\n");
            scanf("%d", &year);

            time.tm_year = year - 1900;
            time.tm_mon = 0;
            time.tm_mday = 1;
            time.tm_hour = 0;
            time.tm_min = 0;
            time.tm_sec = 0;

            time_t past = mktime(&time);
            printf("You have traveled to the past! The current time is: %s\n", ctime(&past));
            break;

        case 2:
            printf("\n");
            printf("Enter the year you want to travel to:\n");
            scanf("%d", &year);

            time.tm_year = year - 1900;
            time.tm_mon = 0;
            time.tm_mday = 1;
            time.tm_hour = 0;
            time.tm_min = 0;
            time.tm_sec = 0;

            time_t future = mktime(&time);
            printf("You have traveled to the future! The current time is: %s\n", ctime(&future));
            break;

        case 3:
            printf("\n");
            printf("Thank you for using the Time Travel Simulator!\n");
            break;

        default:
            printf("\n");
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);

    return 0;
}