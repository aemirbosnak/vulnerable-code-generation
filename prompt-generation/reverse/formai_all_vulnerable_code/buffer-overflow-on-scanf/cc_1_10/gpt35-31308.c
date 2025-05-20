//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seeding rand()

    // Initializing variables
    int no_of_bags = 0;
    int no_of_workers = 0;
    int capacity = 0;
    int total_bags_screened = 0;
    int total_bags_loaded = 0;

    printf("----------Airport Baggage Handling Simulation----------\n\n");

    // Taking input from user
    printf("Enter the total number of bags to be screened: ");
    scanf("%d", &no_of_bags);

    printf("Enter the number of workers available for the screening process: ");
    scanf("%d", &no_of_workers);

    printf("Enter the screening capacity per worker: ");
    scanf("%d", &capacity);

    // Initializing arrays for screening and loading areas
    int screening_area[no_of_workers][capacity];
    int loading_area[no_of_workers][capacity];

    // Screening process
    printf("\nStarting the screening process...\n\n");
    for (int i = 0; i < no_of_bags; i++) {
        // Determining the worker who will screen the bag
        int worker_index = i % no_of_workers;

        // Checking if the worker's screening machine is full or not
        int flag = 0;
        for (int j = 0; j < capacity; j++) {
            if (screening_area[worker_index][j] == 0) {
                // Screening the bag
                screening_area[worker_index][j] = 1;
                total_bags_screened++;
                flag = 1;
                break;
            }
        }

        if (!flag) {
            // If the worker's screening machine is full, bag is discarded
            printf("Bag %d discarded due to capacity constraints in screening machine of worker %d.\n", i+1, worker_index+1);
        }
    }

    // Loading process
    printf("\nStarting the loading process...\n\n");
    for (int i = 0; i < no_of_workers; i++) {
        for (int j = 0; j < capacity; j++) {
            // Checking if the worker's loading machine is empty or not
            if (loading_area[i][j] == 0) {
                // Loading the bag onto the plane
                int bag_index = i * capacity + j + 1;
                loading_area[i][j] = 1;
                total_bags_loaded++;

                printf("Bag %d loaded onto the plane from worker %d's loading machine.\n", bag_index, i+1);

                // Randomly generating delay for loading of bag
                int delay = rand() % 5;
                printf("Delay for bag %d: %d minutes.\n", bag_index, delay+1);

                // Removing bag from screening area
                screening_area[i][j] = 0;
            }
        }
    }

    // Displaying simulation results
    printf("\n----------Simulation Results----------\n\n");
    printf("Total bags screened: %d\n", total_bags_screened);
    printf("Total bags loaded: %d\n", total_bags_loaded);
    printf("Percentage of bags loaded: %.2f%\n", (float) total_bags_loaded / no_of_bags * 100);

    return 0;
}