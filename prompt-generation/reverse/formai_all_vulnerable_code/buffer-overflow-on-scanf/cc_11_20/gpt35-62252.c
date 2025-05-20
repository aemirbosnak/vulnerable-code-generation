//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>

// Define the number of floors in the building
#define NUM_FLOORS 10

// Define the number of elevators in the building
#define NUM_ELEVATORS 3

// Initialize each floor as having no requests
int floor_requests[NUM_FLOORS] = {0};

// Define the elevator struct
struct elevator {
    int current_floor;      // the current floor the elevator is on
    char direction;         // the direction the elevator is moving (up or down)
    int destination_floor;  // the floor the elevator is currently traveling to
    int num_passengers;     // the number of passengers on the elevator
};

// Initialize the elevators
struct elevator elevators[NUM_ELEVATORS] = {
    {0, 'u', -1, 0},
    {0, 'u', -1, 0},
    {0, 'u', -1, 0}
};


int main() {
    int i, j;
    
    // Display welcome message
    printf("Welcome to the elevator simulation program!\n\n");

    // Loop continuously until program is terminated by user
    while (1) {

        // Display information about the elevators
        printf("Elevator Status:\n");
        for (i = 0; i < NUM_ELEVATORS; i++) {
            printf("Elevator %d - Floor:%d, Direction:%c, Passengers:%d\n",
                   i+1, elevators[i].current_floor, elevators[i].direction, elevators[i].num_passengers);
        }
        printf("\n");

        // Get user input for elevator requests
        printf("Please enter the floor number for each elevator request (0 to exit):\n");
        for (i = 0; i < NUM_FLOORS; i++) {
            printf("Floor %d: ", i+1);
            scanf("%d", &floor_requests[i]);
            if (floor_requests[i] == 0) {
                printf("Exiting program...\n");
                return 0;
            }
        }

        // Loop through each elevator
        for (i = 0; i < NUM_ELEVATORS; i++) {

            // If the elevator is not currently moving, choose a new floor to travel to
            if (elevators[i].destination_floor == -1) {

                // Choose the closest floor with pending requests
                int closest_floor = -1;
                int closest_distance = NUM_FLOORS + 1;
                for (j = 0; j < NUM_FLOORS; j++) {
                    int distance = abs(j - elevators[i].current_floor);
                    if (floor_requests[j] && distance < closest_distance) {
                        closest_floor = j;
                        closest_distance = distance;
                    }
                }

                // Set the elevator's destination floor and direction
                elevators[i].destination_floor = closest_floor;
                if (elevators[i].destination_floor > elevators[i].current_floor) {
                    elevators[i].direction = 'u';
                } else {
                    elevators[i].direction = 'd';
                }
            }

            // Move the elevator
            if (elevators[i].destination_floor > elevators[i].current_floor) {
                elevators[i].current_floor++;
            } else if (elevators[i].destination_floor < elevators[i].current_floor) {
                elevators[i].current_floor--;
            }

            // Check if we've arrived at the destination floor
            if (elevators[i].destination_floor == elevators[i].current_floor) {

                // Unload passengers
                if (elevators[i].num_passengers > 0) {
                    printf("Passengers exiting elevator %d on floor %d\n", i+1, elevators[i].current_floor);
                }
                elevators[i].num_passengers = 0;

                // Load passengers
                if (floor_requests[elevators[i].destination_floor-1] > 0) {
                    printf("Passengers entering elevator %d on floor %d\n", i+1, elevators[i].current_floor);
                }
                elevators[i].num_passengers = floor_requests[elevators[i].destination_floor-1];

                // Clear the floor's request
                floor_requests[elevators[i].destination_floor-1] = 0;

                // Set the elevator's destination to -1 since it has no pending requests at the moment
                elevators[i].destination_floor = -1;
            }
        }
    }

    return 0;
}