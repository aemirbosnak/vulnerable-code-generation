//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define BAG_DESC_LENGTH 50

typedef struct {
    int id;
    char description[BAG_DESC_LENGTH];
    int weight; // in kg
    char status[20]; // e.g., 'In Transit', 'Loaded', 'Lost'
} Baggage;

Baggage baggageList[MAX_BAGS];
int currentBags = 0;

void addBaggage();
void displayBaggage();
void loadBaggage();
void simulateBaggageHandling(int numBags);
void updateBaggageStatus(int index, const char *newStatus);

int main() {
    printf("🎉 Welcome to the Airport Baggage Handling Simulation! 🎉\n");

    srand(time(NULL)); // Seed random number generator

    int choice;
    do {
        printf("\n🎡 Menu 🎡\n");
        printf("1. Add Baggage\n");
        printf("2. Display Baggage\n");
        printf("3. Load Baggage onto Airplane\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBaggage();
                break;

            case 2:
                displayBaggage();
                break;

            case 3:
                loadBaggage();
                break;

            case 0:
                printf("🚀 Thank you for using the Baggage Handling Simulator! Goodbye! 🚀\n");
                break;

            default:
                printf("❌ Invalid choice! Please try again. ❌\n");
        }
    } while (choice != 0);

    return 0;
}

void addBaggage() {
    if (currentBags >= MAX_BAGS) {
        printf("❗ Cannot add more baggage! Maximum limit reached. ❗\n");
        return;
    }

    Baggage newBag;
    newBag.id = currentBags + 1; // Bag ID starts from 1
    printf("Enter description of the baggage: ");
    getchar(); // to clear the newline character after scanf
    fgets(newBag.description, BAG_DESC_LENGTH, stdin);
    newBag.description[strcspn(newBag.description, "\n")] = 0; // Remove newline
    printf("Enter weight of the baggage (in kg): ");
    scanf("%d", &newBag.weight);
    strcpy(newBag.status, "In Transit");

    baggageList[currentBags] = newBag;
    currentBags++;
    printf("✅ Baggage added successfully! ID: %d\n", newBag.id);
}

void displayBaggage() {
    if (currentBags == 0) {
        printf("⚠️ No baggage available to display! ⚠️\n");
        return;
    }

    printf("📦 Current Baggage List 📦\n");
    for (int i = 0; i < currentBags; i++) {
        printf("ID: %d, Description: %s, Weight: %d kg, Status: %s\n", 
                baggageList[i].id, baggageList[i].description, 
                baggageList[i].weight, baggageList[i].status);
    }
}

void loadBaggage() {
    if (currentBags == 0) {
        printf("⚠️ No baggage to load! ⚠️\n");
        return;
    }

    int bagsToLoad = rand() % (currentBags + 1); // Load a random number of bags
    printf("🚚 Loading %d baggage(s) onto the airplane... 🚚\n", bagsToLoad);

    for (int i = 0; i < bagsToLoad; i++) {
        int randomIndex = rand() % currentBags;
        updateBaggageStatus(randomIndex, "Loaded");
    }

    printf("✅ All selected baggage has been loaded successfully! ✅\n");
}

void updateBaggageStatus(int index, const char *newStatus) {
    strcpy(baggageList[index].status, newStatus);
}

void simulateBaggageHandling(int numBags) {
    // This function can be expanded to simulate different handling cases
    printf("🔄 Simulating baggage handling for %d bags... 🔄\n", numBags);
    for (int i = 0; i < numBags; i++) {
        // Simulate random operations (like lost bags, etc.)
        if (rand() % 10 < 2) { // 20% chance to 'lose' this bag
            updateBaggageStatus(i, "Lost");
            printf("⚠️ Baggage ID %d has been reported lost! ⚠️\n", baggageList[i].id);
        }
    }
}