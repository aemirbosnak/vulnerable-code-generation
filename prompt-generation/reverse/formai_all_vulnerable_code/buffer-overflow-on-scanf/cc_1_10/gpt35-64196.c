//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define number of bags and conveyor belt capacity */
#define NUM_BAGS 50
#define CONVEYOR_BELT_CAP 10

/* Define global variables */
int conveyor_belt[CONVEYOR_BELT_CAP];
int num_bags_on_conveyor_belt = 0;
int total_num_bags_processed = 0;
int current_bag_index = 0;

/* Function to generate random bag weights */
int generate_random_weight() {
    int weight = (rand() % 50) + 1; /* Random number from 1 to 50 */
    return weight;
}

/* Function to add bag to conveyor belt */
void add_bag_to_conveyor_belt() {
    /* Check if conveyor belt is full */
    if (num_bags_on_conveyor_belt == CONVEYOR_BELT_CAP) {
        printf("Conveyor belt full. Cannot add more bags.\n");
    } else {
        /* Generate random weight for bag */
        int bag_weight = generate_random_weight();
        /* Add bag to conveyor belt */
        conveyor_belt[num_bags_on_conveyor_belt] = bag_weight;
        num_bags_on_conveyor_belt++;
        /* Print confirmation message */
        printf("Added bag with weight %d to conveyor belt.\n", bag_weight);
    }
}

/* Function to process bag on conveyor belt */
void process_bag_on_conveyor_belt() {
    /* Check if there are bags on the conveyor belt */
    if (num_bags_on_conveyor_belt == 0) {
        printf("Conveyor belt is empty. Cannot process more bags.\n");
    } else {
        /* Remove bag from conveyor belt */
        int bag_weight = conveyor_belt[current_bag_index];
        num_bags_on_conveyor_belt--;
        current_bag_index++;
        /* Print confirmation message */
        printf("Processed bag with weight %d.\n", bag_weight);
        /* Update total number of bags processed */
        total_num_bags_processed++;
    }
}

int main() {
    /* Seed RNG */
    srand(time(NULL));
    /* Define variables */
    int choice;
    /* Main loop */
    while (total_num_bags_processed < NUM_BAGS) {
        /* Print menu */
        printf("----------------------\n");
        printf("Airport Baggage Handling Simulation Menu:\n");
        printf("1. Add bag to conveyor belt\n");
        printf("2. Process bag on conveyor belt\n");
        printf("3. Exit program\n");
        printf("----------------------\n");
        /* Get user choice */
        printf("Enter your choice: ");
        scanf("%d", &choice);
        /* Process user choice */
        switch (choice) {
            case 1:
                add_bag_to_conveyor_belt();
                break;
            case 2:
                process_bag_on_conveyor_belt();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}