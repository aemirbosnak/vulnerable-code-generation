//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1000

struct TimeMachine {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

int main() {
    struct TimeMachine time_machine;
    int choice;
    int year, month, day, hour, minute, second;

    srand(time(NULL));
    year = rand() % (MAX_YEAR - MIN_YEAR + 1) + MIN_YEAR;
    month = rand() % 12;
    day = rand() % 28 + 1;
    hour = rand() % 24;
    minute = rand() % 60;
    second = rand() % 60;

    time_machine.year = year;
    time_machine.month = month;
    time_machine.day = day;
    time_machine.hour = hour;
    time_machine.minute = minute;
    time_machine.second = second;

    printf("\nWelcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d.\n", time_machine.year);

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. View current date and time\n");
        printf("2. Travel to a random time period\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nCurrent date and time: %d-%02d-%02d %02d:%02d:%02d\n",
                    time_machine.year, time_machine.month, time_machine.day,
                    time_machine.hour, time_machine.minute, time_machine.second);
            break;

        case 2:
            time_machine.year = rand() % (MAX_YEAR - MIN_YEAR + 1) + MIN_YEAR;
            time_machine.month = rand() % 12;
            time_machine.day = rand() % 28 + 1;
            time_machine.hour = rand() % 24;
            time_machine.minute = rand() % 60;
            time_machine.second = rand() % 60;

            printf("\nYou have successfully traveled through time!\n");
            printf("You are now in the year %d.\n", time_machine.year);
            break;

        case 3:
            printf("\nExiting the Time Travel Simulator...\n");
            exit(0);

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}