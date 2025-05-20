//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a structure to represent the elevator
    struct elevator {
        int current_floor;
        int destination_floor;
        int passengers;
        int max_passengers;
    };

    // Create a structure to represent the building
    struct building {
        int floors;
        struct elevator elevators[5];
    };

    // Initialize the building
    struct building building = {
        10,
        {
            {1, 10, 0, 5},
            {2, 8, 0, 4},
            {3, 6, 0, 3},
            {4, 4, 0, 2},
            {5, 2, 0, 1}
        }
    };

    // Print the initial state of the building
    printf("Initial state of the building:\n");
    for (int i = 0; i < building.floors; i++) {
        printf("Elevator %d: Current floor: %d, Destination floor: %d, Passengers: %d, Max passengers: %d\n", i + 1, building.elevators[i].current_floor, building.elevators[i].destination_floor, building.elevators[i].passengers, building.elevators[i].max_passengers);
    }

    // Simulate the elevator movements
    for (int i = 0; i < 100; i++) {
        // Randomly select an elevator
        int elevator = rand() % building.floors;

        // Randomly select a destination floor
        int destination_floor = rand() % building.floors;

        // Calculate the number of passengers
        int passengers = rand() % building.elevators[elevator].max_passengers;

        // Check if the destination floor is within the elevator's range
        if (building.elevators[elevator].destination_floor!= destination_floor) {
            building.elevators[elevator].destination_floor = destination_floor;
        }

        // Check if the elevator is at the destination floor
        if (building.elevators[elevator].current_floor == building.elevators[elevator].destination_floor) {
            // If there are no passengers, move the elevator to the next floor
            if (building.elevators[elevator].passengers == 0) {
                building.elevators[elevator].current_floor++;
            } else {
                // If there are passengers, wait for them to get off before moving to the next floor
                while (building.elevators[elevator].passengers > 0) {
                    printf("Passenger %d exits the elevator.\n", building.elevators[elevator].passengers - 1);
                    building.elevators[elevator].passengers--;
                }
                building.elevators[elevator].current_floor++;
            }
        }

        // Print the updated state of the building
        printf("After %d movements:\n", i + 1);
        for (int j = 0; j < building.floors; j++) {
            printf("Elevator %d: Current floor: %d, Destination floor: %d, Passengers: %d, Max passengers: %d\n", j + 1, building.elevators[j].current_floor, building.elevators[j].destination_floor, building.elevators[j].passengers, building.elevators[j].max_passengers);
        }
    }

    // Free the memory
    for (int j = 0; j < building.floors; j++) {
        free(building.elevators[j].passengers);
    }

    return 0;
}