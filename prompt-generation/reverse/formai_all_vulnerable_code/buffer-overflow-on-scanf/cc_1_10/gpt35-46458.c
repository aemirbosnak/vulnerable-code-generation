//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGS 1000

// Define a structure for a baggage
typedef struct baggage {
    int id; // Baggage ID
    int weight; // Baggage weight in Kg
} Baggage;

// Define a structure for the conveyor belt
typedef struct conveyor_belt {
    Baggage *bags[MAX_BAGS];
    int head; // Index of the first baggage on the belt
    int tail; // Index of the next empty spot on the belt
    int size; // Number of bags currently on the belt
} Conveyor_belt;

// Function to create a new baggage
Baggage* create_baggage(int id, int weight) {
    Baggage *bag = (Baggage*)malloc(sizeof(Baggage));
    bag->id = id;
    bag->weight = weight;
    return bag;
}

// Function to create a new conveyor belt
Conveyor_belt* create_conveyor_belt() {
    Conveyor_belt *belt = (Conveyor_belt*)malloc(sizeof(Conveyor_belt));
    belt->head = 0;
    belt->tail = 0;
    belt->size = 0;
    return belt;
}

// Function to add a baggage to the conveyor belt
void add_baggage(Conveyor_belt *belt, Baggage *bag) {
    if(belt->size == MAX_BAGS) {
        printf("The conveyor belt is full, can't add any more bags!\n");
        return;
    }
    belt->bags[belt->tail] = bag;
    belt->tail = (belt->tail + 1) % MAX_BAGS;
    belt->size++;
}

// Function to remove the first baggage from the conveyor belt
void remove_first_baggage(Conveyor_belt *belt) {
    if(belt->size == 0) {
        printf("The conveyor belt is empty, nothing to remove!\n");
        return;
    }
    Baggage *bag = belt->bags[belt->head];
    belt->head = (belt->head + 1) % MAX_BAGS;
    belt->size--;
    printf("Bag with ID %d and weight %d Kg has been removed from the conveyor belt.\n", bag->id, bag->weight);
}

// Function to simulate the operation of the baggage handling system
void run_simulation() {
    int num_bags;
    printf("Enter the number of bags to process: ");
    scanf("%d", &num_bags);
    Conveyor_belt *belt = create_conveyor_belt();
    for(int i = 1; i <= num_bags; i++) {
        int id, weight;
        printf("Enter ID and weight (in Kg) of Bag %d: ", i);
        scanf("%d %d", &id, &weight);
        Baggage *bag = create_baggage(id, weight);
        add_baggage(belt, bag);
    }
    printf("Simulating the operation of the baggage handling system...\n");
    while(belt->size > 0) {
        remove_first_baggage(belt);
        usleep(1000000); // Wait for 1 second before processing the next baggage
    }
    printf("All bags have been processed successfully!\n");
}

int main() {
    printf("Welcome to the Airport Baggage Handling Simulation Program!\n");
    run_simulation();
    return 0;
}