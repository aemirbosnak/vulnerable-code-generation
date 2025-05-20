//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1900

struct tm current_time;
int destination_year;

void time_travel() {
    printf("Enter the year you want to travel to: ");
    scanf("%d", &destination_year);

    if (destination_year < MIN_YEAR || destination_year > MAX_YEAR) {
        printf("Invalid year. Please enter a year between %d and %d.\n", MIN_YEAR, MAX_YEAR);
        return;
    }

    time_t target_time = mktime(&current_time) + (destination_year - current_time.tm_year) * 365 * 24 * 60 * 60;

    if (target_time < 0) {
        printf("You cannot travel to a time before the present.\n");
        return;
    }

    current_time.tm_year = destination_year;
    current_time.tm_mon = 0;
    current_time.tm_mday = 1;

    time_t travel_time = mktime(&current_time);

    if (travel_time == -1) {
        printf("Invalid date.\n");
        return;
    }

    printf("Traveling to the year %d...\n", destination_year);
    sleep(1);
    printf("Welcome to the year %d!\n", destination_year);
}

int main() {
    time_t now = time(NULL);
    current_time = *localtime(&now);

    while (1) {
        printf("Current year: %d\n", current_time.tm_year + 1900);
        printf("Press 1 to travel in time.\n");
        printf("Press 0 to exit.\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            time_travel();
        } else if (choice == 0) {
            break;
        }
    }

    return 0;
}