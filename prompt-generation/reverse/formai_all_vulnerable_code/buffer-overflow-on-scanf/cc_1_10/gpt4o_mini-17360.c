//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100
#define BAG_ID_LENGTH 20
#define NAME_LENGTH 50

typedef struct {
    char bagID[BAG_ID_LENGTH];
    char ownerName[NAME_LENGTH];
    int weight; // In kilograms
} Bag;

typedef struct {
    Bag* bags[MAX_BAGS];
    int count;
} BaggageSystem;

void initializeSystem(BaggageSystem* system) {
    system->count = 0;
}

int addBag(BaggageSystem* system, const char* bagID, const char* ownerName, int weight) {
    if (system->count >= MAX_BAGS) {
        printf("Baggage system is full!\n");
        return -1;
    }
    Bag* bag = (Bag*)malloc(sizeof(Bag));
    if (bag == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }
    strcpy(bag->bagID, bagID);
    strcpy(bag->ownerName, ownerName);
    bag->weight = weight;
    
    system->bags[system->count++] = bag;
    printf("Bag %s added successfully.\n", bagID);
    return 0;
}

void displayBags(const BaggageSystem* system) {
    if (system->count == 0) {
        printf("No bags in the system.\n");
        return;
    }
    printf("Current baggage in the system:\n");
    for (int i = 0; i < system->count; i++) {
        Bag* b = system->bags[i];
        printf("Bag ID: %s, Owner: %s, Weight: %d kg\n", b->bagID, b->ownerName, b->weight);
    }
}

int removeBag(BaggageSystem* system, const char* bagID) {
    for (int i = 0; i < system->count; i++) {
        if (strcmp(system->bags[i]->bagID, bagID) == 0) {
            free(system->bags[i]);
            system->bags[i] = system->bags[system->count - 1]; // Move last bag to current position
            system->count--;
            printf("Bag %s removed successfully.\n", bagID);
            return 0;
        }
    }
    printf("Bag %s not found in the system.\n", bagID);
    return -1;
}

void clearSystem(BaggageSystem* system) {
    for (int i = 0; i < system->count; i++) {
        free(system->bags[i]);
    }
    system->count = 0;
}

int main() {
    BaggageSystem system;
    initializeSystem(&system);
    int choice;
    char bagID[BAG_ID_LENGTH];
    char ownerName[NAME_LENGTH];
    int weight;

    do {
        printf("\n--- Baggage Handling System ---\n");
        printf("1. Add Bag\n");
        printf("2. Remove Bag\n");
        printf("3. Display Bags\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                printf("Enter Bag ID: ");
                fgets(bagID, BAG_ID_LENGTH, stdin);
                bagID[strcspn(bagID, "\n")] = '\0'; // Remove newline

                printf("Enter Owner Name: ");
                fgets(ownerName, NAME_LENGTH, stdin);
                ownerName[strcspn(ownerName, "\n")] = '\0'; // Remove newline

                printf("Enter Weight (kg): ");
                scanf("%d", &weight);
                getchar(); // Clear the newline character

                addBag(&system, bagID, ownerName, weight);
                break;
            case 2:
                printf("Enter Bag ID to remove: ");
                fgets(bagID, BAG_ID_LENGTH, stdin);
                bagID[strcspn(bagID, "\n")] = '\0'; // Remove newline

                removeBag(&system, bagID);
                break;
            case 3:
                displayBags(&system);
                break;
            case 4:
                clearSystem(&system);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}