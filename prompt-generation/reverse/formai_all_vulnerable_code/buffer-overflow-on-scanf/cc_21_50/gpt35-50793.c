//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize variables for the time machine
    int year = 2021;
    int day = 1;
    int month = 1;
    int hour = 0;
    int minute = 0;

    // Ask user for input
    printf("Welcome to the Time Travel Simulator! What year would you like to travel to? ");
    scanf("%d", &year);
    printf("What month? ");
    scanf("%d", &month);
    printf("What day? ");
    scanf("%d", &day);
    printf("What hour? ");
    scanf("%d", &hour);
    printf("What minute? ");
    scanf("%d", &minute);

    // Calculate the years, months, days, hours, and minutes to travel
    int years_to_travel = year - 2021;
    int months_to_travel = month - 1;
    int days_to_travel = day - 1;
    int hours_to_travel = hour - 0;
    int minutes_to_travel = minute - 0;

    // Calculate the total seconds to travel
    int seconds_to_travel = years_to_travel * 31536000 + months_to_travel * 2592000 + days_to_travel * 86400 + hours_to_travel * 3600 + minutes_to_travel * 60;

    // Ask user to confirm travel
    printf("Are you sure you want to travel to %d/%d/%d %d:%d? (Y/N) ", month, day, year, hour, minute);
    char confirmation = getchar();
    confirmation = getchar();

    if (confirmation == 'Y' || confirmation == 'y') {
        // Start the time travel
        printf("Initiating time travel...\n");

        for (int i = 1; i <= seconds_to_travel; i++) {
            // Travel one second at a time
            
            // Simulate some turbulence during the time travel
            int turbulence = rand() % 10;
            if (turbulence == 0) {
                printf("WARNING: Turbulence detected! Hold on tight!\n");
            }

            // Update the time machine's clock
            minute++;
            if (minute == 60) {
                minute = 0;
                hour++;
            }
            if (hour == 24) {
                hour = 0;
                day++;
            }
            if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
                day = 1;
                month++;
            }
            if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
                day = 1;
                month++;
            }
            if (day > 28 && month == 2 && year % 4 != 0) {
                day = 1;
                month++;
            }
            if (day > 29 && month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                day = 1;
                month++;
            }
            if (month == 13) {
                month = 1;
                year++;
            }
        }

        // Time travel complete
        printf("Time travel complete! You have arrived at %d/%d/%d %d:%d.\n", month, day, year, hour, minute);
    } else {
        // Time travel canceled
        printf("Time travel canceled. You will remain in %d/%d/%d %d:%d.\n", month, day, year, hour, minute);
    }

    return 0;
}