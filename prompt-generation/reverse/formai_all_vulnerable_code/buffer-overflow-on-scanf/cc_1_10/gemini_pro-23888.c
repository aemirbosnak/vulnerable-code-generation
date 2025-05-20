//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Whoa! Get ready for a mind-bending time travel simulator! Buckle up, time travelers!

// Delorean's time machine specifications
#define MAX_TIME_TRAVELS 5
#define MIN_TIME_TRAVEL_YEAR 1900
#define MAX_TIME_TRAVEL_YEAR 2100

// Time zones
#define PST -8
#define MST -7
#define CST -6
#define EST -5

// Time travel adventure begins!
int main() {
    // Set the time machine's initial state
    int currentYear = 2023;
    int currentMonth = 6;
    int currentDay = 15;
    int currentHour = 10;
    int currentMinute = 30;
    int currentSecond = 0;
    int timezone = PST;

    // Initialize the time machine's travel log
    int travelLog[MAX_TIME_TRAVELS][6];  // [year, month, day, hour, minute, second]

    // Start the time travel adventure!
    printf("Welcome to the Time Travel Simulator! Prepare for an extraordinary journey.\n");

    // Get ready for multiple time travels
    for (int i = 0; i < MAX_TIME_TRAVELS; i++) {
        // Set the destination time
        int destinationYear, destinationMonth, destinationDay, destinationHour, destinationMinute, destinationSecond;
        printf("Time traveler, enter your destination year (%d-%d): ", MIN_TIME_TRAVEL_YEAR, MAX_TIME_TRAVEL_YEAR);
        scanf("%d", &destinationYear);
        printf("Enter your destination month (1-12): ");
        scanf("%d", &destinationMonth);
        printf("Enter your destination day (1-%d): ", daysInMonth(destinationMonth, destinationYear));
        scanf("%d", &destinationDay);
        printf("Enter your destination hour (0-23): ");
        scanf("%d", &destinationHour);
        printf("Enter your destination minute (0-59): ");
        scanf("%d", &destinationMinute);
        printf("Enter your destination second (0-59): ");
        scanf("%d", &destinationSecond);

        // Record the time travel in the log
        travelLog[i][0] = destinationYear;
        travelLog[i][1] = destinationMonth;
        travelLog[i][2] = destinationDay;
        travelLog[i][3] = destinationHour;
        travelLog[i][4] = destinationMinute;
        travelLog[i][5] = destinationSecond;

        // Embark on the time travel!
        currentYear = destinationYear;
        currentMonth = destinationMonth;
        currentDay = destinationDay;
        currentHour = destinationHour;
        currentMinute = destinationMinute;
        currentSecond = destinationSecond;

        // Display the time traveler's new location
        printf("Whoosh! You've arrived in %d-%d-%d %d:%d:%d.\n", currentYear, currentMonth, currentDay, currentHour, currentMinute, currentSecond);
    }

    // Display the time travel log
    printf("Review your time-bending adventures:\n");
    for (int i = 0; i < MAX_TIME_TRAVELS; i++) {
        printf("Travel %d: %d-%d-%d %d:%d:%d\n", i + 1, travelLog[i][0], travelLog[i][1], travelLog[i][2], travelLog[i][3], travelLog[i][4], travelLog[i][5]);
    }

    // Bon voyage, time traveler! May your adventures inspire the future.
    printf("Thank you for using the Time Travel Simulator! May your journeys through time be filled with wonder and discovery.\n");

    return 0;
}

// Calculate the number of days in a month
int daysInMonth(int month, int year) {
    switch (month) {
        case 2:
            return 28 + ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}