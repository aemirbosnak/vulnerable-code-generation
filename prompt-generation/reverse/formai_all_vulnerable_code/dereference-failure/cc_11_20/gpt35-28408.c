//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LUGGAGE 10 // Max number of luggage pieces per passenger
#define MAX_PASSENGERS 100 // Max number of passengers per simulation
#define BELT_CAPACITY 50 // Max number of luggage pieces on the belt at once

typedef struct {
    int id;
    int num_luggage;
    int *luggage_weights;
} Passenger;

typedef struct {
    Passenger passenger;
    int luggage_id;
} Belt_Luggage;

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    // Initialize passengers with random number of luggage pieces and weights
    Passenger passengers[MAX_PASSENGERS];
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        passengers[i].id = i + 1;
        passengers[i].num_luggage = rand() % MAX_LUGGAGE + 1;
        passengers[i].luggage_weights = (int *) malloc(sizeof(int) * passengers[i].num_luggage);
        for (int j = 0; j < passengers[i].num_luggage; j++) {
            passengers[i].luggage_weights[j] = rand() % 30 + 1; // random weight between 1 and 30 kg
        }
    }
    
    // Initialize belt luggage queue
    Belt_Luggage belt[BELT_CAPACITY];
    int head = 0, tail = 0;
    
    // Loop through all passengers and their luggage
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        printf("Passenger %d has %d pieces of luggage, weighing:", passengers[i].id, passengers[i].num_luggage);
        for (int j = 0; j < passengers[i].num_luggage; j++) {
            printf(" %d kg", passengers[i].luggage_weights[j]);
            if (head != (tail + 1) % BELT_CAPACITY) { // Check if there is space on the belt
                tail = (tail + 1) % BELT_CAPACITY;
                belt[tail].passenger = passengers[i];
                belt[tail].luggage_id = j;
                printf(" (loaded onto belt)");
            } else {
                printf(" (could not be loaded onto belt)");
            }
        }
        printf("\n");
    }
    
    // Simulate belt handling passengers' luggage
    printf("Starting baggage handling...\n");
    int unloaded_luggage = 0;
    int awaiting_luggage = 0;
    while (unloaded_luggage < MAX_PASSENGERS * MAX_LUGGAGE) {
        // Unload luggage from the belt
        if (awaiting_luggage > 0) {
            int luggage_unloaded = rand() % 5 + 1; // Unload 1 to 5 luggage pieces at a time
            if (luggage_unloaded > awaiting_luggage) {
                luggage_unloaded = awaiting_luggage;
            }
            head = (head + luggage_unloaded) % BELT_CAPACITY;
            awaiting_luggage -= luggage_unloaded;
            unloaded_luggage += luggage_unloaded;
            printf("%d luggage pieces unloaded from belt.\n", luggage_unloaded);
        }
        
        // Load luggage onto the belt
        int loaded_luggage = rand() % 5 + 1; // Load 1 to 5 luggage pieces at a time
        if (loaded_luggage > BELT_CAPACITY - awaiting_luggage) {
            loaded_luggage = BELT_CAPACITY - awaiting_luggage;
        }
        for (int i = 0; i < loaded_luggage; i++) {
            if (unloaded_luggage + awaiting_luggage < MAX_PASSENGERS * MAX_LUGGAGE) {
                tail = (tail + 1) % BELT_CAPACITY;
                Belt_Luggage next_luggage = belt[(head + awaiting_luggage) % BELT_CAPACITY];
                awaiting_luggage++;
                printf("Passenger %d's luggage piece %d (weighing %d kg) loaded onto belt.\n",
                       next_luggage.passenger.id, next_luggage.luggage_id + 1,
                       next_luggage.passenger.luggage_weights[next_luggage.luggage_id]);
            }
        }
    }
    printf("All luggage has been loaded onto the plane. Simulation complete!\n");
    
    // Free memory for luggage weights
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        free(passengers[i].luggage_weights);
    }
    
    return 0;
}