//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char bagID[MAX_NAME_LENGTH];
    char ownerName[MAX_NAME_LENGTH];
    int weight;  // Weight in kg
} Baggage;

Baggage baggageList[MAX_BAGS];
int bagCount = 0;

void addBaggage() {
    if (bagCount >= MAX_BAGS) {
        printf("🎒 Sorry! The baggage area is full! Can't add more bags. 🎒\n");
        return;
    }
    Baggage bag;
    printf("🎈 Enter Bag ID: ");
    scanf("%s", bag.bagID);
    printf("🎈 Enter Owner Name: ");
    scanf("%s", bag.ownerName);
    printf("🎈 Enter Weight (kg): ");
    scanf("%d", &bag.weight);
  
    baggageList[bagCount++] = bag;
    printf("🎉 Baggage added successfully! 🎉\n");
}

void removeBaggage() {
    if (bagCount == 0) {
        printf("👜 There's no baggage to remove! 👜\n");
        return;
    }
    char bagID[MAX_NAME_LENGTH];
    printf("🧳 Enter Bag ID to remove: ");
    scanf("%s", bagID);
    
    for (int i = 0; i < bagCount; i++) {
        if (strcmp(baggageList[i].bagID, bagID) == 0) {
            printf("🚀 Removing bag ID: %s (Owner: %s, Weight: %d kg) 🚀\n",
                   baggageList[i].bagID, baggageList[i].ownerName, baggageList[i].weight);
            for (int j = i; j < bagCount - 1; j++) {
                baggageList[j] = baggageList[j + 1];
            }
            bagCount--;
            printf("✅ Baggage removed successfully! ✅\n");
            return;
        }
    }
    printf("❌ Bag ID not found! ❌\n");
}

void displayBaggage() {
    if (bagCount == 0) {
        printf("📦 No baggage currently in the system! 📦\n");
        return;
    }
    printf("\n🎉 Baggage List 🎉\n");
    printf("────────────────────────────\n");
    for (int i = 0; i < bagCount; i++) {
        printf("🧳 Bag ID: %s | Owner: %s | Weight: %d kg 🧳\n",
               baggageList[i].bagID, baggageList[i].ownerName, baggageList[i].weight);
    }
    printf("────────────────────────────\n");
}

void displayMenu() {
    printf("\n✨ Welcome to the Baggage Handling System! ✨\n");
    printf("1. Add Baggage\n");
    printf("2. Remove Baggage\n");
    printf("3. Display Baggage\n");
    printf("4. Exit\n");
    printf("🍀 Please choose an option (1-4): ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBaggage();
                break;
            case 2:
                removeBaggage();
                break;
            case 3:
                displayBaggage();
                break;
            case 4:
                printf("🎈 Thank you for using the baggage handling system! Have a great day! 🎈\n");
                break;
            default:
                printf("❓ Invalid option! Please select a valid option (1-4). ❓\n");
        }
    } while (choice != 4);

    return 0;
}