//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure representing a Time Traveler
typedef struct {
    char name[50];
    int year;
} TimeTraveler;

// Function to display available years for time travel
void showYearsAvailable() {
    printf("Available years to travel to:\n");
    printf("1. 1920\n");
    printf("2. 1969\n");
    printf("3. 1984\n");
    printf("4. 2020\n");
    printf("5. 2121\n");
    printf("Select a year by entering the corresponding number: ");
}

// Function to perform time travel
void timeTravel(TimeTraveler *traveler) {
    int choice;
    showYearsAvailable();
    
    scanf("%d", &choice);

    // Map user choice to a specific year
    switch (choice) {
        case 1:
            traveler->year = 1920;
            break;
        case 2:
            traveler->year = 1969;
            break;
        case 3:
            traveler->year = 1984;
            break;
        case 4:
            traveler->year = 2020;
            break;
        case 5:
            traveler->year = 2121;
            break;
        default:
            printf("Invalid choice! Please select a valid year.\n");
            return;
    }

    printf("%s, you're about to travel to the year %d!\n", traveler->name, traveler->year);
    printf("Tick... Tock... Time traveling...\n");
    sleep(3);
    printf("Welcome to the year %d!\n", traveler->year);
}

// Function to set the traveler's name
void setTravelerName(TimeTraveler *traveler) {
    printf("Enter your name, brave time traveler: ");
    scanf("%s", traveler->name);
}

// Entry point of the program
int main() {
    TimeTraveler traveler;
    traveler.year = 2023; // Starting year, current time

    printf("** Welcome to the Time Travel Simulator! **\n\n");

    // Collecting traveler's name
    setTravelerName(&traveler);

    // Introduction
    printf("Hello, %s! You can now travel through time.\n", traveler.name);
    
    while (1) {
        // Offering time travel option
        printf("Would you like to travel through time? (1 for Yes, 0 for No): ");
        int decision;
        scanf("%d", &decision);
        
        if (decision == 1) {
            timeTravel(&traveler);
        } else {
            printf("Thank you for using the Time Travel Simulator. Safe travels!\n");
            break;
        }

        // Option to return to present
        char returnToPresent;
        printf("Would you like to return to the present? (Y/N): ");
        scanf(" %c", &returnToPresent);
        
        if (returnToPresent == 'Y' || returnToPresent == 'y') {
            printf("Returning to the present...\n");
            printf("Safe travels, %s!\n", traveler.name);
            traveler.year = 2023; // Resetting to present
        }
    }

    return 0;
}