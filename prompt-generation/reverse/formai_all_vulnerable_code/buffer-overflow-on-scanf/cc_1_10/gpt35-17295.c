//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <time.h>

// Define time periods
typedef enum {
    PREHISTORIC,
    ANCIENT,
    MEDIEVAL,
    MODERN
} time_period;

// Define events
typedef enum {
    DINOSAURS,
    PYRAMIDS,
    KNIGHTS,
    SPACE_TRAVEL
} event;

// Define time traveler
typedef struct {
    char name[20];
    time_period period;
    event event;
} time_traveler;

// Define function that returns a random number between min and max
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Define function that creates a random time traveler
time_traveler create_time_traveler() {
    // Initialize time traveler
    time_traveler traveler;

    // Ask for traveler's name
    printf("Enter your name: ");
    scanf("%s", traveler.name);

    // Generate random period and event
    traveler.period = random_number(PREHISTORIC, MODERN);
    traveler.event = random_number(DINOSAURS, SPACE_TRAVEL);

    return traveler;
}

// Define function that displays time traveler's information
void print_time_traveler(time_traveler traveler) {
    printf("Name: %s\n", traveler.name);

    switch (traveler.period) {
        case PREHISTORIC:
            printf("Period: Prehistoric\n");
            break;
        case ANCIENT:
            printf("Period: Ancient\n");
            break;
        case MEDIEVAL:
            printf("Period: Medieval\n");
            break;
        case MODERN:
            printf("Period: Modern\n");
            break;
    }

    switch (traveler.event) {
        case DINOSAURS:
            printf("Event: Dinosaurs\n");
            break;
        case PYRAMIDS:
            printf("Event: Pyramids\n");
            break;
        case KNIGHTS:
            printf("Event: Knights\n");
            break;
        case SPACE_TRAVEL:
            printf("Event: Space Travel\n");
            break;
    }
}

// Main function
int main() {
    // Seed rand with current time
    srand(time(NULL));

    // Create a time traveler
    time_traveler traveler = create_time_traveler();

    // Display time traveler's information
    print_time_traveler(traveler);

    return 0;
}