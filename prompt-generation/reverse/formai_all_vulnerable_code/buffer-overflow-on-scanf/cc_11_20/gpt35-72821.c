//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setting seed for random number generator
    srand(time(NULL));

    // Initializing variables
    int year = 2022;
    int decision;
    int travel_distance;
    int time_elapsed;
    int minutes_elapsed;
    int seconds_elapsed;
    int new_year;
    int new_month;
    char* month_name;

    // Introduction
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You find yourself in a post-apocalyptic world where time travel has been invented.\n");
    printf("You have been given the opportunity to travel back in time to rewrite history.\n");

    // Main program loop
    while(year > 1900) {
        // Displaying current year
        printf("The current year is %d.\n", year);

        // Prompting user for travel distance
        printf("How many years would you like to travel back?\n");
        scanf("%d", &travel_distance);

        // Updating year
        new_year = year - travel_distance;

        // Determining month of new year
        new_month = rand() % 12 + 1;
        switch(new_month) {
            case 1:
                month_name = "January";
                break;
            case 2:
                month_name = "February";
                break;
            case 3:
                month_name = "March";
                break;
            case 4:
                month_name = "April";
                break;
            case 5:
                month_name = "May";
                break;
            case 6:
                month_name = "June";
                break;
            case 7:
                month_name = "July";
                break;
            case 8:
                month_name = "August";
                break;
            case 9:
                month_name = "September";
                break;
            case 10:
                month_name = "October";
                break;
            case 11:
                month_name = "November";
                break;
            case 12:
                month_name = "December";
                break;
        }

        // Calculating time elapsed
        time_elapsed = travel_distance * 365;
        minutes_elapsed = time_elapsed * 24 * 60;
        seconds_elapsed = minutes_elapsed * 60;

        // Displaying travel information
        printf("You have traveled back %d years to %s %d.\n", travel_distance, month_name, new_year);
        printf("Time elapsed: %d days, %d minutes, %d seconds.\n", time_elapsed, minutes_elapsed, seconds_elapsed);

        // Prompting for next action
        printf("What would you like to do?\n");
        printf("1. Go further back in time.\n");
        printf("2. Stay in this time period.\n");
        printf("3. Return to the present.\n");
        scanf("%d", &decision);

        // Updating year based on decision
        switch(decision) {
            case 1:
                year = new_year;
                break;
            case 2:
                // Do nothing
                break;
            case 3:
                year = 1900;
                break;
        }
    }

    // End of program
    printf("Thanks for using the Time Travel Simulator!\n");

    return 0;
}