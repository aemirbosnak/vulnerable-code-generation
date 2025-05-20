//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Baggage Handling Simulation!\n");
    printf("You are the detective in charge of solving the mystery of the missing bag!\n");
    printf("Let us start the simulation!\n\n");

    // Random seed generator
    srand(time(NULL));

    // Initializing variables
    int num_bags = 10;
    int max_weight = 50;
    int total_weight = 0;
    int missing_bag = rand() % num_bags + 1;
    int actual_weight = 0;
    int scanned_weight = 0;
    char status;

    // Generating bags
    int i;
    for (i = 1; i <= num_bags; i++) {
        int weight = rand() % max_weight + 1;
        printf("Bag %d - Weight: %d kg\n", i, weight);
        total_weight += weight;

        if (i == missing_bag) {
            actual_weight = weight;
        }
    }

    printf("\nTotal weight of bags: %d kg\n", total_weight);
    printf("Detective, please enter the weight of the missing bag as shown on the label:\n");

    scanf("%d", &scanned_weight);

    if (scanned_weight == actual_weight) {
        status = 'F';
    } else {
        status = 'M';
    }

    printf("\nThe missing bag is: %c\n", status);

    if (status == 'M') {
        printf("The weight of the missing bag shown on the label is incorrect!\n");
        printf("Please check your calculations again!\n");
    } else {
        printf("Congratulations detective! You have solved the mystery!\n");
        printf("The weight of the missing bag matches the weight shown on the label!\n");
    }

    return 0;
}