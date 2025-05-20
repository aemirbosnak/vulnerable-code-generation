//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of bags that can be processed per hour
#define MAX_BAGS_PER_HOUR 600

// Define the maximum number of hours that the simulation can run
#define MAX_HOURS 12

// Define the maximum number of bags that can be stored in the baggage claim area
#define MAX_BAGS_IN_CLAIM_AREA 1000

// Define the probability that a bag will be lost
#define PROB_BAG_LOST 0.01

// Define the probability that a bag will be delayed
#define PROB_BAG_DELAYED 0.05

// Define the structure of a bag
typedef struct bag {
    int id;
    char *destination;
    int arrival_time;
    int departure_time;
    int lost;
    int delayed;
} bag;

// Define the structure of the baggage claim area
typedef struct baggage_claim_area {
    int num_bags;
    bag *bags[MAX_BAGS_IN_CLAIM_AREA];
} baggage_claim_area;

// Create a new bag
bag *create_bag(int id, char *destination, int arrival_time, int departure_time) {
    bag *b = malloc(sizeof(bag));
    b->id = id;
    b->destination = strdup(destination);
    b->arrival_time = arrival_time;
    b->departure_time = departure_time;
    b->lost = 0;
    b->delayed = 0;
    return b;
}

// Destroy a bag
void destroy_bag(bag *b) {
    free(b->destination);
    free(b);
}

// Create a new baggage claim area
baggage_claim_area *create_baggage_claim_area() {
    baggage_claim_area *bca = malloc(sizeof(baggage_claim_area));
    bca->num_bags = 0;
    return bca;
}

// Destroy a baggage claim area
void destroy_baggage_claim_area(baggage_claim_area *bca) {
    for (int i = 0; i < bca->num_bags; i++) {
        destroy_bag(bca->bags[i]);
    }
    free(bca);
}

// Add a bag to the baggage claim area
void add_bag_to_claim_area(baggage_claim_area *bca, bag *b) {
    bca->bags[bca->num_bags] = b;
    bca->num_bags++;
}

// Remove a bag from the baggage claim area
void remove_bag_from_claim_area(baggage_claim_area *bca, bag *b) {
    for (int i = 0; i < bca->num_bags; i++) {
        if (bca->bags[i] == b) {
            bca->bags[i] = bca->bags[bca->num_bags - 1];
            bca->num_bags--;
            break;
        }
    }
}

// Simulate the baggage handling process
void simulate(int num_bags, int num_hours) {
    // Create a baggage claim area
    baggage_claim_area *bca = create_baggage_claim_area();

    // Create a queue of bags
    bag **queue = malloc(sizeof(bag *) * num_bags);
    int head = 0;
    int tail = 0;

    // Generate random bags
    for (int i = 0; i < num_bags; i++) {
        int id = i + 1;
        char *destination = malloc(10);
        sprintf(destination, "Destination %d", id);
        int arrival_time = rand() % (num_hours * 60);  
        int departure_time = arrival_time + rand() % (num_hours * 60);
        bag *b = create_bag(id, destination, arrival_time, departure_time);

        // Determine if the bag will be lost or delayed 
        double r = (double)rand() / RAND_MAX;
        if (r < PROB_BAG_LOST) {
            b->lost = 1;
        } else if (r < PROB_BAG_DELAYED) {
            b->delayed = 1;
        }

        // Add the bag to the queue 
        queue[tail] = b;
        tail = (tail + 1) % num_bags;
    }

    // Simulate the baggage handling process for each hour
    for (int hour = 0; hour < num_hours; hour++) {
        // Process bags that have arrived this hour
        while (head != tail && queue[head]->arrival_time <= hour * 60) {
            bag *b = queue[head];
            head = (head + 1) % num_bags;

            // Add the bag to the baggage claim area
            add_bag_to_claim_area(bca, b);
        }

        // Process bags that are ready to be claimed
        for (int i = 0; i < bca->num_bags; i++) {
            bag *b = bca->bags[i];
            if (b->departure_time <= hour * 60) {
                // Remove the bag from the baggage claim area
                remove_bag_from_claim_area(bca, b);

                // Print the bag information
                printf("Bag %d: %s", b->id, b->destination);
                if (b->lost) {
                    printf(" (lost)");
                } else if (b->delayed) {
                    printf(" (delayed)");
                }
                printf("\n");

                // Destroy the bag
                destroy_bag(b);
            }
        }
    }

    // Destroy the baggage claim area
    destroy_baggage_claim_area(bca);

    // Free the queue
    free(queue);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Get the number of bags and hours from the user
    int num_bags;
    int num_hours;
    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);
    printf("Enter the number of hours: ");
    scanf("%d", &num_hours);

    // Simulate the baggage handling process
    simulate(num_bags, num_hours);

    return 0;
}