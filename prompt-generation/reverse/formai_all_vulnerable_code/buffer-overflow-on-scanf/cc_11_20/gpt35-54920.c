//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 1000
#define MIN_CAPACITY 50

int main(){
    // Welcome message
    printf("\nWelcome to the airport baggage handling simulation!\n");

    // Input validation loop for baggage capacity
    int capacity = 0;
    while (capacity < MIN_CAPACITY || capacity > MAX_CAPACITY) {
        printf("\nEnter the baggage capacity of the airport's baggage system (from %d to %d): ", MIN_CAPACITY, MAX_CAPACITY);
        scanf("%d", &capacity);
        if (capacity < MIN_CAPACITY || capacity > MAX_CAPACITY) {
            printf("\nError: Invalid capacity entered. Please try again.\n");
        }
    }

    // Initializing data structures and variables
    int num_passengers = 0;
    int num_bags = 0;
    int bags_in_system = 0;
    int bags_processed = 0;
    int num_passengers_left = 0;

    // Main program loop
    while(1) {
        // Input validation loop for number of passengers
        while (num_passengers <= 0) {
            printf("\nEnter the number of passengers (from 1 to %d) or enter -1 to exit: ", capacity);
            scanf("%d", &num_passengers);
            if (num_passengers == -1) {
                printf("\nSimulation ended. Have a nice day!\n");
                exit(0);
            }
            if (num_passengers < 1 || num_passengers > capacity) {
                printf("\nError: Invalid number of passengers. Please try again.\n");
            }
        }

        // Input validation loop for number of bags
        while (num_bags <= 0) {
            printf("\nEnter the number of bags per passenger (from 1 to 10): ");
            scanf("%d", &num_bags);
            if (num_bags < 1 || num_bags > 10) {
                printf("\nError: Invalid number of bags. Please try again.\n");
            }
        }

        // Processing bags for each passenger
        int bags_added = 0;
        for (int i = 1; i <= num_passengers; i++) {
            for (int j = 1; j <= num_bags; j++) {
                if (bags_in_system < capacity) {
                    bags_in_system++;
                    bags_added++;
                }
                else {
                    num_passengers_left++;
                }
            }
        }
        
        bags_processed += bags_added;
        printf("\n%d bags processed. %d bags in the system. %d passengers left.\n", bags_processed, bags_in_system, num_passengers_left);

        // Resetting variables for next round
        num_passengers = 0;
        num_bags = 0;
        bags_added = 0;

        // Checking if system is full
        if (bags_in_system >= capacity) {
            printf("\nWarning: Baggage system is full. Please wait for available space.\n");
        }
    }

    return 0;
}