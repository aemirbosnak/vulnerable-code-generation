//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char owner[MAX_NAME_LENGTH];
    int weight;
    int isLoaded;
} Baggage;

// Function to create a new baggage
Baggage createBaggage(int id, const char *owner, int weight) {
    Baggage bag;
    bag.id = id;
    strcpy(bag.owner, owner);
    bag.weight = weight;
    bag.isLoaded = 0;
    return bag;
}

// Function to check-in baggage
void checkInBaggage(Baggage *baggage, int *count) {
    if (*count >= MAX_BAGGAGE) {
        printf("No more baggage can be checked in!\n");
        return;
    }
    char owner[MAX_NAME_LENGTH];
    int weight;

    printf("Enter baggage owner's name: ");
    scanf("%s", owner);
    printf("Enter baggage weight (kg): ");
    scanf("%d", &weight);

    baggage[*count] = createBaggage(*count + 1, owner, weight);
    (*count)++;
    printf("Baggage checked in successfully!\n");
}

// Function to load baggage on the plane
void loadBaggage(Baggage *baggage, int count) {
    if (count == 0) {
        printf("No baggage available to load!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (baggage[i].isLoaded == 0) {
            baggage[i].isLoaded = 1; // Marking as loaded
            printf("Loading baggage ID %d belonging to %s weighing %d kg...\n",
                   baggage[i].id, baggage[i].owner, baggage[i].weight);
            sleep(1); // Simulating loading time
            printf("Baggage ID %d has been loaded successfully!\n", baggage[i].id);
        }
    }
}

// Function to unload baggage from the plane
void unloadBaggage(Baggage *baggage, int count) {
    for (int i = 0; i < count; i++) {
        if (baggage[i].isLoaded == 1) {
            baggage[i].isLoaded = 0; // Marking as unloaded
            printf("Unloading baggage ID %d belonging to %s...\n", baggage[i].id, baggage[i].owner);
            sleep(1); // Simulating unloading time
            printf("Baggage ID %d has been unloaded successfully!\n", baggage[i].id);
        }
    }
}

// Function to display all baggage
void displayBaggage(Baggage *baggage, int count) {
    if (count == 0) {
        printf("No baggage to display!\n");
        return;
    }
    printf("\nBaggage List:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Owner: %s, Weight: %d kg, Status: %s\n", 
               baggage[i].id, baggage[i].owner, baggage[i].weight, 
               baggage[i].isLoaded ? "Loaded" : "Not Loaded");
    }
}

int main() {
    Baggage baggage[MAX_BAGGAGE]; // Array to store baggage
    int count = 0; // Count of current baggage
    int choice;

    srand(time(NULL)); // Seed random number generator
    printf("Welcome to the Airport Baggage Handling System!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Check-in Baggage\n");
        printf("2. Load Baggage on Plane\n");
        printf("3. Unload Baggage from Plane\n");
        printf("4. Display All Baggage\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkInBaggage(baggage, &count);
                break;
            case 2:
                loadBaggage(baggage, count);
                break;
            case 3:
                unloadBaggage(baggage, count);
                break;
            case 4:
                displayBaggage(baggage, count);
                break;
            case 5:
                printf("Thank you for using the Baggage Handling System. Safe travels!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}