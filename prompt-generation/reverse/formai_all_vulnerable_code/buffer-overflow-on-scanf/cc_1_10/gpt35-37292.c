//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

typedef enum {
    IDLE,
    UP,
    DOWN
} State;

typedef struct {
    int floor;
    State state;
} Elevator;

int main() {
    Elevator elevator = {1, IDLE};
    int request;
    int floorCount[MAX_FLOORS] = {0};

    printf("Welcome to the elevator simulation program!\n\n");
    while (1) {
        printf("Elevator is currently on floor %d\n", elevator.floor);

        // Check if there is a floor that needs to be serviced
        if (floorCount[elevator.floor - 1] > 0) {
            printf("Opening doors...\n");
            printf("Closing doors...\n");
            floorCount[elevator.floor - 1]--;
        }

        printf("Enter floor number to request the elevator (1 - 10) (0 to quit): ");
        scanf("%d", &request);

        // Check if the user wants to quit the program
        if (request == 0) {
            break;
        }
        // Check if requested floor is valid
        if (request < 1 || request > MAX_FLOORS) {
            printf("Invalid floor request. Please enter a number between 1 and 10.\n");
            continue;
        }

        // Add the requested floor to the list of floors that need to be serviced
        floorCount[request - 1]++;
        
        // Move the elevator to the appropriate floor
        if (request > elevator.floor) {
            printf("Elevator is going up...\n");
            elevator.state = UP;
            while (elevator.floor != request) {
                elevator.floor++;
                printf("Elevator is on floor %d...\n", elevator.floor);
            }
        } else if (request < elevator.floor) {
            printf("Elevator is going down...\n");
            elevator.state = DOWN;
            while (elevator.floor != request) {
                elevator.floor--;
                printf("Elevator is on floor %d...\n", elevator.floor);
            }
        }

        // Service the requested floor
        printf("Opening doors...\n");
        printf("Closing doors...\n");
        floorCount[elevator.floor - 1]--;
    }

    printf("Thank you for using the elevator simulation program!\n");
    return 0;
}