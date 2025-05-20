//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Elevator car structure definition
typedef struct {
    int current_floor;    // Current floor
    int destination_floor; // Destination floor
    char direction;       // Direction (up or down)
} ElevatorCar;

// Global variable to represent the elevator car
ElevatorCar my_elevator = {0, 0, 'u'};

// Function to move the elevator to a new floor
void move_elevator(int new_floor) {
    if (my_elevator.destination_floor == new_floor) {
        my_elevator.direction = (my_elevator.direction == 'u') ? 'd' : 'u';
        printf("Elevator reached floor %d.\n", new_floor);
    } else {
        printf("Elevator is currently on floor %d and heading to floor %d.\n", my_elevator.current_floor, my_elevator.destination_floor);
    }

    my_elevator.current_floor = new_floor;
}

// Function to display the current status of the elevator
void display_status() {
    printf("Current floor: %d\n", my_elevator.current_floor);
    printf("Destination floor: %d\n", my_elevator.destination_floor);
    printf("Direction: %c\n", my_elevator.direction);
}

int main() {
    int floor;

    // Infinite loop that simulates the elevator moving up and down between floors
    while (1) {
        display_status();
        scanf("%d", &floor);

        if (floor >= 0 && floor <= 10) { // Assuming we have 11 floors
            my_elevator.destination_floor = floor;
        } else {
            printf("Invalid floor number.\n");
        }

        move_elevator(my_elevator.current_floor);
        my_elevator.current_floor++;

        if (my_elevator.current_floor > 10) {
            my_elevator.current_floor = 0;
        }
    }

    return 0;
}