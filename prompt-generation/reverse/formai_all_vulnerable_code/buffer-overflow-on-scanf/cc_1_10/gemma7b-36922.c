//Gemma-7B DATASET v1.0 Category: Elevator Simulation ; Style: Sherlock Holmes
// A Sherlock Holmes-style C Elevator Simulation

#include <stdio.h>
#include <stdlib.h>

// Define the number of floors in the building
#define NUM_FLOORS 10

// Define the elevator capacity
#define CAPACITY 4

// Define the elevator current floor
int currentFloor = 1;

// Define the elevator direction (up or down)
char direction = ' ';

// Define the elevator passengers
int passengers = 0;

// Function to move the elevator up one floor
void moveUp() {
  if (currentFloor < NUM_FLOORS) {
    currentFloor++;
  }
}

// Function to move the elevator down one floor
void moveDown() {
  if (currentFloor > 1) {
    currentFloor--;
  }
}

// Function to add a passenger to the elevator
void addPassenger() {
  if (passengers < CAPACITY) {
    passengers++;
  }
}

// Function to remove a passenger from the elevator
void removePassenger() {
  if (passengers > 0) {
    passengers--;
  }
}

// Main loop
int main() {
  // Loop until the user enters 'q'
  char input;
  while (input != 'q') {
    // Get the user input
    printf("Enter command (up/down/add/remove/q): ");
    scanf("%c", &input);

    // Process the user input
    switch (input) {
      case 'u':
        moveUp();
        break;
      case 'd':
        moveDown();
        break;
      case 'a':
        addPassenger();
        break;
      case 'r':
        removePassenger();
        break;
      case 'q':
        break;
      default:
        printf("Invalid command.\n");
    }

    // Print the current floor and passengers
    printf("Current floor: %d\n", currentFloor);
    printf("Passengers: %d\n", passengers);
  }

  // Print goodbye message
  printf("Thank you for using the Sherlock Holmes Elevator Simulator.\n");

  return 0;
}