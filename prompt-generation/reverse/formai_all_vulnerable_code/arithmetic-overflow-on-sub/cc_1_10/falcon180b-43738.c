//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int year, month, day, hour, minute, second;
    struct tm time;
    char input[80];
    int choice;

    do {
        printf("Enter a date and time in the format yyyy-mm-dd hh:mm:ss\n");
        fgets(input, sizeof(input), stdin);
        strptime(input, "%Y-%m-%d %H:%M:%S", &time);
        year = time.tm_year + 1900;
        month = time.tm_mon + 1;
        day = time.tm_mday;
        hour = time.tm_hour;
        minute = time.tm_min;
        second = time.tm_sec;

        printf("Current date and time: %d-%d-%d %d:%d:%d\n", year, month, day, hour, minute, second);

        printf("What would you like to do?\n");
        printf("1. Travel to the future\n");
        printf("2. Travel to the past\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of seconds to travel into the future:\n");
                scanf("%d", &second);
                time.tm_sec += second;
                break;
            case 2:
                printf("Enter the number of seconds to travel into the past:\n");
                scanf("%d", &second);
                time.tm_sec -= second;
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("New date and time: %d-%d-%d %d:%d:%d\n", year, month, day, hour, minute, second);

    } while (choice!= 3);

    return 0;
}