//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Define the elevator state
enum ElevatorState {
    UP,
    DOWN,
    HALT
};

// Define the elevator position
struct Elevator {
    int floor;
    enum ElevatorState state;
};

// Function to move the elevator up
void moveUp(struct Elevator* elevator) {
    if (elevator->state == HALT) {
        elevator->state = UP;
        elevator->floor++;
    }
}

// Function to move the elevator down
void moveDown(struct Elevator* elevator) {
    if (elevator->state == UP) {
        elevator->state = DOWN;
        elevator->floor--;
    }
}

// Function to halt the elevator
void halt(struct Elevator* elevator) {
    elevator->state = HALT;
}

// Function to print the elevator state
void printState(struct Elevator elevator) {
    printf("Elevator state: %s\n", elevator.state == UP? "UP" : (elevator.state == DOWN? "DOWN" : "HALT"));
}

int main() {
    struct Elevator elevator;
    elevator.floor = 0;
    elevator.state = UP;

    printf("Elevator state: %s\n", elevator.state == UP? "UP" : (elevator.state == DOWN? "DOWN" : "HALT"));

    while (1) {
        printf("Enter 1 to move up, 2 to move down, 3 to halt, or 4 to exit:\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveUp(&elevator);
                break;
            case 2:
                moveDown(&elevator);
                break;
            case 3:
                halt(&elevator);
                break;
            case 4:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Elevator state: %s\n", elevator.state == UP? "UP" : (elevator.state == DOWN? "DOWN" : "HALT"));
    }

    return 0;
}