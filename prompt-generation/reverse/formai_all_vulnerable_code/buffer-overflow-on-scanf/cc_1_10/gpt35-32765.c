//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CAPACITY 100 // Maximum capacity of the conveyor belt

typedef struct baggage {
    int id; // Unique ID of the baggage
    int weight; // Weight of the baggage
    struct baggage *next; // Pointer to next baggage in the queue
} baggage_t;

// Global variables
baggage_t *conveyor_belt = NULL; // Pointer to the head of the conveyor belt
int current_capacity = 0; // Current capacity of the conveyor belt

// Function to generate a random integer between a min and max value
int generate_random_int(int min_value, int max_value) {
    srand(time(NULL)); // Seed the random number generator with current time
    return (rand() % (max_value - min_value + 1)) + min_value;
}

// Function to add baggage to the conveyor belt
void add_baggage() {
    if (current_capacity == MAX_CAPACITY) {
        printf("Conveyor belt is full. Cannot add more baggage.\n");
        return;
    }

    // Create a new baggage
    baggage_t *new_baggage = malloc(sizeof(baggage_t));
    new_baggage->id = generate_random_int(1, 1000);
    new_baggage->weight = generate_random_int(20, 50);
    new_baggage->next = NULL;

    // Add the new baggage to the end of the conveyor belt queue
    if (conveyor_belt == NULL) {
        conveyor_belt = new_baggage;
    } else {
        baggage_t *temp_baggage = conveyor_belt;
        while (temp_baggage->next != NULL) {
            temp_baggage = temp_baggage->next;
        }
        temp_baggage->next = new_baggage;
    }

    // Update the current capacity of the conveyor belt
    current_capacity += new_baggage->weight;

    printf("Baggage with ID %d and weight %d kg is added to the conveyor belt. Current capacity: %d kg\n", new_baggage->id, new_baggage->weight, current_capacity);
}

// Function to remove baggage from the conveyor belt
void remove_baggage() {
    if (conveyor_belt == NULL) {
        printf("Conveyor belt is empty, cannot remove baggage.\n");
        return;
    }

    // Remove the first baggage from the conveyor belt queue
    baggage_t *temp_baggage = conveyor_belt;
    conveyor_belt = conveyor_belt->next;
    current_capacity -= temp_baggage->weight;

    printf("Baggage with ID %d and weight %d kg is removed from the conveyor belt. Current capacity: %d kg\n", temp_baggage->id, temp_baggage->weight, current_capacity);

    // Free memory occupied by the removed baggage
    free(temp_baggage);
}

// Function to display the conveyor belt status
void display_status() {
    if (conveyor_belt == NULL) {
        printf("Conveyor belt is empty.\n");
        return;
    }

    printf("Conveyor belt status:\n");
    baggage_t *temp_baggage = conveyor_belt;
    while (temp_baggage != NULL) {
        printf("\tID: %d Weight: %d kg\n", temp_baggage->id, temp_baggage->weight);
        temp_baggage = temp_baggage->next;
    }
    printf("Current capacity: %d kg\n", current_capacity);
}

int main() {
    int option;

    do {
        // Display menu
        printf("\n****Airport Baggage Handling Simulation****\n");
        printf("1. Add baggage to conveyor belt.\n");
        printf("2. Remove baggage from conveyor belt.\n");
        printf("3. Display conveyor belt status.\n");
        printf("4. Exit.\n");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_baggage();
                break;
            case 2:
                remove_baggage();
                break;
            case 3:
                display_status();
                break;
            case 4:
                printf("Exiting from the program...\n");
                break;
            default:
                printf("Invalid choice. Try again...\n");
        }
    } while (option != 4);

    // Free memory occupied by remaining baggage on conveyor belt
    baggage_t *temp_baggage = conveyor_belt;
    while (temp_baggage != NULL) {
        baggage_t *temp = temp_baggage;
        temp_baggage = temp_baggage->next;
        free(temp);
    }

    return 0;
}