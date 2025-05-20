//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGGAGE 10
#define MAX_NAME_LENGTH 50

typedef struct Baggage {
    int id;
    char owner[MAX_NAME_LENGTH];
    int weight; // in kg
    char status[MAX_NAME_LENGTH];
} Baggage;

void initializeBaggage(Baggage *baggage, int id, const char *owner, int weight) {
    baggage->id = id;
    strncpy(baggage->owner, owner, MAX_NAME_LENGTH);
    baggage->weight = weight;
    strcpy(baggage->status, "Checked In");
}

void printBaggageInfo(Baggage *baggage) {
    printf("Baggage ID: %d\n", baggage->id);
    printf("Owner: %s\n", baggage->owner);
    printf("Weight: %d kg\n", baggage->weight);
    printf("Status: %s\n\n", baggage->status);
}

void updateBaggageStatus(Baggage *baggage, const char *newStatus) {
    strncpy(baggage->status, newStatus, MAX_NAME_LENGTH);
}

void handleBaggage(Baggage *baggage) {
    printf("Handling baggage with ID: %d\n", baggage->id);
    updateBaggageStatus(baggage, "In Transit");
    sleep(1); // Simulate time taken to handle
    updateBaggageStatus(baggage, "Delivered");
    sleep(1); // Simulate time taken to deliver
}

int main() {
    Baggage baggageQueue[MAX_BAGGAGE];
    int currentIndex = 0;
    char owner[MAX_NAME_LENGTH];
    int weight;

    printf("Welcome to the Airport Baggage Handling System\n");

    while (currentIndex < MAX_BAGGAGE) {
        printf("Enter the owner's name (or 'exit' to finish): ");
        fgets(owner, MAX_NAME_LENGTH, stdin);
        owner[strcspn(owner, "\n")] = 0; // Remove newline character

        if (strcmp(owner, "exit") == 0) {
            break;
        }

        printf("Enter the weight of the baggage (kg): ");
        scanf("%d", &weight);
        getchar(); // Consume the remaining newline

        initializeBaggage(&baggageQueue[currentIndex], currentIndex + 1, owner, weight);
        printBaggageInfo(&baggageQueue[currentIndex]);
        currentIndex++;
    }

    printf("Starting baggage handling process...\n");

    for (int i = 0; i < currentIndex; i++) {
        handleBaggage(&baggageQueue[i]);
        printBaggageInfo(&baggageQueue[i]);
    }

    printf("Baggage handling completed successfully!\n");
    return 0;
}