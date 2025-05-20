//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int current_floor = 0;
int numberOfFloors;
int numberOfPassengers;

// Struct for elevator object
struct elevator {
    int capacity;
    int current_passengers;
    bool moving_direction;
} elevator;

// Struct for building object
struct building {
    struct elevator elevator;
} building;

// Function to move the elevator up
void moveUp() {
    if(current_floor == numberOfFloors) {
        printf("You are already at the highest floor.\n");
    }
    else {
        current_floor++;
        printf("You have arrived at floor %d.\n", current_floor);
    }
}

// Function to move the elevator down
void moveDown() {
    if(current_floor == 0) {
        printf("You are already at the ground floor.\n");
    }
    else {
        current_floor--;
        printf("You have arrived at floor %d.\n", current_floor);
    }
}

// Function to check if the elevator is full
bool isElevatorFull() {
    return building.elevator.capacity == building.elevator.current_passengers;
}

// Function to add passengers to the elevator
void addPassengers(int passengers) {
    if(isElevatorFull()) {
        printf("The elevator is already at capacity.\n");
    }
    else {
        building.elevator.current_passengers += passengers;
        printf("%d passengers have entered the elevator. There are now %d passengers in the elevator.\n", passengers, building.elevator.current_passengers);
    }
}

// Function to remove passengers from the elevator
void removePassengers(int passengers) {
    if(building.elevator.current_passengers == 0) {
        printf("There are no passengers in the elevator to remove.\n");
    }
    else {
        building.elevator.current_passengers -= passengers;
        printf("%d passengers have left the elevator. There are now %d passengers in the elevator.\n", passengers, building.elevator.current_passengers);
    }
}

// Main function
int main() {
    printf("Welcome to the elevator simulation!\n\n");

    // Prompt user for number of floors
    printf("How many floors are in the building?\n");
    scanf("%d", &numberOfFloors);

    // Prompt user for elevator capacity
    printf("What is the capacity of the elevator?\n");
    scanf("%d", &building.elevator.capacity);

    // Prompt user for number of passengers
    printf("How many passengers are there?\n");
    scanf("%d", &numberOfPassengers);

    // Add passengers to the elevator
    addPassengers(numberOfPassengers);

    // Loop until all passengers have reached their desired floor
    while(building.elevator.current_passengers != 0) {
        int desiredFloor;

        // Prompt user for desired floor
        printf("What floor would you like to go to?\n");
        scanf("%d", &desiredFloor);

        // Check if desired floor is within range
        if(desiredFloor < 0 || desiredFloor > numberOfFloors) {
            printf("Invalid floor. Please select a floor between 0 and %d.\n", numberOfFloors);
        }
        else {
            // Move elevator to desired floor
            while(current_floor != desiredFloor) {
                if(current_floor < desiredFloor) {
                    moveUp();
                }
                else {
                    moveDown();
                }
            }

            // Remove passengers from elevator
            removePassengers(building.elevator.current_passengers);

            // Add passengers to elevator
            printf("How many passengers are there?\n");
            scanf("%d", &numberOfPassengers);
            addPassengers(numberOfPassengers);
        }
    }

    printf("All passengers have reached their desired floor. Thank you for using the elevator simulation!\n");

    return 0;
}