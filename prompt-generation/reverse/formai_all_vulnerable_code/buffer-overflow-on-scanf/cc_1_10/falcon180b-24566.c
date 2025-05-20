//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_YEARS 9999
#define MAX_MONTHS 12
#define MAX_DAYS 31

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

void print_time(Time time) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", time.year, time.month, time.day, time.hour, time.minute, time.second);
}

int main() {
    Time current_time, destination_time;
    int choice;
    char input[100];

    srand(time(NULL));
    current_time.year = rand() % MAX_YEARS + 1;
    current_time.month = rand() % MAX_MONTHS + 1;
    current_time.day = rand() % MAX_DAYS + 1;
    current_time.hour = rand() % 24;
    current_time.minute = rand() % 60;
    current_time.second = rand() % 60;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Current time: ");
    print_time(current_time);

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Travel forward in time\n");
        printf("2. Travel backward in time\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the number of years to travel forward: ");
            scanf("%s", input);
            current_time.year += atoi(input);
            if (current_time.year > MAX_YEARS) {
                printf("Error: cannot travel forward past the year %d.\n", MAX_YEARS);
                continue;
            }
            current_time.month = rand() % MAX_MONTHS + 1;
            current_time.day = rand() % MAX_DAYS + 1;
            current_time.hour = rand() % 24;
            current_time.minute = rand() % 60;
            current_time.second = rand() % 60;
            printf("You have traveled forward in time to the year %d.\n", current_time.year);
            break;

        case 2:
            printf("Enter the number of years to travel backward: ");
            scanf("%s", input);
            current_time.year -= atoi(input);
            if (current_time.year < 1) {
                printf("Error: cannot travel backward before the year 1.\n");
                continue;
            }
            current_time.month = rand() % MAX_MONTHS + 1;
            current_time.day = rand() % MAX_DAYS + 1;
            current_time.hour = rand() % 24;
            current_time.minute = rand() % 60;
            current_time.second = rand() % 60;
            printf("You have traveled backward in time to the year %d.\n", current_time.year);
            break;

        case 3:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}