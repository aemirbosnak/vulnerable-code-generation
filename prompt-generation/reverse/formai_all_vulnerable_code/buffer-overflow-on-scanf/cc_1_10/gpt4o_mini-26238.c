//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_DESTINATIONS 5
#define BAGS_TO_CHECK 3

const char *destinations[MAX_DESTINATIONS] = {
    "New York", 
    "Los Angeles", 
    "Chicago", 
    "Houston", 
    "Miami"
};

// Structure to represent a baggage entry
typedef struct {
    int id;
    char owner[50];
    char destination[50];
    int checkedIn;
} Baggage;

// Function to create a new baggage
Baggage createBaggage(int id, const char *owner, const char *destination) {
    Baggage bag;
    bag.id = id;
    strncpy(bag.owner, owner, sizeof(bag.owner));
    strncpy(bag.destination, destination, sizeof(bag.destination));
    bag.checkedIn = 0; // Not checked in initially
    return bag;
}

// Function to simulate baggage check-in
void checkInBaggage(Baggage *bag) {
    if (!bag->checkedIn) {
        bag->checkedIn = 1;
        printf("✅ Baggage ID %d for %s checked in successfully to %s!\n", bag->id, bag->owner, bag->destination);
    } else {
        printf("❌ Baggage ID %d for %s is already checked in!\n", bag->id, bag->owner);
    }
}

// Function to simulate sorting baggage based on destination
void sortBaggage(Baggage bags[], int count) {
    printf("\n🎉 Sorting bags by destination...\n");
    for (int i = 0; i < count; i++) {
        if (bags[i].checkedIn) {
            printf("🔄 Sorting Baggage ID %d to %s...\n", bags[i].id, bags[i].destination);
            sleep(2); // Simulates time taken to sort
        }
    }
}

// Function to simulate loading baggage onto a plane
void loadBaggage(Baggage bags[], int count) {
    printf("\n✈️ Loading bags onto the plane...\n");
    for (int i = 0; i < count; i++) {
        if (bags[i].checkedIn) {
            printf("🧳 Loading Baggage ID %d...\n", bags[i].id);
            sleep(1); // Simulates time taken to load
        }
    }
    printf("🚀 All bags loaded! Ready for takeoff!\n");
}

// Function to simulate the baggage handling process
void handleBaggage(Baggage bags[], int count) {
    for (int i = 0; i < count; i++) {
        checkInBaggage(&bags[i]);
        sleep(1); // Simulated inter-check-in delay
    }
    sortBaggage(bags, count);
    loadBaggage(bags, count);
}

int main() {
    srand(time(NULL)); // Seed for randomness
    printf("🎒 Welcome to the Airport Baggage Handling Simulation! 🎒\n");

    Baggage bags[MAX_BAGS];
    int bagCount = 0;

    // Simulate creating bags
    while (bagCount < MAX_BAGS) {
        char owner[50];
        printf("👤 Enter the owner's name for baggage %d: ", bagCount + 1);
        scanf("%s", owner);

        int destinationIndex = rand() % MAX_DESTINATIONS;
        bags[bagCount] = createBaggage(bagCount + 1, owner, destinations[destinationIndex]);
        bagCount++;
        printf("📦 Bag for %s designated to %s has been created! 🎈\n", owner, destinations[destinationIndex]);
        
        // Break if we reach max bags
        if (bagCount >= MAX_BAGS) {
            printf("😅 Maximum baggage count reached!\n");
            break;
        }
    }

    // Handle baggage processing
    handleBaggage(bags, bagCount);

    printf("\n🎊 Thank you for using our baggage handling system! 🎊\n");
    return 0;
}