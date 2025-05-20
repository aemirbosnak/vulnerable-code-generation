//Code Llama-13B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: configurable
/*
 * Airport Baggage Handling Simulation
 *
 * This program simulates the process of baggage handling at an airport.
 * It allows the user to configure the number of baggage handlers, the
 * number of bags to be handled, and the time it takes to handle each bag.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to handle a bag
void handle_bag(int bag_id, int handler_id) {
    printf("Handling bag %d with handler %d\n", bag_id, handler_id);
    sleep(1); // Simulate handling time
}

int main() {
    // Ask user for configuration
    int num_handlers, num_bags, handler_time;
    printf("Enter number of baggage handlers: ");
    scanf("%d", &num_handlers);
    printf("Enter number of bags: ");
    scanf("%d", &num_bags);
    printf("Enter time it takes to handle a bag: ");
    scanf("%d", &handler_time);

    // Initialize random seed
    srand(time(NULL));

    // Create array of bag IDs
    int bag_ids[num_bags];
    for (int i = 0; i < num_bags; i++) {
        bag_ids[i] = i;
    }

    // Shuffle bag IDs
    for (int i = 0; i < num_bags; i++) {
        int j = rand() % num_bags;
        int temp = bag_ids[i];
        bag_ids[i] = bag_ids[j];
        bag_ids[j] = temp;
    }

    // Handle bags
    for (int i = 0; i < num_bags; i++) {
        int bag_id = bag_ids[i];
        int handler_id = rand() % num_handlers;
        handle_bag(bag_id, handler_id);
        sleep(handler_time);
    }

    return 0;
}