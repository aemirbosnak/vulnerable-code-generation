//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare global variables for time travel
int currentYear;
int currentMonth;
int currentDay;

void timeTravel(int year, int month, int day) {
    // Set current date to user specified date
    currentYear = year;
    currentMonth = month;
    currentDay = day;
    
    // Print message to user
    printf("You have successfully traveled to %d/%d/%d\n", currentDay, currentMonth, currentYear);
}

void jumpToYear(int year) {
    // Set current year to user specified year
    currentYear = year;
    
    // Print message to user
    printf("You have successfully jumped to the year %d\n", currentYear);
}

void printCurrentDate() {
    // Print current date to user
    printf("The current date is %d/%d/%d\n", currentDay, currentMonth, currentYear);
}

int main() {
    // Set seed for random number generator
    srand(time(NULL));
    
    // Randomize current date between years 2020-2025
    currentYear = rand() % 6 + 2020;
    currentMonth = rand() % 12 + 1;
    currentDay = rand() % 31 + 1;
    
    // Print initial current date to user
    printf("Welcome to the Time Travel Simulator!\n");
    printf("The current date is %d/%d/%d\n", currentDay, currentMonth, currentYear);
    
    // Offer time travel options to user
    printf("What would you like to do?\n");
    printf("1. Time Travel to a Specific Date\n");
    printf("2. Jump to a Specific Year\n");
    printf("3. View Current Date\n");
    printf("4. Quit\n");
    
    // Allow user to make a choice (keep running until choice 4 is made)
    int choice;
    while (choice != 4) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                // Prompt user for date to travel to
                int year, month, day;
                printf("Enter the year: ");
                scanf("%d", &year);
                printf("Enter the month: ");
                scanf("%d", &month);
                printf("Enter the day: ");
                scanf("%d", &day);
                
                // Call time travel function
                timeTravel(year, month, day);
                break;
            }
            case 2: {
                // Prompt user for year to jump to
                int year;
                printf("Enter the year: ");
                scanf("%d", &year);
                
                // Call jump to year function
                jumpToYear(year);
                break;
            }
            case 3: {
                // Call function to print current date
                printCurrentDate();
                break;
            }
            case 4: {
                // Exit program
                printf("Thanks for using the Time Travel Simulator!\n");
                break;
            }
            default: {
                // Invalid choice, prompt user to try again
                printf("Invalid choice, please try again.\n");
            }
        }
    }
    
    return 0;
}