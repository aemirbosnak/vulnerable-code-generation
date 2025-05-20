//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define BAG_ID_LENGTH 10

typedef struct {
    char id[BAG_ID_LENGTH];
    char owner[50];
    char destination[50];
    int processed;
} Baggage;

Baggage baggageList[MAX_BAGS];
int bagCount = 0;

void addBaggage() {
    if (bagCount >= MAX_BAGS) {
        printf("Baggage limit reached! Cannot add more bags.\n");
        return;
    }
    
    Baggage newBag;
    printf("Enter bag ID: ");
    scanf("%s", newBag.id);
    printf("Enter owner's name: ");
    scanf("%s", newBag.owner);
    printf("Enter destination: ");
    scanf("%s", newBag.destination);
    newBag.processed = 0;

    baggageList[bagCount] = newBag;
    bagCount++;
    printf("Baggage %s added successfully!\n", newBag.id);
}

void processBaggage() {
    if (bagCount == 0) {
        printf("No baggage to process!\n");
        return;
    }
    
    for (int i = 0; i < bagCount; i++) {
        if (!baggageList[i].processed) {
            baggageList[i].processed = 1;
            printf("Processing baggage ID: %s for %s to %s.\n", 
                   baggageList[i].id, baggageList[i].owner, baggageList[i].destination);
            return;
        }
    }
    printf("All baggage has been processed.\n");
}

void checkBaggageStatus() {
    if (bagCount == 0) {
        printf("No baggage stored!\n");
        return;
    }
    
    printf("Baggage Status:\n");
    for (int i = 0; i < bagCount; i++) {
        printf("Bag ID: %s, Owner: %s, Destination: %s, Processed: %s\n", 
               baggageList[i].id, baggageList[i].owner, baggageList[i].destination, 
               baggageList[i].processed ? "Yes" : "No");
    }
}

void displayMenu() {
    printf("\n--- Airport Baggage Handling System ---\n");
    printf("1. Add Baggage\n");
    printf("2. Process Baggage\n");
    printf("3. Check Baggage Status\n");
    printf("4. Exit\n");
    printf("-----------------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBaggage();
                break;
            case 2:
                processBaggage();
                break;
            case 3:
                checkBaggageStatus();
                break;
            case 4:
                printf("Exiting the baggage handling simulation. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}