//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum years for the time travel simulation
#define MAX_YEARS 3000
#define MIN_YEARS 1900

// Structure to hold the information about a time traveler
typedef struct {
    char name[50];
    int year;
} TimeTraveler;

// Function to create a time traveler
TimeTraveler createTimeTraveler(const char *name, int year) {
    TimeTraveler traveler;
    strncpy(traveler.name, name, sizeof(traveler.name) - 1);
    traveler.name[sizeof(traveler.name) - 1] = '\0'; // Ensure null termination
    traveler.year = year;
    return traveler;
}

// Function to display the time traveler's information
void displayTravelerInfo(TimeTraveler traveler) {
    printf("Traveler Name: %s\n", traveler.name);
    printf("Current Year: %d\n", traveler.year);
}

// Function to change the year of the time traveler
int changeYear(TimeTraveler *traveler, int newYear) {
    if (newYear < MIN_YEARS || newYear > MAX_YEARS) {
        printf("Invalid year! Please choose a year between %d and %d.\n", MIN_YEARS, MAX_YEARS);
        return -1;
    }
    traveler->year = newYear;
    return 0;
}

// Function to simulate a time jump
void timeJump(TimeTraveler *traveler) {
    int jumpYears;
    printf("Enter how many years you want to jump (positive for future, negative for past): ");
    scanf("%d", &jumpYears);

    int newYear = traveler->year + jumpYears;
    if (changeYear(traveler, newYear) == 0) {
        printf("You've jumped to the year %d!\n", traveler->year);
    }
}

// Function to display available options for time travel
void displayOptions() {
    printf("\n----- Time Travel Simulator -----\n");
    printf("1. Change Year\n");
    printf("2. Time Jump\n");
    printf("3. Display Traveler Info\n");
    printf("4. Exit\n");
}

// Main function
int main() {
    char name[50];
    int initialYear;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove the newline character

    printf("Enter your initial year (between %d and %d): ", MIN_YEARS, MAX_YEARS);
    scanf("%d", &initialYear);

    TimeTraveler traveler = createTimeTraveler(name, initialYear);

    int choice;
    do {
        displayOptions();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new year: ");
                scanf("%d", &initialYear);
                if (changeYear(&traveler, initialYear) == 0) {
                    printf("Year changed successfully!\n");
                }
                break;
            case 2:
                timeJump(&traveler);
                break;
            case 3:
                displayTravelerInfo(traveler);
                break;
            case 4:
                printf("Exiting the simulator. Safe travels!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}