//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to travel to the past
void travelToPast(int year) {
    printf("Traveling to the year %d\n", year);
    printf("You have arrived in the past!\n");
    // Other time-travel specific code here
}

// Function to travel to the future
void travelToFuture(int year) {
    printf("Traveling to the year %d\n", year);
    printf("Wow! You've made it to the future!\n");
    // Other time-travel specific code here
}

int main() {
    int currentYear = 2021;
    
    printf("Welcome to the time travel simulator!\n");
    
    int choice;
    int year;
    
    // Loop to keep giving options to time-travel until the user quits
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Travel to the past\n");
        printf("2. Travel to the future\n");
        printf("3. Quit\n");
        
        scanf("%d", &choice);
        
        // Switch statement to execute the user's choice
        switch(choice) {
            case 1:
                printf("What year would you like to travel to?\n");
                scanf("%d", &year);
                
                // Check if the user is trying to travel to a year after the current year
                if (year > currentYear) {
                    printf("You can't travel to the future!\n");
                }
                else {
                    travelToPast(year);
                }
                break;
                
            case 2:
                printf("What year would you like to travel to?\n");
                scanf("%d", &year);
                
                // Check if the user is trying to travel to a year before the current year
                if (year < currentYear) {
                    printf("You can't travel to the past!\n");
                }
                else {
                    travelToFuture(year);
                }
                break;
                
            case 3:
                printf("Thank you for using the time travel simulator!\n");
                break;
                
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 3); // End of the loop
    
    return 0;
}