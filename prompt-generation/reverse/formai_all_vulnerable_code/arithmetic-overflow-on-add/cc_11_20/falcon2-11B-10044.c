//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int floor;
    int direction;
    int speed;
} ElevatorState;

ElevatorState elevator;

int main() {
    // Initialize elevator state
    elevator.floor = 0;
    elevator.direction = 1; // Up
    elevator.speed = 1; // Slow
    
    // Simulate elevator movement
    while (true) {
        // Move elevator
        switch (elevator.direction) {
            case 1:
                elevator.floor++;
                break;
            case -1:
                elevator.floor--;
                break;
        }
        
        // Change direction after reaching top or bottom floor
        if (elevator.floor == 0) {
            elevator.direction = -1;
        } else if (elevator.floor == 7) {
            elevator.direction = 1;
        }
        
        // Change speed after reaching destination
        if (elevator.floor == 0 && elevator.direction == -1) {
            elevator.speed = 2;
        } else if (elevator.floor == 7 && elevator.direction == 1) {
            elevator.speed = 2;
        }
        
        // Print elevator state
        printf("Floor: %d, Direction: %d, Speed: %d\n", elevator.floor, elevator.direction, elevator.speed);
        
        // Sleep for a random amount of time
        clock_t start = clock();
        while (clock() < start + rand() % (CLOCKS_PER_SEC * 5))
            ;
    }
}