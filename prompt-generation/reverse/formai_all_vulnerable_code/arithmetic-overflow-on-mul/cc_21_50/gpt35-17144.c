//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Counter for days passed
    int days_passed = 0;
    
    // Seed for random number generator
    srand(time(NULL));
    
    // Game starts in year 1400, January 1st
    int year = 1400, month = 1, day = 1;
    
    // Loop until the player decides to stop
    while (1) {
        printf("\n\nYou are in the year %d, %s %d, on day %d.\n", year, (month == 1) ? "January" : (month == 2) ? "February" : (month == 3) ? "March" : (month == 4) ? "April" : (month == 5) ? "May" : (month == 6) ? "June" : (month == 7) ? "July" : (month == 8) ? "August" : (month == 9) ? "September" : (month == 10) ? "October" : (month == 11) ? "November" : "December", day, days_passed);
        
        printf("What would you like to do?\n");
        printf("1. Travel to a specific year\n");
        printf("2. Travel to a specific month and day\n");
        printf("3. Stop playing\n");
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter the year you would like to travel to: ");
            int target_year;
            scanf("%d", &target_year);
            
            // Calculate time difference and update days_passed accordingly
            int time_diff = abs(target_year - year) * 365;
            days_passed += time_diff;
            
            printf("Travelling to year %d...\n", target_year);
            printf("Time travelled %d days.\n", time_diff);
            
            year = target_year;
            
            // Random event based on the year
            if (year >= 1380 && year <= 1420) {
                printf("You encounter a group of bandits, but manage to escape.\n");
            } else if (year == 1350 || year == 1400) {
                printf("You witness a major battle between two kingdoms.\n");
            }
        } else if (choice == 2) {
            printf("Enter the month and day you would like to travel to (mm/dd): ");
            char target_date[6];
            scanf("%s", target_date);
            
            int target_month = atoi(target_date);
            int target_day = atoi(target_date + 3);
            
            // Calculate time difference and update days_passed accordingly
            int time_diff = (abs(target_month - month) * 30) + abs(target_day - day);
            days_passed += time_diff;
            
            printf("Travelling to %s %d...\n", (target_month == 1) ? "January" : (target_month == 2) ? "February" : (target_month == 3) ? "March" : (target_month == 4) ? "April" : (target_month == 5) ? "May" : (target_month == 6) ? "June" : (target_month == 7) ? "July" : (target_month == 8) ? "August" : (target_month == 9) ? "September" : (target_month == 10) ? "October" : (target_month == 11) ? "November" : "December", target_day);
            printf("Time travelled %d days.\n", time_diff);
            
            month = target_month;
            day = target_day;
            
            // Random event based on the month and day
            if (month == 12 && day == 25) {
                printf("You witness a grand feast in honor of Christmas.\n");
            } else if (month == 10 && (day >= 27 && day <= 31)) {
                printf("You encounter ghosts and ghouls on a spooky Halloween night.\n");
            }
        } else if (choice == 3) {
            printf("Thanks for playing. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    
    return 0;
}