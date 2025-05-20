//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void delay(int seconds) {
    clock_t end_time = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_time) { }
}

int main() {
    // Simulation parameters
    int num_passengers = 50;
    int num_bags_max = 2;
    int time_per_bag = 1; // seconds
    int time_per_passenger = 5; // seconds
    int time_to_pickup = 20; // seconds

    // Initialize counters
    int total_bags = 0;
    int total_time = 0;

    // Initialize random seed
    srand(time(NULL));

    // Print introduction
    printf("Welcome to the medieval airport baggage handling simulation!\n");
    printf("There are %d passengers with up to %d bags each.\n", num_passengers, num_bags_max);
    printf("Each bag takes %d seconds to process and each passenger takes %d seconds to pass through security.\n", time_per_bag, time_per_passenger);
    printf("The bags will be sent to the baggage claim area %d seconds after the last passenger passes through security.\n", time_to_pickup);
    printf("Let's begin...\n\n");

    // Process passengers
    for (int i = 1; i <= num_passengers; i++) {
        int num_bags = rand() % (num_bags_max + 1);
        printf("Passenger %d has %d bags.\n", i, num_bags);
        delay(time_per_passenger);
        for (int j = 1; j <= num_bags; j++) {
            printf("Bag %d of Passenger %d is being processed...\n", j, i);
            delay(time_per_bag);
            total_bags++;
        }
        printf("Passenger %d has completed the security process.\n", i);
    }

    // Wait for bags to arrive at baggage claim
    printf("\nAll passengers have passed through security. Waiting for bags to arrive at baggage claim...\n");
    delay(time_to_pickup);

    // Print summary
    printf("\n\nSimulation complete.\n");
    printf("Total bags processed: %d\n", total_bags);
    printf("Total time elapsed: %d seconds\n", total_bags * time_per_bag + num_passengers * time_per_passenger + time_to_pickup);

    return 0;
}