//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_YEARS 5000
#define TIME_TRAVELER_NAME_LEN 50
#define BUFFER_SIZE 100

typedef struct {
    char name[TIME_TRAVELER_NAME_LEN];
    int timeTravelCount;
} TimeTraveler;

void initializeTraveler(TimeTraveler* traveler, const char* name) {
    strncpy(traveler->name, name, TIME_TRAVELER_NAME_LEN - 1);
    traveler->name[TIME_TRAVELER_NAME_LEN - 1] = '\0';  // Ensure null-termination
    traveler->timeTravelCount = 0;
}

void displayMenu() {
    printf("--------------------------------------------------\n");
    printf("             TIME TRAVEL SIMULATOR               \n");
    printf("--------------------------------------------------\n");
    printf("1. Travel to the Future\n");
    printf("2. Travel to the Past\n");
    printf("3. View Travel History\n");
    printf("4. Exit\n");
    printf("--------------------------------------------------\n");
}

void travelToFuture(TimeTraveler* traveler) {
    int years;
    printf("\nEnter the number of years to travel into the future: ");
    scanf("%d", &years);
    
    if (years <= 0 || years > MAX_YEARS) {
        printf("Invalid input! You can only travel between 1 and %d years.\n", MAX_YEARS);
        return;
    }

    traveler->timeTravelCount++;
    printf("!!! ZAP !!! You have traveled %d years into the future!\n\n", years);
}

void travelToPast(TimeTraveler* traveler) {
    int years;
    printf("\nEnter the number of years to travel into the past: ");
    scanf("%d", &years);
    
    if (years <= 0 || years > MAX_YEARS) {
        printf("Invalid input! You can only travel between 1 and %d years.\n", MAX_YEARS);
        return;
    }

    traveler->timeTravelCount++;
    printf("!!! WHOOSH !!! You have traveled %d years into the past!\n\n", years);
}

void viewTravelHistory(TimeTraveler* traveler) {
    if (traveler->timeTravelCount > 0) {
        printf("You have time-traveled %d times.\n\n", traveler->timeTravelCount);
    } else {
        printf("You have not traveled through time yet!\n\n");
    }
}

int main() {
    TimeTraveler traveler;
    initializeTraveler(&traveler, "Doc Brown");

    int choice;
    do {
        displayMenu();
        printf("Select an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travelToFuture(&traveler);
                break;
            case 2:
                travelToPast(&traveler);
                break;
            case 3:
                viewTravelHistory(&traveler);
                break;
            case 4:
                printf("Exiting Time Travel Simulator... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}