//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_CONVEYOR_SECTIONS 10
#define BAG_SIZE 5
#define CONVEYOR_SPEED 1
#define TRANSFER_DELAY 2

typedef struct {
    int id;
    int destination;
    int current_section;
    time_t arrival_time;
} Bag;

Bag bags[NUM_BAGS];
int num_bags = 0;
int num_sections = NUM_CONVEYOR_SECTIONS;

void generate_bag() {
    Bag bag;
    bag.id = num_bags++;
    bag.destination = rand() % num_sections;
    bag.current_section = 0;
    bag.arrival_time = time(NULL) + rand() % 60; // Arrives between 0 and 60 seconds from now
    bags[bag.id] = bag;
}

void print_bag_info(Bag bag) {
    printf("Bag %d is going to section %d and will arrive in %ld seconds.\n", bag.id, bag.destination, bag.arrival_time - time(NULL));
}

void transfer_bag(Bag bag) {
    if (bag.current_section == bag.destination) {
        printf("Bag %d has reached its destination.\n", bag.id);
        return;
    }

    if (bag.current_section < bag.destination) {
        bag.current_section++;
    } else {
        bag.current_section--;
    }

    printf("Bag %d is being transferred from section %d to section %d.\n", bag.id, bag.current_section - 1, bag.current_section);
}

void main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_BAGS; i++) {
        generate_bag();
    }

    while (1) {
        for (int bag_id = 0; bag_id < NUM_BAGS; bag_id++) {
            Bag bag = bags[bag_id];

            if (bag.arrival_time <= time(NULL)) {
                printf("Bag %d has arrived at section %d.\n", bag_id, bag.current_section);
                transfer_bag(bag);
            } else {
                int seconds_left = bag.arrival_time - time(NULL);
                printf("Bag %d will arrive at section %d in %d seconds.\n", bag_id, bag.current_section, seconds_left);
            }
        }

        sleep(1);
    }
}