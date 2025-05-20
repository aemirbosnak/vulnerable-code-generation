//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void travelToYear(int year);
void printMainMenu();

int main() {
    srand(time(NULL)); // Initialize random seed
    
    int currentYear = 2022; // Set current year
    int destinationYear;
    int menuChoice;
    
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d.\n", currentYear);
    printf("______________________________________\n");
    
    do {
        printMainMenu();
        scanf("%d", &menuChoice);
        
        switch(menuChoice) {
            case 1:
                printf("Enter the year you want to travel to: ");
                scanf("%d", &destinationYear);
                travelToYear(destinationYear);
                currentYear = destinationYear;
                printf("You have reached the year %d!\n", currentYear);
                printf("______________________________________\n");
                break;
            case 2:
                printf("You are currently in the year %d.\n", currentYear);
                printf("______________________________________\n");
                break;
            case 3:
                printf("Thanks for using the Time Travel Simulator!\n");
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                printf("______________________________________\n");
                break;
        }
    } while(menuChoice != 3);
    
    return 0;
}

void travelToYear(int year) {
    int yearsToTravel = abs(year - 2022); // Calculate years to travel
    int i;
    
    if (year < 2022) { // Travel backwards in time
        printf("Traveling back in time...\n");
        for (i = yearsToTravel; i > 0; i--) {
            printf("You have arrived in the year %d.\n", 2022 - i);
        }
    }
    else if (year > 2022) { // Travel forwards in time
        printf("Traveling forward in time...\n");
        for (i = 1; i <= yearsToTravel; i++) {
            printf("You have arrived in the year %d.\n", 2022 + i);
        }
    }
    else { // Destination year is the same as current year
        printf("You are already in the year %d!\n", year);
    }
}

void printMainMenu() {
    printf("What would you like to do?\n");
    printf("1. Travel to a specific year\n");
    printf("2. Check current year\n");
    printf("3. Exit program\n");
    printf("Enter your choice: ");
}