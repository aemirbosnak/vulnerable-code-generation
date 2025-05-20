//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20
#define MAX_ROADS 3

// Function to pause the simulation
void wait(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {}
}

// Function to randomly generate cars on the roads
void generate_cars(int roads[][MAX_CARS], int num_cars[]) {
    int i, j;
    for(i = 0; i < MAX_ROADS; i++) {
        num_cars[i] = rand() % (MAX_CARS + 1);
        for(j = 0; j < num_cars[i]; j++) {
            roads[i][j] = rand() % 2;
        }
    }
}

// Function to print the current traffic flow
void print_traffic(int roads[][MAX_CARS], int num_cars[]) {
    int i, j;
    for(i = 0; i < MAX_ROADS; i++) {
        printf("Road %d: [", i);
        for(j = 0; j < num_cars[i]; j++) {
            printf("%d ", roads[i][j]);
        }
        printf("]\n");
    }
}

// Function to move the cars on the roads
void move_cars(int roads[][MAX_CARS], int num_cars[]) {
    int i, j;
    for(i = 0; i < MAX_ROADS; i++) {
        for(j = 0; j < num_cars[i]; j++) {
            if(j == 0 && roads[i][j] == 0) {
                // Car is at the beginning of the road and there is no car in front of it
                roads[i][j] = 1; // Move the car
            } else if(j > 0 && roads[i][j] == 0 && roads[i][j-1] == 1) {
                // Car is not at the beginning of the road and there is a car in front of it
                roads[i][j] = 1; // Move the car
                roads[i][j-1] = 0; // Remove the car from the previous position
            }
        }
    }
}

int main() {
    int roads[MAX_ROADS][MAX_CARS] = {{0}}; // Initialize all elements to 0
    int num_cars[MAX_ROADS] = {0}; // Initialize all elements to 0
    int cycle = 0;

    srand(time(NULL)); // Seed the random number generator with the current time

    while(cycle < 100) { // Run the simulation for 100 cycles
        system("clear"); // Clear the console
        printf("Cycle %d\n========\n", cycle);
        generate_cars(roads, num_cars);
        print_traffic(roads, num_cars);
        move_cars(roads, num_cars);
        wait(1); // Pause the simulation for 1 second
        cycle++;
    }

    return 0;
}