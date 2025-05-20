//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_LENGTH 30

typedef struct {
    char id[MAX_LENGTH];
    char destination[MAX_LENGTH];
    int weight;
    int checked_in;
} Baggage;

typedef struct {
    Baggage bags[MAX_BAGS];
    int count;
} BaggageSystem;

void initializeSystem(BaggageSystem *system) {
    system->count = 0;
}

void checkInBaggage(BaggageSystem *system) {
    if(system->count >= MAX_BAGS) {
        printf("Cannot check in more bags, system full!\n");
        return;
    }
    Baggage newBag;
    printf("Enter baggage ID: ");
    scanf("%s", newBag.id);
    printf("Enter destination: ");
    scanf("%s", newBag.destination);
    printf("Enter weight: ");
    scanf("%d", &newBag.weight);
    newBag.checked_in = 1; // Mark as checked-in
    system->bags[system->count++] = newBag;
    printf("Baggage %s checked in successfully!\n", newBag.id);
}

void moveBaggage(BaggageSystem *system) {
    for(int i = 0; i < system->count; i++) {
        if(system->bags[i].checked_in) {
            printf("Moving baggage ID: %s to %s...\n", system->bags[i].id, system->bags[i].destination);
            // Simulate movement with a sleep
            printf("Baggage ID: %s arrived at %s terminal.\n", system->bags[i].id, system->bags[i].destination);
            system->bags[i].checked_in = 0; // Mark as moved
        }
    }
}

void retrieveBaggage(BaggageSystem *system) {
    char bagId[MAX_LENGTH];
    printf("Enter baggage ID to retrieve: ");
    scanf("%s", bagId);
    for (int i = 0; i < system->count; i++) {
        if (strcmp(system->bags[i].id, bagId) == 0) {
            if (!system->bags[i].checked_in) {
                printf("Baggage ID: %s retrieved successfully!\n", bagId);
                // Optionally remove the bag from the system
                system->bags[i] = system->bags[--system->count]; // Pop the last item into this spot
                return;
            } else {
                printf("Baggage ID: %s is not available for retrieval yet.\n", bagId);
                return;
            }
        }
    }
    printf("Baggage ID not found!\n");
}

void displayBaggage(BaggageSystem *system) {
    printf("=== Current Baggage ===\n");
    for(int i = 0; i < system->count; i++) {
        printf("ID: %s, Destination: %s, Weight: %d kg, Checked In: %s\n",
            system->bags[i].id, system->bags[i].destination, system->bags[i].weight,
            system->bags[i].checked_in ? "Yes" : "No");
    }
}

int main() {
    BaggageSystem system;
    initializeSystem(&system);
    int choice;

    do {
        printf("\n=== Airport Baggage Handling System ===\n");
        printf("1. Check-in Baggage\n");
        printf("2. Move Baggage\n");
        printf("3. Retrieve Baggage\n");
        printf("4. Display All Baggage\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkInBaggage(&system);
                break;
            case 2:
                moveBaggage(&system);
                break;
            case 3:
                retrieveBaggage(&system);
                break;
            case 4:
                displayBaggage(&system);
                break;
            case 5:
                printf("Thank you for using the Baggage Handling System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}