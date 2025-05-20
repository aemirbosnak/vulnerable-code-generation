//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIPS 10
#define MAX_YEAR 3000
#define MIN_YEAR 1000

typedef struct {
    int year;
    char destination[50];
    char description[200];
} TimeTrip;

void greetUser() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel to various points in time. Let's explore!\n");
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Plan a time trip\n");
    printf("2. View planned trips\n");
    printf("3. Travel to a trip\n");
    printf("4. Exit\n");
}

void planTrip(TimeTrip* trips, int* count) {
    if (*count >= MAX_TRIPS) {
        printf("You have reached the maximum number of trips you can plan.\n");
        return;
    }

    TimeTrip trip;
    printf("Enter the year to travel to (between %d and %d): ", MIN_YEAR, MAX_YEAR);
    scanf("%d", &trip.year);
    if (trip.year < MIN_YEAR || trip.year > MAX_YEAR) {
        printf("Invalid year! Please select a year between %d and %d.\n", MIN_YEAR, MAX_YEAR);
        return;
    }

    getchar(); // Clear newline character
    printf("Enter the destination (e.g., Ancient Rome): ");
    fgets(trip.destination, sizeof(trip.destination), stdin);
    trip.destination[strcspn(trip.destination, "\n")] = '\0'; // Remove newline

    printf("Describe your trip: ");
    fgets(trip.description, sizeof(trip.description), stdin);
    trip.description[strcspn(trip.description, "\n")] = '\0'; // Remove newline

    trips[*count] = trip;
    (*count)++;
    printf("Trip planned to %s in the year %d!\n", trip.destination, trip.year);
}

void viewTrips(TimeTrip* trips, int count) {
    if (count == 0) {
        printf("No trips planned yet!\n");
        return;
    }
    printf("\nPlanned Trips:\n");
    for (int i = 0; i < count; i++) {
        printf("Trip %d: Year %d, Destination: %s, Description: %s\n", 
            i + 1, trips[i].year, trips[i].destination, trips[i].description);
    }
}

void travelToTrip(TimeTrip* trips, int count) {
    if (count == 0) {
        printf("No trips planned yet!\n");
        return;
    }

    int choice;
    printf("Select a trip to travel to (1-%d): ", count);
    scanf("%d", &choice);
    if (choice < 1 || choice > count) {
        printf("Invalid choice! Please select a trip number between 1 and %d.\n", count);
        return;
    }

    TimeTrip trip = trips[choice - 1];
    printf("Traveling to %s in the year %d...\n", trip.destination, trip.year);
    // Simulate time travel
    for (int i = 0; i < 3; i++) {
        printf("Time traveling...\n");
        sleep(1); // Simulate waiting time of 1 second
    }
    printf("You have arrived at your destination: %s, Year %d!\n", trip.destination, trip.year);
}

int main() {
    TimeTrip trips[MAX_TRIPS];
    int tripCount = 0;
    greetUser();
    
    while (1) {
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                planTrip(trips, &tripCount);
                break;
            case 2:
                viewTrips(trips, tripCount);
                break;
            case 3:
                travelToTrip(trips, tripCount);
                break;
            case 4:
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}