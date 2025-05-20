//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time, target_time;
    struct tm *current_date, *target_date;
    int current_year, target_year, leap_years = 0;
    char travel_direction, confirm;

    // Get current date and time
    current_time = time(NULL);
    current_date = localtime(&current_time);
    current_year = current_date->tm_year + 1900;

    printf("Welcome to the Time Travel Simulator\n");
    printf("You are currently in the year %d\n\n", current_year);

    // Prompt for travel direction
    do {
        printf("Do you want to travel to the future (F) or the past (P)? ");
        scanf("%c", &travel_direction);
        fflush(stdin);
    } while (travel_direction != 'F' && travel_direction != 'P');

    // Prompt for target year
    printf("\nEnter the year you want to travel to: ");
    scanf("%d", &target_year);
    fflush(stdin);

    // Calculate time difference
    if (travel_direction == 'F') {
        target_date = current_date;
        target_date->tm_year = target_year - 1900;
        target_date->tm_mday = 1;
        target_date->tm_mon = 0;
        target_date->tm_hour = 0;
        target_date->tm_min = 0;
        target_date->tm_sec = 0;
        target_time = mktime(target_date);
    } else {
        target_date = current_date;
        target_date->tm_year = target_year - 1900;
        target_date->tm_mon = 0;
        target_date->tm_mday = 1;
        target_date->tm_hour = 0;
        target_date->tm_min = 0;
        target_date->tm_sec = 0;
        target_time = mktime(target_date);
    }

    if (current_year < target_year) {
        printf("\nTime travel commencing to the year %d... 3... 2... 1...\n\n", target_year);
    } else if (current_year > target_year) {
        printf("\nTime travel commencing to the year %d... 3... 2... 1...\n\n", target_year);
    } else {
        printf("\nYou are already in the year %d! Nothing to do here.\n", target_year);
        return 0;
    }

    // Confirm travel
    printf("Are you sure you want to travel to the year %d (Y/N)? ", target_year);
    scanf("%c", &confirm);
    fflush(stdin);

    if (confirm == 'N' || confirm == 'n') {
        printf("\nTime travel aborted. Returning to present time.\n");
        return 0;
    }

    // Calculate leap years
    for (int year = current_year; year < target_year; year++) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            leap_years++;
        }
    }

    // Travel through time
    if (current_time < target_time) {
        for (time_t t = current_time; t <= target_time; t++) {
            printf("Current year: %d\n", current_year++);
            if (current_year > target_year) {
                break;
            }
            if (current_year % 10 == 0) {
                printf("\nYou have traveled through %d years so far. Keep going?\n", current_year - (target_year-1));
                printf("Press enter to continue...");
                getchar();
            }
        }
    } else {
        for (time_t t = current_time; t >= target_time; t--) {
            printf("Current year: %d\n", current_year--);
            if (current_year < target_year) {
                break;
            }
            if (current_year % 10 == 0) {
                printf("\nYou have traveled through %d years so far. Keep going?\n", (target_year-1) - current_year);
                printf("Press enter to continue...");
                getchar();
            }
        }
    }

    printf("\nCongratulations! You have successfully traveled through time to the year %d.\n", target_year);
    printf("You have traveled through a total of %d years, including %d leap years.\n", abs(current_year - target_year), leap_years);

    return 0;
}