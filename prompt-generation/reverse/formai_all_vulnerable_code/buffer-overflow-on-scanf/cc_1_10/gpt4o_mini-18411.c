//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGGAGE 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int weight;
    int processed;
} Baggage;

Baggage luggage[MAX_BAGGAGE];
int luggageCount = 0;

void addBaggage() {
    if (luggageCount >= MAX_BAGGAGE) {
        printf("Baggage claim area is full! Please wait for processing.\n");
        return;
    }
    
    Baggage newBag;
    printf("Enter luggage name: ");
    scanf("%s", newBag.name);
    printf("Enter luggage weight (in kg): ");
    scanf("%d", &newBag.weight);
    newBag.processed = 0;
    
    luggage[luggageCount] = newBag;
    luggageCount++;
    printf("Luggage added: %s weighing %d kg\n", newBag.name, newBag.weight);
}

void processBaggage() {
    if (luggageCount == 0) {
        printf("No baggage to process!\n");
        return;
    }

    for (int i = 0; i < luggageCount; i++) {
        if (!luggage[i].processed) {
            luggage[i].processed = 1;
            printf("Processing baggage: %s\n", luggage[i].name);
            // Simulate baggage handling time
            sleep(1);

            // Randomly simulate luggage status
            if (rand() % 2) {
                printf("Baggage %s processed successfully!\n", luggage[i].name);
            } else {
                printf("Baggage %s lost during processing!\n", luggage[i].name);
            }
            break;
        }
    }
}

void displayBaggageStatus() {
    if (luggageCount == 0) {
        printf("No baggage in the system.\n");
        return;
    }

    printf("\nCurrent Baggage Status:\n");
    for (int i = 0; i < luggageCount; i++) {
        printf("Luggage Name: %-15s Weight: %-5d Status: %s\n",
               luggage[i].name,
               luggage[i].weight,
               luggage[i].processed ? "Processed" : "Pending");
    }
    printf("\n");
}

void showMenu() {
    printf("----- Airport Baggage Handling -----\n");
    printf("1. Add Baggage\n");
    printf("2. Process Baggage\n");
    printf("3. Display Baggage Status\n");
    printf("4. Exit\n");
    printf("------------------------------------\n");
}

int main() {
    srand(time(NULL));
    int choice;

    while (1) {
        showMenu();
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
                displayBaggageStatus();
                break;
            case 4:
                printf("Exiting the program. Have a safe flight!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}