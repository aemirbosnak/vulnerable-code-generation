//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_YEAR 3000
#define MIN_YEAR 1000

void displayOptions() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose a time travel destination:\n");
    printf("1. Travel to a specific year\n");
    printf("2. Travel to the present year\n");
    printf("3. Quit\n");
}

void travelToYear(int year) {
    // Simulating simple facts about the chosen year
    printf("You've traveled to the year %d!\n", year);
    
    // Simple history facts
    if (year == 1776) {
        printf("American Declaration of Independence signed!\n");
    } else if (year == 1865) {
        printf("The Civil War ends in the USA!\n");
    } else if (year == 1969) {
        printf("Apollo 11 lands on the Moon!\n");
    } else if (year == 1989) {
        printf("The Berlin Wall falls!\n");
    } else {
        printf("Who knows what awaits you in %d?\n", year);
    }
    
    printf("Type 'back' to return to the present.\n");
    char command[10];
    scanf("%s", command);
    if (strcmp(command, "back") == 0) {
        printf("Returning to the present...\n");
    } else {
        printf("Unrecognized command! You may be stuck in time...\n");
    }
}

int main() {
    int choice, year;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Current Year: %d\n", tm.tm_year + 1900);

    while (1) {
        displayOptions();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the year you want to travel to (%d - %d): ", MIN_YEAR, MAX_YEAR);
                scanf("%d", &year);
                if (year >= MIN_YEAR && year <= MAX_YEAR) {
                    travelToYear(year);
                } else {
                    printf("Invalid year! Please choose a year between %d and %d.\n", MIN_YEAR, MAX_YEAR);
                }
                break;
            case 2:
                printf("You have returned to the present year: %d.\n", tm.tm_year + 1900);
                break;
            case 3:
                printf("Thank you for using the Time Travel Simulator! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select an option between 1 and 3.\n");
        }
        printf("\n");
    }

    return 0;
}