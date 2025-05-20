//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void time_travel(int year);

int main() {
    int choice;
    do {
        printf("Welcome to the Time Travel Simulator!\n");
        printf("Please choose an option:\n");
        printf("1. Enter a year to travel to\n");
        printf("2. Exit program\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int year;
                printf("Enter the year you want to travel to: ");
                scanf("%d", &year);
                time_travel(year);
                break;
            }
            case 2: {
                exit(0);
            }
            default: {
                printf("Invalid option. Please try again.\n");
            }
        }
    } while(1);
    return 0;
}

// This function simulates time travel by changing the system time
void time_travel(int year) {
    struct tm time = {0};
    time.tm_year = year - 1900; // Adjust for Unix epoch
    time.tm_mon = 0; // January
    time.tm_mday = 1; // 1st of the month
    time.tm_hour = 0;
    time.tm_min = 0;
    time.tm_sec = 0;
    time_t now = mktime(&time); // Convert to Unix timestamp
    time_t target = now + 60*60*24*365*(year-2022); // Add number of seconds in a year
    settimeofday(&target, NULL); // Change system time
    printf("You have successfully traveled to the year %d!\n", year);
    system("pause"); // Pause program to view time change
    settimeofday(&now, NULL); // Reset system time
}