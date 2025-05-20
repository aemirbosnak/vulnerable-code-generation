//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_BAGGAGE 500
#define MAX_WEIGHT 50
#define MAX_WAIT_TIME 20

int main() {
    srand(time(NULL));

    int total_bags = 0;
    int num_planes = 0;
    int plane_bags[MAX_BAGGAGE];

    printf("Welcome to the Airport Baggage Handling Simulation!\n\n");
    printf("How many planes are arriving today? ");
    scanf("%d", &num_planes);

    for (int i = 0; i < num_planes; i++) {
        int num_bags = (rand() % 50) + 1; // Random number of bags per plane
        total_bags += num_bags;

        printf("\nPlane %d is arriving with %d bags.\n", i+1, num_bags);

        for (int j = 0; j < num_bags; j++) {
            int weight = (rand() % 50) + 1; // Random weight of each bag
            plane_bags[j] = weight;
        }

        // Sort bags by weight
        for (int j = 0; j < num_bags; j++) {
            for (int k = 0; k < num_bags-1; k++) {
                if (plane_bags[k] > plane_bags[k+1]) {
                    int temp = plane_bags[k+1];
                    plane_bags[k+1] = plane_bags[k];
                    plane_bags[k] = temp;
                }
            }
        }

        printf("Bags are being loaded onto the conveyor belt.\n");
        printf("Please wait...\n");

        // Wait time simulation
        for (int j = 0; j < (rand() % MAX_WAIT_TIME) + 1; j++) {
            printf(".");
        }

        printf("\n\nAll bags have been loaded onto the conveyor belt.\n");
        printf("The conveyor belt is taking the bags to the baggage handlers.\n\n");

        // Baggage handler simulation
        for (int j = 0; j < num_bags; j++) {
            int weight = plane_bags[j];
            printf("Handling bag with weight %d kg...\n", weight);

            if (weight > MAX_WEIGHT) {
                printf("Bag is too heavy for the baggage handlers and needs to be manually loaded.\n");
                printf("Please wait while we manually load the bag.\n");

                // Manual loading time simulation
                for (int k = 0; k < (rand() % MAX_WAIT_TIME) + 1; k++) {
                    printf(".");
                }

                printf("\n\nBag has been manually loaded onto the plane.\n");
            } else {
                printf("Bag has been successfully loaded onto the plane.\n");
            }
        }

        printf("\nAll bags for plane %d have been loaded onto the plane.\n", i+1);
        printf("---------------------------------------------------------\n");
    }

    printf("\n\nAll planes have been serviced. Thank you for using our simulation.\n");
    printf("Total number of bags handled: %d\n", total_bags);

    return 0;
}