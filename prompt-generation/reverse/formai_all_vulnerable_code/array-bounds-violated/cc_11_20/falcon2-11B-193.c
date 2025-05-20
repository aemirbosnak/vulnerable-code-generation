//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSENGERS 5
#define MAX_FLOORS 10
#define BUILDING_HEIGHT 20

typedef struct {
    int floor;
    int passengerCount;
    int elevatorPosition;
} elevator_t;

int main() {
    elevator_t elevator;
    elevator.floor = 0;
    elevator.passengerCount = 0;
    elevator.elevatorPosition = BUILDING_HEIGHT / 2; // Starting position of the elevator

    int floors[MAX_FLOORS] = {0};
    int passengers[MAX_PASSENGERS] = {0};
    int numPassengers = 0;
    int numFloors = 0;

    char command;
    while ((command = getchar())!= 'q') {
        if (isdigit(command)) { // Check if the command is a digit
            elevator.floor = command - '0';
            floors[elevator.floor] = 1; // Mark the floor as visited
        } else if (command == 'd') { // Move down
            if (elevator.floor > 0) {
                elevator.floor--;
            } else {
                printf("Elevator cannot move down any further.\n");
            }
        } else if (command == 'u') { // Move up
            if (elevator.floor < BUILDING_HEIGHT - 1) {
                elevator.floor++;
            } else {
                printf("Elevator cannot move up any further.\n");
            }
        } else if (command == 'o') { // Open doors
            elevator.passengerCount++; // Increment the passenger count
        } else if (command == 'c') { // Close doors
            elevator.passengerCount--; // Decrement the passenger count
        } else if (command =='s') { // Stop
            elevator.elevatorPosition = BUILDING_HEIGHT / 2; // Reset the elevator position
        } else {
            printf("Invalid command.\n");
        }

        if (elevator.passengerCount > 0) {
            elevator.floor--; // Move the elevator to the floor with the highest passenger count
            while (floors[elevator.floor] == 0) { // Move the elevator down until it reaches an unvisited floor
                elevator.floor--;
            }
        }

        numPassengers += elevator.passengerCount; // Increment the number of passengers
        numFloors += elevator.floor; // Increment the number of floors visited

        printf("Passengers: %d\nFloors visited: %d\nElevator position: %d\n", numPassengers, numFloors, elevator.elevatorPosition);
    }

    return 0;
}