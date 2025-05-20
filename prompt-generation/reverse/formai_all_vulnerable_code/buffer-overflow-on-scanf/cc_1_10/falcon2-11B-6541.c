//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#define NUM_BELT_SLOTS 4
#define MAX_BAGS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int conveyor_slot;
} bag_t;

typedef struct {
    bag_t bags[MAX_BAGS];
    int num_bags;
    int front_bag;
} queue_t;

queue_t queue;

int main(int argc, char **argv) {
    // Initialize the queue
    queue.front_bag = -1;
    queue.num_bags = 0;

    // Initialize the belt slots
    int belt_slots[NUM_BELT_SLOTS] = {0};

    // Simulate bags arriving at the airport
    while (true) {
        char name[MAX_NAME_LENGTH];
        printf("Enter the name of the bag (or 'q' to quit): ");
        scanf("%s", name);

        if (strcmp(name, "q") == 0) {
            break;
        }

        // Add the bag to the queue
        bag_t new_bag;
        strncpy(new_bag.name, name, MAX_NAME_LENGTH);
        new_bag.conveyor_slot = -1;
        queue.front_bag = (queue.front_bag + 1) % MAX_BAGS;
        queue.bags[queue.front_bag] = new_bag;
        queue.num_bags++;

        // Simulate the belt slots
        for (int i = 0; i < NUM_BELT_SLOTS; i++) {
            int slot = i + 1;
            if (belt_slots[slot - 1] == -1) {
                belt_slots[slot - 1] = slot;
            }
        }
    }

    // Simulate the bags being moved to the belt slots
    for (int i = 0; i < queue.num_bags; i++) {
        bag_t bag = queue.bags[queue.front_bag];
        if (bag.conveyor_slot == -1) {
            continue;
        }
        printf("Bag %s moved to belt slot %d.\n", bag.name, bag.conveyor_slot);
    }

    // Free the memory
    for (int i = 0; i < queue.num_bags; i++) {
        free(queue.bags[i].name);
    }
    free(queue.bags);
    queue.front_bag = -1;
    queue.num_bags = 0;

    return 0;
}