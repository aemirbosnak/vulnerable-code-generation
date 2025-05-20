//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20
#define MAX_SPEED 60

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Initialize the road with no cars
    int road[MAX_SPEED] = { 0 };

    // Get user input for number of cars
    int num_cars;
    printf("Enter number of cars (up to %d): ", MAX_CARS);
    scanf("%d", &num_cars);

    // Initialize cars randomly on the road
    for (int i = 0; i < num_cars; i++) {
        int pos = rand() % MAX_SPEED;
        while (road[pos] != 0) {
            pos = (pos + 1) % MAX_SPEED;
        }
        road[pos] = i + 1; // Car ID is index + 1
    }

    // Display initial road state
    printf("Initial road state:\n");
    for (int i = 0; i < MAX_SPEED; i++) {
        if (road[i] != 0) {
            printf("%d", road[i]);
        } else {
            printf("-");
        }
    }
    printf("\n");

    // Start the simulation
    printf("Starting simulation...\n");
    int time = 0;
    while (1) { // Run forever
        printf("Time %d: ", time);

        // Move each car forward if possible
        for (int i = 0; i < MAX_SPEED; i++) {
            if (road[i] != 0) {
                int new_pos = (i + 1) % MAX_SPEED;
                if (road[new_pos] == 0) {
                    road[new_pos] = road[i];
                    road[i] = 0;
                }
            }
        }

        // Display current road state
        for (int i = 0; i < MAX_SPEED; i++) {
            if (road[i] != 0) {
                printf("%d", road[i]);
            } else {
                printf("-");
            }
        }
        printf("\n");

        // Check if all cars have reached the end
        int all_done = 1;
        for (int i = MAX_SPEED - num_cars; i < MAX_SPEED; i++) {
            if (road[i] == 0) {
                all_done = 0;
            }
        }
        if (all_done) {
            printf("All cars have reached the end!\n");
            break;
        }

        // Increment time and wait before next iteration
        time++;
        printf("\n");
        system("PAUSE");
    }

    return 0;
}