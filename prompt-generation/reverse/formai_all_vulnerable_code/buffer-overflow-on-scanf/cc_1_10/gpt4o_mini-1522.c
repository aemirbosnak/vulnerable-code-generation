//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    int id;
    char description[256];
    Date travelDate;
} TimeTravelDestination;

void initializeDestinations(TimeTravelDestination *destinations) {
    // Predefined destinations
    destinations[0] = (TimeTravelDestination){1, "Jurassic Period - Witness Dinosaurs", {65, 0, 1}};
    destinations[1] = (TimeTravelDestination){2, "Ancient Rome - Experience the Colosseum", {80, 6, 15}};
    destinations[2] = (TimeTravelDestination){3, "Renaissance Florence - Meet Leonardo da Vinci", {1500, 0, 1}};
    destinations[3] = (TimeTravelDestination){4, "Moon Landing - Apollo 11 Mission", {1969, 6, 20}};
    destinations[4] = (TimeTravelDestination){5, "Modern Day - See the Technology", {2023, 0, 1}};
}

void displayDestinations(TimeTravelDestination *destinations, int size) {
    printf("Available Time Travel Destinations:\n");
    for (int i = 0; i < size; i++) {
        printf("%d: %s | Date: %04d-%02d-%02d\n", 
               destinations[i].id, destinations[i].description, 
               destinations[i].travelDate.year + 1900, 
               destinations[i].travelDate.month + 1, 
               destinations[i].travelDate.day);
    }
}

void travelToDestination(TimeTravelDestination selectedDestination) {
    printf("Traveling to: %s...\n", selectedDestination.description);
    printf("Arrived on date: %04d-%02d-%02d\n", 
            selectedDestination.travelDate.year + 1900, 
            selectedDestination.travelDate.month + 1, 
            selectedDestination.travelDate.day);
    printf("Enjoy your time travel experience!\n");
}

int main() {
    const int numDestinations = 5;
    TimeTravelDestination destinations[numDestinations];
    
    initializeDestinations(destinations);
    
    int choice = 0;

    while (1) {
        displayDestinations(destinations, numDestinations);
        printf("\nSelect a destination by ID (1-%d) or 0 to exit: ", numDestinations);
        scanf("%d", &choice);
        
        if (choice == 0) {
            printf("Exiting Time Travel Simulator. Safe travels!\n");
            break;
        } else if (choice < 1 || choice > numDestinations) {
            printf("Invalid choice. Please try again.\n");
        } else {
            travelToDestination(destinations[choice - 1]);
            printf("\n");
        }
        
        printf("Would you like to travel again? (1 for Yes, 0 for No): ");
        int repeat;
        scanf("%d", &repeat);
        if (repeat == 0) {
            printf("Thank you for using the Time Travel Simulator. Goodbye!\n");
            break;
        }
    }

    return 0;
}