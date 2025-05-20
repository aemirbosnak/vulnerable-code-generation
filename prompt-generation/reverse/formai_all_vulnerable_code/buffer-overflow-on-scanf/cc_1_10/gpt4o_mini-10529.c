//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_FLIGHTS 5

typedef struct {
    int bagID;
    char ownerName[50];
    int flightNumber;
    int isPickedUp;
} Baggage;

typedef struct {
    int flightNumber;
    char destination[50];
} Flight;

Baggage baggageInventory[MAX_BAGS];
Flight flightSchedule[MAX_FLIGHTS];

// Function declarations
void initializeFlights();
void checkInBaggage();
void listBaggage();
void pickUpBaggage();
void simulateBaggageHandling();

// Sherlock-style narrative printing
void narrative(const char *str) {
    printf("\n*** Sherlock Holmes deduced: %s ***\n", str);
}

int main() {
    srand(time(NULL));
    
    initializeFlights();
    simulateBaggageHandling();
    
    return 0;
}

void initializeFlights() {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flightSchedule[i].flightNumber = i + 1;
        sprintf(flightSchedule[i].destination, "Destination_%d", i + 1);
    }
    narrative("The flights have been initialized.");
}

void checkInBaggage() {
    for (int i = 0; i < MAX_BAGS; i++) {
        if (baggageInventory[i].bagID == 0) {
            baggageInventory[i].bagID = i + 1;
            printf("Enter the name of the bag owner (i.e. Watson, Holmes, etc.): ");
            scanf(" %[^\n]", baggageInventory[i].ownerName);
            baggageInventory[i].flightNumber = rand() % MAX_FLIGHTS + 1;
            baggageInventory[i].isPickedUp = 0;
            narrative("A new bag has been checked in.");
            return;
        }
    }
    narrative("The baggage check-in is full.");
}

void listBaggage() {
    printf("\n=== Current Baggage Inventory ===\n");
    for (int i = 0; i < MAX_BAGS; i++) {
        if (baggageInventory[i].bagID != 0) {
            printf("Bag ID: %d, Owner: %s, Flight Number: %d, Picked Up: %s\n",
                   baggageInventory[i].bagID,
                   baggageInventory[i].ownerName,
                   baggageInventory[i].flightNumber,
                   baggageInventory[i].isPickedUp ? "Yes" : "No");
        }
    }
    narrative("The baggage inventory has been displayed.");
}

void pickUpBaggage() {
    int bagID;
    printf("Enter Bag ID to pick up: ");
    scanf("%d", &bagID);
    
    if (bagID > 0 && bagID <= MAX_BAGS && baggageInventory[bagID - 1].isPickedUp == 0) {
        baggageInventory[bagID - 1].isPickedUp = 1;
        narrative("The bag has been successfully picked up.");
    } else {
        narrative("The bag is either already picked up or does not exist.");
    }
}

void simulateBaggageHandling() {
    int choice;
    
    while (1) {
        printf("\n=== Baggage Handling System ===\n");
        printf("1. Check In Baggage\n");
        printf("2. List Baggage\n");
        printf("3. Pick Up Baggage\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                checkInBaggage();
                break;
            case 2:
                listBaggage();
                break;
            case 3:
                pickUpBaggage();
                break;
            case 4:
                narrative("The baggage handling system is being shut down.");
                exit(0);
            default:
                narrative("You have made an incorrect selection.");
                break;
        }
    }
}