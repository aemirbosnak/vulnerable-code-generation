//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100
#define BAG_ID_LENGTH 16

typedef struct {
    char id[BAG_ID_LENGTH];
    char ownerName[50];
    char status[20]; // "Checked In", "In Transit", "Retrieved"
} Baggage;

Baggage baggageSystem[MAX_BAGS];
int baggageCount = 0;

void checkInBaggage() {
    if (baggageCount >= MAX_BAGS) {
        printf("Baggage handling system is full.\n");
        return;
    }

    Baggage newBaggage;

    printf("Enter baggage ID: ");
    scanf("%s", newBaggage.id);
    printf("Enter owner's name: ");
    scanf(" %[^\n]", newBaggage.ownerName);
    strcpy(newBaggage.status, "Checked In");

    baggageSystem[baggageCount++] = newBaggage;
    printf("Baggage %s checked in successfully.\n", newBaggage.id);
}

void retrieveBaggage() {
    char id[BAG_ID_LENGTH];

    printf("Enter baggage ID to retrieve: ");
    scanf("%s", id);

    for (int i = 0; i < baggageCount; i++) {
        if (strcmp(baggageSystem[i].id, id) == 0) {
            if (strcmp(baggageSystem[i].status, "Retrieved") == 0) {
                printf("Baggage %s already retrieved.\n", id);
                return;
            }
            strcpy(baggageSystem[i].status, "Retrieved");
            printf("Baggage %s retrieved successfully.\n", id);
            return;
        }
    }

    printf("Baggage with ID %s not found.\n", id);
}

void viewBaggageStatus() {
    printf("\n--- Baggage Status ---\n");
    for (int i = 0; i < baggageCount; i++) {
        printf("ID: %s | Owner: %s | Status: %s\n", 
            baggageSystem[i].id, 
            baggageSystem[i].ownerName, 
            baggageSystem[i].status);
    }
    printf("----------------------\n");
}

void displayMenu() {
    printf("\n--- Airport Baggage Handling System ---\n");
    printf("1. Check in baggage\n");
    printf("2. Retrieve baggage\n");
    printf("3. View baggage status\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkInBaggage();
                break;
            case 2:
                retrieveBaggage();
                break;
            case 3:
                viewBaggageStatus();
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}