//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGS 10
#define MAX_NAME_LENGTH 50

// Structure to represent a bag
typedef struct {
    int id;
    char owner[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];
} Baggage;

typedef struct {
    Baggage bags[MAX_BAGS];
    int front, rear;
} ConveyorBelt;

// Function declarations
void initializeBelt(ConveyorBelt *belt);
int isBeltFull(ConveyorBelt *belt);
int isBeltEmpty(ConveyorBelt *belt);
void addBaggage(ConveyorBelt *belt, Baggage bag);
Baggage removeBaggage(ConveyorBelt *belt);
void processBaggage(ConveyorBelt *belt);
void displayBaggage(Baggage bag);

int main() {
    ConveyorBelt conveyor;
    initializeBelt(&conveyor);

    int choice;
    Baggage bag;
    
    while (1) {
        printf("\nAirport Baggage Handling System\n");
        printf("1. Check-in Baggage\n");
        printf("2. Process Baggage\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To capture the newline character
        
        switch (choice) {
            case 1:
                if (isBeltFull(&conveyor)) {
                    printf("Conveyor belt is full! Cannot check in more baggage.\n");
                    break;
                }
                bag.id = conveyor.rear + 1; // Simple ID increment
                printf("Enter owner's name: ");
                fgets(bag.owner, MAX_NAME_LENGTH, stdin);
                bag.owner[strcspn(bag.owner, "\n")] = 0; // Remove newline character

                printf("Enter destination: ");
                fgets(bag.destination, MAX_NAME_LENGTH, stdin);
                bag.destination[strcspn(bag.destination, "\n")] = 0;

                addBaggage(&conveyor, bag);
                printf("Bag checked in successfully!\n");
                break;

            case 2:
                if (isBeltEmpty(&conveyor)) {
                    printf("No baggage to process.\n");
                } else {
                    processBaggage(&conveyor);
                }
                break;

            case 3:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}

// Initialize the conveyor belt
void initializeBelt(ConveyorBelt *belt) {
    belt->front = 0;
    belt->rear = -1;
}

// Check if the belt is full
int isBeltFull(ConveyorBelt *belt) {
    return (belt->rear == MAX_BAGS - 1);
}

// Check if the belt is empty
int isBeltEmpty(ConveyorBelt *belt) {
    return (belt->front > belt->rear);
}

// Add a bag to the conveyor belt
void addBaggage(ConveyorBelt *belt, Baggage bag) {
    belt->bags[++belt->rear] = bag;
}

// Remove a bag from the conveyor belt
Baggage removeBaggage(ConveyorBelt *belt) {
    return belt->bags[belt->front++];
}

// Process baggage on the conveyor belt
void processBaggage(ConveyorBelt *belt) {
    Baggage bag = removeBaggage(belt);
    printf("Processing bag ID: %d\n", bag.id);
    printf("Owner: %s\n", bag.owner);
    printf("Destination: %s\n", bag.destination);
    printf("Bag has been delivered to carousel.\n");
    sleep(2); // Simulating time taken to process
}

// Display bag information
void displayBaggage(Baggage bag) {
    printf("Bag ID: %d\n", bag.id);
    printf("Owner: %s\n", bag.owner);
    printf("Destination: %s\n", bag.destination);
}