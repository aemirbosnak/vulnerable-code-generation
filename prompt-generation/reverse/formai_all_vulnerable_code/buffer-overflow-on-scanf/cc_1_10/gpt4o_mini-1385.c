//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define ELEVATOR_CAPACITY 5

typedef struct {
    int currentFloor;
    int direction; // 1 for up, -1 for down, 0 for idle
    int passengers;
} Elevator;

Elevator elevator = {0, 0, 0};
int floorRequests[MAX_FLOORS] = {0};

// Function prototypes
void requestFloor(int floor);
void moveElevator();
void displayElevatorStatus();
void boardPassengers(int num);
void exitPassengers(int num);

int main() {
    int requestedFloor;

    printf("Elevator Simulation\n");
    printf("===================\n");

    while (true) {
        printf("Enter the floor to request (0-%d), or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &requestedFloor);

        if (requestedFloor == -1) {
            break; // Exit the program
        }

        if (requestedFloor < 0 || requestedFloor >= MAX_FLOORS) {
            printf("Invalid floor request. Please try again.\n");
            continue;
        }

        requestFloor(requestedFloor);
        moveElevator();
        displayElevatorStatus();
    }

    return 0;
}

void requestFloor(int floor) {
    floorRequests[floor]++;
}

void moveElevator() {
    // Handle elevator direction and movement
    while (true) {
        // Determine the next floor to stop at
        int nextFloor = -1;
        for (int i = 0; i < MAX_FLOORS; i++) {
            if (floorRequests[i] > 0) {
                nextFloor = i;
                break;
            }
        }

        if (nextFloor == -1) {
            printf("No pending requests. Elevator is idling.\n");
            elevator.direction = 0;
            return; // No requests, elevator idles
        }

        // Move elevator to the next requested floor
        if (nextFloor > elevator.currentFloor) {
            elevator.direction = 1; // Moving up
            elevator.currentFloor++;
        } else if (nextFloor < elevator.currentFloor) {
            elevator.direction = -1; // Moving down
            elevator.currentFloor--;
        }

        printf("Elevator moving %s to floor %d...\n", elevator.direction == 1 ? "up" : "down", elevator.currentFloor);
        sleep(1); // Simulate time taken to move between floors

        // Handle boarding and exiting passengers
        if (nextFloor == elevator.currentFloor) {
            printf("Arrived at floor %d\n", elevator.currentFloor);
            floorRequests[nextFloor]--;
            int exiting = rand() % (elevator.passengers + 1);
            int entering = rand() % (ELEVATOR_CAPACITY - elevator.passengers + 1);

            exitPassengers(exiting);
            boardPassengers(entering);
        }
    }
}

void displayElevatorStatus() {
    printf("\nElevator Status:\n");
    printf("Current Floor: %d\n", elevator.currentFloor);
    printf("Direction: %s\n", elevator.direction == 1 ? "Up" : (elevator.direction == -1 ? "Down" : "Idle"));
    printf("Passengers: %d\n", elevator.passengers);
    printf("\n");
}

void boardPassengers(int num) {
    if (elevator.passengers + num <= ELEVATOR_CAPACITY) {
        elevator.passengers += num;
        printf("%d passengers boarded the elevator.\n", num);
    } else {
        printf("Cannot board %d passengers. Elevator full.\n", num);
    }
}

void exitPassengers(int num) {
    if (num <= elevator.passengers) {
        elevator.passengers -= num;
        printf("%d passengers exited the elevator.\n", num);
    } else {
        printf("Cannot exit %d passengers. Only %d in the elevator.\n", num, elevator.passengers);
    }
}