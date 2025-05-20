//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up initial variables
    int year = 2022;
    int month = 1;
    int day = 1;
    int hour = 0;
    int minute = 0;
    int second = 0;
    
    int choice; // User's choice for time shift
    int shift; // Amount of time to shift
    
    // Set up random number generator
    srand(time(NULL));
    
    // Start time travel simulator
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d.\n", year);
    printf("What would you like to do?\n");
    
    // Main program loop
    while (1)
    {
        printf("\n1. Shift forward in time\n");
        printf("2. Shift backwards in time\n");
        printf("3. Check current date and time\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                // Prompt user for amount of time to shift
                printf("\nHow many years forward would you like to go? (max 100) ");
                scanf("%d", &shift);
                
                if (shift > 100)
                {
                    printf("Sorry, you cannot shift more than 100 years at a time.\n");
                    break;
                }
                
                // Shift years
                year += shift;
                
                // Randomly shift months, days, hours, minutes, and seconds
                month += rand() % 12;
                day += rand() % 31;
                hour += rand() % 24;
                minute += rand() % 60;
                second += rand() % 60;
                
                // Account for overflow of minutes and seconds
                if (minute >= 60)
                {
                    minute -= 60;
                    hour++;
                }
                if (second >= 60)
                {
                    second -= 60;
                    minute++;
                }
                
                printf("\nYou have shifted %d years into the future.\n", shift);
                printf("The current date and time is %d-%02d-%02d %02d:%02d:%02d.\n", year, month, day, hour, minute, second);
                break;
                
            case 2:
                // Prompt user for amount of time to shift
                printf("\nHow many years backwards would you like to go? (max 100) ");
                scanf("%d", &shift);
                
                if (shift > 100)
                {
                    printf("Sorry, you cannot shift more than 100 years at a time.\n");
                    break;
                }
                
                // Shift years
                year -= shift;
                
                // Randomly shift months, days, hours, minutes, and seconds
                month -= rand() % 12;
                day -= rand() % 31;
                hour -= rand() % 24;
                minute -= rand() % 60;
                second -= rand() % 60;
                
                // Account for underflow of minutes and seconds
                if (minute < 0)
                {
                    minute += 60;
                    hour--;
                }
                if (second < 0)
                {
                    second += 60;
                    minute--;
                }
                
                printf("\nYou have shifted %d years into the past.\n", shift);
                printf("The current date and time is %d-%02d-%02d %02d:%02d:%02d.\n", year, month, day, hour, minute, second);
                break;
                
            case 3:
                printf("\nThe current date and time is %d-%02d-%02d %02d:%02d:%02d.\n", year, month, day, hour, minute, second);
                break;
                
            case 4:
                printf("\nThank you for using the Time Travel Simulator!\n");
                exit(0);
                
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}