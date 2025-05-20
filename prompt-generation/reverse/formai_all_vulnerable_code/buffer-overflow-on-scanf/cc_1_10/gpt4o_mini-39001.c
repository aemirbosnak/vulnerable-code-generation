//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BAGGAGE 10
#define MAX_NAME_LENGTH 30

typedef struct {
    int id;
    char owner[MAX_NAME_LENGTH];
    int weight; // in kilograms
    int isProcessed;
} Baggage;

typedef struct {
    Baggage bags[MAX_BAGGAGE];
    int count;
} BaggageHandler;

void initBaggageHandler(BaggageHandler* handler) {
    handler->count = 0;
}

void generateBaggage(BaggageHandler* handler) {
    if (handler->count >= MAX_BAGGAGE) {
        printf("Baggage area is full, cannot add more.\n");
        return;
    }

    Baggage newBag;
    newBag.id = handler->count + 1;
    snprintf(newBag.owner, MAX_NAME_LENGTH, "Survivor%d", newBag.id);
    newBag.weight = rand() % 30 + 5; // Random weight between 5kg and 35kg
    newBag.isProcessed = 0; // Not processed

    handler->bags[handler->count] = newBag;
    handler->count++;
    printf("New baggage added: ID=%d Owner=%s Weight=%d kg\n", newBag.id, newBag.owner, newBag.weight);
}

void processBaggage(BaggageHandler* handler) {
    for (int i = 0; i < handler->count; i++) {
        if (!handler->bags[i].isProcessed) {
            // Simulate processing time with random sleep
            printf("Processing baggage ID=%d Owner=%s...\n", handler->bags[i].id, handler->bags[i].owner);
            handler->bags[i].isProcessed = 1; // Mark as processed
            return;
        }
    }
    printf("All baggage processed!\n");
}

void displayProcessedBaggage(BaggageHandler* handler) {
    printf("\n=== Processed Baggage ===\n");
    for (int i = 0; i < handler->count; i++) {
        if (handler->bags[i].isProcessed) {
            printf("ID=%d Owner=%s Weight=%d kg\n", handler->bags[i].id, handler->bags[i].owner, handler->bags[i].weight);
        }
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    BaggageHandler handler;
    initBaggageHandler(&handler);

    // Simulating a post-apocalyptic airport baggage handling
    printf("Welcome to the Post-Apocalyptic Airport Baggage Handling System!\n");

    char command;
    do {
        printf("\nEnter 'a' to add baggage, 'p' to process baggage, 'd' to display processed baggage, 'q' to quit: ");
        scanf(" %c", &command);

        switch (command) {
            case 'a':
                generateBaggage(&handler);
                break;
            case 'p':
                processBaggage(&handler);
                break;
            case 'd':
                displayProcessedBaggage(&handler);
                break;
            case 'q':
                printf("Exiting the system. Stay safe, survivor!\n");
                break;
            default:
                printf("Invalid command. Please try again.\n");
        }
    } while (command != 'q');

    return 0;
}