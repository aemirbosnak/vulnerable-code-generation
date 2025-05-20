//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int current_year = 2021; // set the current year
    int year_to_travel; // declare the year variable to travel to
    int year_difference; // declare the variable to hold difference between current and travel year
    int choice; // declare the user's choice variable
    srand(time(NULL)); // seed the random number generator with current time

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("You are currently in the year %d.\n", current_year);

    do {
        printf("\nWhat would you like to do? Choose an option from the following menu:\n");
        printf("1. Travel to a specific year\n");
        printf("2. Travel to a random year in the past or future\n");
        printf("3. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the year you want to travel to: ");
                scanf("%d", &year_to_travel);

                if(year_to_travel == current_year) {
                    printf("\nYou are already in that year!\n");
                } else if(year_to_travel < current_year) {
                    year_difference = current_year - year_to_travel;
                    printf("\nYou have travelled back in time by %d years to the year %d.\n", year_difference, year_to_travel);
                } else {
                    year_difference = year_to_travel - current_year;
                    printf("\nYou have travelled forward in time by %d years to the year %d.\n", year_difference, year_to_travel);
                }

                current_year = year_to_travel;
                break;

            case 2:
                year_to_travel = rand() % 10000; // generate a random year between 0 and 9999
                printf("\nYou have travelled to the year %d.\n", year_to_travel);

                if(year_to_travel == current_year) {
                    printf("\nYou are already in that year!\n");
                } else if(year_to_travel < current_year) {
                    year_difference = current_year - year_to_travel;
                    printf("\nYou have travelled back in time by %d years.\n", year_difference);
                } else {
                    year_difference = year_to_travel - current_year;
                    printf("\nYou have travelled forward in time by %d years.\n", year_difference);
                }

                current_year = year_to_travel;
                break;

            case 3:
                printf("\nThank you for using the Time Travel Simulator. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while(1); // loop indefinitely

    return 0;
}