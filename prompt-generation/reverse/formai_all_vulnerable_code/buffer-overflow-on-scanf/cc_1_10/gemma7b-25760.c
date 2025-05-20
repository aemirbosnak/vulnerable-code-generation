//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

// Define the number of floors in the elevator
#define NUM_FLOORS 5

// Define the maximum number of passengers in the elevator
#define MAX_PASSENGERS 10

// Define the elevator floor structure
typedef struct Floor {
    int current_passengers;
    int next_floor;
} Floor;

// Create an array of floors
Floor floors[NUM_FLOORS] = {
    {0, 1},
    {0, 2},
    {0, 3},
    {0, 4},
    {0, 0}
};

// Function to simulate the elevator movement
void simulate_elevator(int current_floor, int destination_floor) {
    // Calculate the direction of travel
    int direction = (destination_floor - current_floor) > 0 ? 1 : -1;

    // Move the elevator to the destination floor
    for (int i = current_floor; i != destination_floor; i += direction) {
        floors[i].current_passengers++;
        printf("The elevator is on floor %d.\n", i);
        sleep(1);
    }

    // Arrive at the destination floor
    floors[destination_floor].current_passengers--;
    printf("The elevator has arrived on floor %d.\n", destination_floor);
}

int main() {
    // Get the current floor and destination floor from the player
    int current_floor = 0;
    int destination_floor = 0;
    printf("Enter your current floor: ");
    scanf("%d", &current_floor);

    printf("Enter your destination floor: ");
    scanf("%d", &destination_floor);

    // Simulate the elevator movement
    simulate_elevator(current_floor, destination_floor);

    return 0;
}