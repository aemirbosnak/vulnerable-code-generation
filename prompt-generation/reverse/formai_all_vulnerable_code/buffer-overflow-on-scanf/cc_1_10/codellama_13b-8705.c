//Code Llama-13B DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

    // Structure to represent the elevator
    typedef struct {
        int current_floor;
        int destination_floor;
        int direction;
    } Elevator;

    // Function to move the elevator to the destination floor
    void move_elevator(Elevator* elevator) {
        // Check if the elevator is moving up or down
        if (elevator->direction == 1) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }

        // Check if the elevator has reached its destination
        if (elevator->current_floor == elevator->destination_floor) {
            elevator->direction = 0;
        }
    }

    // Function to handle the user input
    void handle_input(Elevator* elevator) {
        // Get the user input
        char input[100];
        scanf("%s", input);

        // Check if the input is a valid floor number
        int floor_number = atoi(input);
        if (floor_number < 1 || floor_number > 100) {
            printf("Invalid floor number!\n");
            return;
        }

        // Check if the elevator is already on the floor
        if (elevator->current_floor == floor_number) {
            printf("Elevator is already on floor %d\n", floor_number);
            return;
        }

        // Check if the elevator is moving towards the floor
        if (elevator->direction == 1 && floor_number > elevator->current_floor || elevator->direction == -1 && floor_number < elevator->current_floor) {
            printf("Elevator is moving towards floor %d\n", floor_number);
            return;
        }

        // Set the destination floor
        elevator->destination_floor = floor_number;

        // Check if the elevator is moving up or down
        if (floor_number > elevator->current_floor) {
            elevator->direction = 1;
        } else {
            elevator->direction = -1;
        }
    }

    int main() {
        // Initialize the elevator structure
        Elevator elevator;
        elevator.current_floor = 1;
        elevator.destination_floor = 1;
        elevator.direction = 0;

        // Loop until the user exits
        while (1) {
            // Print the current status of the elevator
            printf("Current floor: %d\n", elevator.current_floor);
            printf("Destination floor: %d\n", elevator.destination_floor);
            printf("Direction: %d\n", elevator.direction);

            // Handle the user input
            handle_input(&elevator);

            // Move the elevator to the destination floor
            move_elevator(&elevator);
        }

        return 0;
    }