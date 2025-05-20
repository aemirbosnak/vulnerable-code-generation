//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int year, month, day, hour, minute, second;
    struct tm time_struct;
    time_t current_time;
    char input[100];

    printf("Welcome to the Time Travel Simulator!\n\n");

    time(&current_time);
    localtime_r(&current_time, &time_struct);

    printf("Current date and time: %s", asctime(&time_struct));

    while(1) {
        printf("\nEnter the year you want to travel to (YYYY): ");
        scanf("%d", &year);
        printf("Enter the month you want to travel to (MM): ");
        scanf("%d", &month);
        printf("Enter the day you want to travel to (DD): ");
        scanf("%d", &day);
        printf("Enter the hour you want to travel to (HH): ");
        scanf("%d", &hour);
        printf("Enter the minute you want to travel to (MM): ");
        scanf("%d", &minute);
        printf("Enter the second you want to travel to (SS): ");
        scanf("%d", &second);

        time_struct.tm_year = year - 1900;
        time_struct.tm_mon = month - 1;
        time_struct.tm_mday = day;
        time_struct.tm_hour = hour;
        time_struct.tm_min = minute;
        time_struct.tm_sec = second;

        current_time = mktime(&time_struct);
        time_struct = *localtime(&current_time);

        printf("\nYou have successfully traveled to %s", asctime(&time_struct));

        printf("\nDo you want to travel again? (y/n): ");
        scanf(" %c", &input[0]);
        if(input[0] == 'n' || input[0] == 'N') {
            break;
        }
    }

    return 0;
}