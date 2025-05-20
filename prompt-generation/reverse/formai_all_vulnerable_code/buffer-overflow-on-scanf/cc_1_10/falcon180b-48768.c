//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_YEAR 9999
#define MIN_YEAR 1000
#define INVALID_YEAR -1

int main() {
    int year;
    struct tm time_struct;
    time_t current_time;

    // Get the current time
    time(&current_time);

    // Convert the current time to a struct tm
    localtime_r(&current_time, &time_struct);

    // Ask the user for the year they want to travel to
    printf("Enter the year you want to travel to (between %d and %d): ", MIN_YEAR, MAX_YEAR);
    scanf("%d", &year);

    // Validate the user input
    if (year < MIN_YEAR || year > MAX_YEAR) {
        printf("Invalid year. Please enter a year between %d and %d.\n", MIN_YEAR, MAX_YEAR);
        return 1;
    }

    // Time travel simulation
    printf("Time travel simulation initiated...\n");
    printf("Current year: %d\n", time_struct.tm_year + 1900);
    printf("Year %d selected for time travel.\n", year);
    printf("Press any key to continue...\n");
    getchar();

    // Change the year in the struct tm
    time_struct.tm_year = year - 1900;

    // Convert the struct tm back to a time_t
    time_t travel_time = mktime(&time_struct);

    // Check if the time travel was successful
    if (travel_time == -1) {
        printf("Time travel failed. Please try again.\n");
        return 1;
    }

    // Print the new time
    printf("Time travel successful!\n");
    printf("Current year: %d\n", time_struct.tm_year + 1900);

    return 0;
}