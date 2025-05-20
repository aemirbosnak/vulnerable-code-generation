//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define MAX_TIME 10

// Struct to represent a bag
typedef struct {
    int id;
    int destination;
    int status;
} Bag;

// Function to initialize the bags
void init_bags(Bag bags[]) {
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].id = i + 1;
        bags[i].destination = rand() % 10 + 1;
        bags[i].status = 0;
    }
}

// Function to print the bags
void print_bags(Bag bags[]) {
    for (int i = 0; i < NUM_BAGS; i++) {
        printf("%d -> %d (%d)\n", bags[i].id, bags[i].destination, bags[i].status);
    }
}

// Function to sort the bags by destination
void sort_bags(Bag bags[]) {
    for (int i = 0; i < NUM_BAGS - 1; i++) {
        for (int j = i + 1; j < NUM_BAGS; j++) {
            if (bags[i].destination > bags[j].destination) {
                Bag temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }
}

// Function to simulate the baggage handling system
void baggage_handling_system(Bag bags[]) {
    srand(time(NULL));
    init_bags(bags);
    printf("Initial bag positions:\n");
    print_bags(bags);

    int num_moves = 0;
    while (num_moves < MAX_TIME) {
        sort_bags(bags);
        for (int i = 0; i < NUM_BAGS; i++) {
            if (bags[i].status == 0) {
                int j;
                for (j = i + 1; j < NUM_BAGS && bags[j].destination == bags[i].destination; j++) {
                    if (bags[j].status == 0) {
                        bags[i].status = 1;
                        bags[j].status = 1;
                        printf("%d and %d are now being loaded together.\n", bags[i].id, bags[j].id);
                        break;
                    }
                }
                if (j == NUM_BAGS || bags[j].destination!= bags[i].destination) {
                    bags[i].status = 1;
                    printf("%d is being loaded.\n", bags[i].id);
                }
            }
        }
        num_moves++;
        printf("\n");
        print_bags(bags);
    }

    printf("\nSimulation complete.\n");
}

int main() {
    baggage_handling_system(NULL);
    return 0;
}