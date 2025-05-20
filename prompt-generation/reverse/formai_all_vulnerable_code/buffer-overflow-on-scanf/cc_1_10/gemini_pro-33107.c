//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Time travel simulator configuration
#define MAX_TIME_TRIPS 10
#define MAX_DESTINATION_YEAR 2100
#define MIN_DESTINATION_YEAR 1900
#define TIME_TRAVEL_COST 1000000

// Data structure to store time travel destinations
typedef struct {
    int year;
    char *description;
} TimeDestination;

// Array of time travel destinations
TimeDestination destinations[] = {
    {1920, "The Roaring Twenties"},
    {1969, "The Moon Landing"},
    {1989, "The Fall of the Berlin Wall"},
    {2001, "The First iPhone"},
    {2020, "The COVID-19 Pandemic"},
    {2050, "A Dystopian Future"},
    {2077, "Cyberpunk City"},
    {2100, "The Singularity"}
};

// Function to print the available time travel destinations
void printDestinations() {
    printf("Available time travel destinations:\n");
    for (int i = 0; i < sizeof(destinations) / sizeof(TimeDestination); i++) {
        printf("%d. %s\n", i + 1, destinations[i].description);
    }
}

// Function to get the user's input for the destination year
int getDestinationYear() {
    int year;
    printf("Enter the year you want to travel to (1900-2100): ");
    scanf("%d", &year);
    return year;
}

// Function to check if the destination year is valid
int isValidDestinationYear(int year) {
    return year >= MIN_DESTINATION_YEAR && year <= MAX_DESTINATION_YEAR;
}

// Function to get the user's input for the number of time trips
int getTimeTrips() {
    int timeTrips;
    printf("Enter the number of time trips you want to make (1-%d): ", MAX_TIME_TRIPS);
    scanf("%d", &timeTrips);
    return timeTrips;
}

// Function to check if the number of time trips is valid
int isValidTimeTrips(int timeTrips) {
    return timeTrips >= 1 && timeTrips <= MAX_TIME_TRIPS;
}

// Function to calculate the total cost of the time travel
int calculateCost(int timeTrips) {
    return timeTrips * TIME_TRAVEL_COST;
}

// Function to run the time travel simulation
void runSimulation() {
    // Print the available time travel destinations
    printDestinations();

    // Get the user's input for the destination year
    int destinationYear = getDestinationYear();

    // Check if the destination year is valid
    if (!isValidDestinationYear(destinationYear)) {
        printf("Invalid destination year. Please enter a year between 1900 and 2100.\n");
        return;
    }

    // Get the user's input for the number of time trips
    int timeTrips = getTimeTrips();

    // Check if the number of time trips is valid
    if (!isValidTimeTrips(timeTrips)) {
        printf("Invalid number of time trips. Please enter a number between 1 and %d.\n", MAX_TIME_TRIPS);
        return;
    }

    // Calculate the total cost of the time travel
    int cost = calculateCost(timeTrips);

    // Print the summary of the time travel simulation
    printf("Time travel summary:\n");
    printf("Destination year: %d\n", destinationYear);
    printf("Number of time trips: %d\n", timeTrips);
    printf("Total cost: %d\n", cost);

    // Ask the user if they want to confirm the time travel
    char confirmation;
    printf("Do you want to confirm the time travel? (Y/N): ");
    scanf(" %c", &confirmation);

    // If the user confirms the time travel, print a success message
    if (confirmation == 'Y' || confirmation == 'y') {
        printf("Time travel confirmed. Bon voyage!\n");
    } else {
        printf("Time travel cancelled.\n");
    }
}

int main() {
    // Run the time travel simulation
    runSimulation();

    return 0;
}