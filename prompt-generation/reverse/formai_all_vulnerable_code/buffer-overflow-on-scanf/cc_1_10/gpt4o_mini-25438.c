//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void displayMenu();
void travelToYear(int year);
void provideHistoricalEvent(int year);

// Data structure to hold historical events
typedef struct {
    int year;
    char event[256];
} HistoricalEvent;

// Array of historical events
HistoricalEvent events[] = {
    { 1776, "The Declaration of Independence was adopted in the U.S." },
    { 1865, "The American Civil War ends." },
    { 1969, "Apollo 11 lands humans on the Moon." },
    { 1989, "The Berlin Wall falls." },
    { 2000, "The turn of the millennium." },
    { 2020, "The world experiences a global pandemic." }
};

int main() {
    int choice;
    int year;

    while (1) {
        displayMenu();
        
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the year you wish to travel to: ");
                scanf("%d", &year);
                travelToYear(year);
                break;
                
            case 2:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

// Display the menu
void displayMenu() {
    printf("\n********** Time Travel Simulator **********\n");
    printf("1. Travel to a specific year\n");
    printf("2. Exit\n");
    printf("********************************************\n");
}

// Function to simulate traveling to a specific year
void travelToYear(int year) {
    printf("Time traveling...\n");
    sleep(2); // Simulate travel time
    printf("You have arrived in the year %d.\n", year);
    provideHistoricalEvent(year);
}

// Provide historical event based on the year
void provideHistoricalEvent(int year) {
    int found = 0;
    for (int i = 0; i < sizeof(events)/sizeof(events[0]); i++) {
        if (events[i].year == year) {
            printf("Historical Event: %s\n", events[i].event);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No significant historical event found for the year %d.\n", year);
    }
}