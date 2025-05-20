//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int year, month, day, hour, minute, second;
    struct tm time_now;
    time_t current_time;
    char past_or_future[2];
    int choice;
    int i;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the current date and time:\n");
    printf("Year: ");
    scanf("%d", &year);
    printf("Month: ");
    scanf("%d", &month);
    printf("Day: ");
    scanf("%d", &day);
    printf("Hour: ");
    scanf("%d", &hour);
    printf("Minute: ");
    scanf("%d", &minute);
    printf("Second: ");
    scanf("%d", &second);

    time_now.tm_year = year - 1900;
    time_now.tm_mon = month - 1;
    time_now.tm_mday = day;
    time_now.tm_hour = hour;
    time_now.tm_min = minute;
    time_now.tm_sec = second;

    current_time = mktime(&time_now);
    printf("Current time: %s", ctime(&current_time));

    do {
        printf("\nDo you want to travel to the past or the future?\n");
        printf("1. Past\n2. Future\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("How many years do you want to travel back in time?\n");
            scanf("%d", &i);
            time_now.tm_year -= i;
            past_or_future[0] = 'P';
        } else if (choice == 2) {
            printf("How many years do you want to travel into the future?\n");
            scanf("%d", &i);
            time_now.tm_year += i;
            past_or_future[0] = 'F';
        }

        current_time = mktime(&time_now);
        printf("\nYou have traveled %d year%c.\n", i, past_or_future[0]);
        printf("Current time: %s", ctime(&current_time));

        printf("\nDo you want to travel again? (Y/N)\n");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return 0;
}