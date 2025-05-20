//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_NAME_LENGTH 30

typedef struct {
    int id;
    char owner[MAX_NAME_LENGTH];
    char status[20];
} Baggage;

Baggage baggageList[MAX_BAGGAGE];
int baggageCount = 0;

void checkInBaggage() {
    if (baggageCount >= MAX_BAGGAGE) {
        printf("Whoa! The baggage system is full! Can't check in any more baggage!\n");
        return;
    }
    
    Baggage newBaggage;
    newBaggage.id = baggageCount + 1; // ID starts from 1
    printf("Enter the owner's name for baggage ID %d: ", newBaggage.id);
    scanf("%s", newBaggage.owner);
    strcpy(newBaggage.status, "Checked In");
    baggageList[baggageCount] = newBaggage;

    printf("Surprisingly, baggage from %s has been checked in with ID %d!\n", newBaggage.owner, newBaggage.id);
    baggageCount++;
}

void processBaggage() {
    for (int i = 0; i < baggageCount; i++) {
        if (strcmp(baggageList[i].status, "Checked In") == 0) {
            printf("Processing baggage ID %d belonging to %s...\n", baggageList[i].id, baggageList[i].owner);
            sleep(1); // Simulate processing time
            
            strcpy(baggageList[i].status, "In Transit");
            printf("Surprise! Baggage ID %d is now in transit!\n", baggageList[i].id);
        }
    }
}

void loadBaggage() {
    for (int i = 0; i < baggageCount; i++) {
        if (strcmp(baggageList[i].status, "In Transit") == 0) {
            printf("Loading baggage ID %d belonging to %s onto the plane...\n", baggageList[i].id, baggageList[i].owner);
            sleep(1); // Simulate loading time
            
            strcpy(baggageList[i].status, "Loaded");
            printf("Whoa! Baggage ID %d has been successfully loaded!\n", baggageList[i].id);
        }
    }
}

void displayBaggageStatus() {
    printf("\nBaggage Status Report:\n");
    for (int i = 0; i < baggageCount; i++) {
        printf("Baggage ID: %d, Owner: %s, Status: %s\n", baggageList[i].id, baggageList[i].owner, baggageList[i].status);
    }
    printf("\n");
}

int main() {
    int choice;
    srand(time(NULL)); // Initialize random seed

    while (1) {
        printf("Welcome to the Baggage Handling Simulation!\n");
        printf("1. Check In Baggage\n");
        printf("2. Process Baggage\n");
        printf("3. Load Baggage\n");
        printf("4. Display Baggage Status\n");
        printf("5. Exit Simulation\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkInBaggage();
                break;
            case 2:
                processBaggage();
                break;
            case 3:
                loadBaggage();
                break;
            case 4:
                displayBaggageStatus();
                break;
            case 5:
                printf("Exiting the Baggage Handling Simulation! Until next time!\n");
                return 0;
            default:
                printf("Oops! That's not a valid option. Please try again.\n");
        }
    }
    
    return 0;
}