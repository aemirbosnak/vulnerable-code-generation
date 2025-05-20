//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
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

void travel_time(struct TimeMachine *time_machine) {
    printf("Entering the Time Machine...\n");
    printf("Year: %d\n", time_machine->year);
    printf("Month: %d\n", time_machine->month);
    printf("Day: %d\n", time_machine->day);
    printf("Hour: %d\n", time_machine->hour);
    printf("Minute: %d\n", time_machine->minute);
    printf("Second: %d\n", time_machine->second);
}

int main() {
    struct TimeMachine time_machine;
    int choice;

    srand(time(NULL));
    time_machine.year = rand() % (MAX_YEAR - MIN_YEAR + 1) + MIN_YEAR;
    time_machine.month = rand() % 12 + 1;
    time_machine.day = rand() % 28 + 1;
    time_machine.hour = rand() % 24;
    time_machine.minute = rand() % 60;
    time_machine.second = rand() % 60;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d.\n", time_machine.year);

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. View current time\n");
        printf("2. Travel back in time\n");
        printf("3. Travel forward in time\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                travel_time(&time_machine);
                break;
            case 2:
                time_machine.year -= rand() % 10 + 1;
                if (time_machine.year < MIN_YEAR) {
                    time_machine.year = MIN_YEAR;
                }
                printf("You have traveled back in time to the year %d.\n", time_machine.year);
                break;
            case 3:
                time_machine.year += rand() % 10 + 1;
                if (time_machine.year > MAX_YEAR) {
                    time_machine.year = MAX_YEAR;
                }
                printf("You have traveled forward in time to the year %d.\n", time_machine.year);
                break;
            case 4:
                printf("Exiting Time Travel Simulator...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 4);

    return 0;
}